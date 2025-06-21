#include "mywidget.h"
#include "ui_mywidget.h"

QRegularExpression MyWidget::address_pattern;

MyWidget::MyWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MyWidget)
{
    ui->setupUi(this);
    effect = new QSoundEffect(this);
    effect->setSource(QUrl::fromLocalFile("/home/jie/Qt_Project/temperature_monitor/temperature_server/alarm-987.wav"));
    effect->setLoopCount(1);
    effect->setVolume(0.25);
    udp_socket = new QUdpSocket(this);
    udp_socket->bind(QHostAddress::Any, udp_port_number, QAbstractSocket::ShareAddress | QAbstractSocket::ReuseAddressHint);
    udp_socket_loopback = new QUdpSocket(this);
    udp_socket_loopback->bind(QHostAddress::LocalHost, udp_client_loopback_port);
    tcp_socket = new QTcpSocket(this);
    tcp_socket_loopback = new QTcpSocket(this);
    tcp_server = new QTcpServer(this);
    tcp_server_loopback = new QTcpServer(this);
    connect(udp_socket, &QUdpSocket::readyRead, this, &MyWidget::read_udp_message);
    connect(udp_socket_loopback, &QUdpSocket::readyRead, this, &MyWidget::read_udp_message_loopback);
    connect(tcp_server, &QTcpServer::newConnection, this, &MyWidget::get_tcpsocket);
    connect(tcp_server_loopback, &QTcpServer::newConnection, this, &MyWidget::get_tcpsocket_loopback);
}


void MyWidget::read_udp_message()
{
    while (udp_socket->hasPendingDatagrams())
    {
        qint64 size = udp_socket->pendingDatagramSize();
        QByteArray value;
        value.resize(size);
        udp_socket->readDatagram(value.data(), size);
        address_pattern.setPattern(".*\\..*\\..*\\..*");
        if (address_pattern.match(QString::fromUtf8(value.data())).hasMatch())
        {
            continue;
        }
        else if (QString::fromUtf8(value.data()) == "服务器地址")
        {
            QHostAddress temp_address;
            QList<QHostAddress> all_host_Addresses = QNetworkInterface::allAddresses();
            foreach (temp_address, all_host_Addresses)
            {
                if (temp_address.protocol() == QAbstractSocket::IPv4Protocol && temp_address != QHostAddress::LocalHost)
                {
                    local_address = temp_address;
                    break;
                }
            }
            udp_socket->writeDatagram(local_address.toString().toUtf8(), QHostAddress::Broadcast, udp_port_number);
            tcp_server->close();
            tcp_server->listen(local_address, tcp_port_number);
        }
        else
        {
            double temperature_value = value.toDouble();

            if ((temperature_value < -50) || (temperature_value > 150))
            {
                QString error_value = QString::fromUtf8(value) + "℃";
                qDebug() << "error temperature data" << " " << error_value << "℃";
                setStyleSheet("background : green");
                //effect->play();
                QFile logfile("mylog.txt");
                if (!logfile.open(QIODeviceBase::WriteOnly | QIODeviceBase::Append))
                    return;
                QTextStream out(&logfile);
                QDateTime date_time = QDateTime::currentDateTime();
                out << date_time.toString("dd MM yyyy") << " " << value.toDouble() <<'\n';
                out << error_value << '\n';
                logfile.close();
            }
            else
                setStyleSheet("");
            ui->temperature_value->setText(QString::fromUtf8(value));
        }
    }
}

void MyWidget::read_udp_message_loopback()
{
    while (udp_socket_loopback->hasPendingDatagrams())
    {
        qint64 size = udp_socket_loopback->pendingDatagramSize();
        QByteArray value;
        value.resize(size);
        udp_socket_loopback->readDatagram(value.data(), size);
        address_pattern.setPattern(".*\\..*\\..*\\..*");
        QString cur_message = QString::fromUtf8(value.data());
        if (cur_message == "服务器地址")
        {
            local_address = QHostAddress::LocalHost;
            udp_socket_loopback->writeDatagram(local_address.toString().toUtf8(), QHostAddress::LocalHost, udp_server_loopback_port);
            tcp_server_loopback->close();
            tcp_server_loopback->listen(QHostAddress::LocalHost, tcp_port_number_loopback);
        }
        else if (cur_message == "打开环回测试")
        {
            loopback_activated = true;
        }
        else if (cur_message== "关闭环回测试")
        {
            loopback_activated = false;
        }
        else
        {
            double temperature_value = value.toDouble();
            if ((temperature_value < -50) || (temperature_value > 150))
            {
                QString error_value = QString::fromUtf8(value) + "℃";
                qDebug() << "error temperature data" << " " << error_value << "℃";
                setStyleSheet("background : green");
                //effect->play();
                QFile logfile("mylog.txt");
                if (!logfile.open(QIODeviceBase::WriteOnly | QIODeviceBase::Append))
                    return;
                QTextStream out(&logfile);
                QDateTime date_time = QDateTime::currentDateTime();
                out << date_time.toString("dd MM yyyy") << " " << value.toDouble() <<'\n';
                out << error_value << '\n';
                logfile.close();
            }
            else
                setStyleSheet("");
            ui->temperature_value->setText(QString::fromUtf8(value));
        }
    }
}

void MyWidget::get_tcpsocket()
{
    tcp_socket = tcp_server->nextPendingConnection();
    connect(tcp_socket, &QTcpSocket::readyRead, this, &MyWidget::read_tcp_message, Qt::UniqueConnection);
}

void MyWidget::get_tcpsocket_loopback()
{
    tcp_socket_loopback = tcp_server_loopback->nextPendingConnection();
    connect(tcp_socket_loopback, &QTcpSocket::readyRead, this, &MyWidget::read_tcp_message, Qt::UniqueConnection);
}

void MyWidget::read_tcp_message()
{
    QTcpSocket *temp_tcp_socket;
    if (loopback_activated)
        temp_tcp_socket = tcp_socket_loopback;
    else
        temp_tcp_socket = tcp_socket;
    if (temp_tcp_socket->bytesAvailable())
    {
        buffer_information = buffer_information + temp_tcp_socket->readAll();
        qint64 index = buffer_information.indexOf('\n');
        QByteArray value = buffer_information.first(index - 0);
        double temperature_value = value.toDouble();
        buffer_information = buffer_information.sliced(index + 1);
        if ((temperature_value < -50) || (temperature_value > 150))
        {
            QString error_value = QString::fromUtf8(value) + "℃";
            qDebug() << "error temperature data" << " " << error_value << "℃";
            setStyleSheet("background : green");
            //effect->play();
            QFile logfile("mylog.txt");
            if (!logfile.open(QIODeviceBase::WriteOnly | QIODeviceBase::Append))
                return;
            QTextStream out(&logfile);
            QDateTime date_time = QDateTime::currentDateTime();
            out << date_time.toString("dd MM yyyy") << " " << temperature_value <<'\n';
            out << error_value << '\n';
            logfile.close();
        }
        else
            setStyleSheet("");
        ui->temperature_value->setText(QString::fromUtf8(value));
    }
}

MyWidget::~MyWidget()
{
    delete ui;
}
