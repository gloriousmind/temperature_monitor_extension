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
    udp_socket->bind(udp_port_number, QAbstractSocket::ShareAddress | QAbstractSocket::ReuseAddressHint);
    connect(udp_socket, &QUdpSocket::readyRead, this, &MyWidget::read_udp_message);
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
        if (address_pattern.match(QString(value.data())).hasMatch())
            break;
        if (QString::fromUtf8(value.data()) == "服务器地址")
        {
            QHostAddress local_address;
            QHostAddress temp_address;
            QList<QHostAddress> all_host_Addresses = QNetworkInterface::allAddresses();
            foreach (temp_address, all_host_Addresses)
            {
                if (temp_address.protocol() == QAbstractSocket::IPv4Protocol && temp_address != QHostAddress::LocalHost)
                {
                    local_address = temp_address;
                    qDebug() << local_address;
                    break;
                }
            }
            udp_socket->writeDatagram(local_address.toString().toUtf8(), QHostAddress::Broadcast, udp_port_number);
            if (!tcp_server)
            {
                tcp_server = new QTcpServer(this);
                connect(tcp_server, &QTcpServer::newConnection, this, &MyWidget::get_tcpsocket);
            }
            tcp_server->listen(QHostAddress::Any, tcp_port_number);
        }
        else
        {
            double temperature_value = value.toDouble();

            if ((temperature_value < -50) || (temperature_value > 150))
            {
                QString error_value = QString::fromUtf8(value) + "℃";
                qDebug() << "error temperature data" << " " << error_value << "℃";
                setStyleSheet("background : green");
                effect->play();
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
    connect(tcp_socket, &QTcpSocket::readyRead, this, &MyWidget::read_tcp_message);
}

void MyWidget::read_tcp_message()
{
    if (tcp_socket->bytesAvailable())
    {
        buffer_information = buffer_information + tcp_socket->readAll();
        qint64 index = buffer_information.indexOf('\n');
        QByteArray value = buffer_information.first(index - 0);
        double temperature_value = value.toDouble();
        buffer_information = buffer_information.sliced(index + 1);
        if ((temperature_value < -50) || (temperature_value > 150))
        {
            QString error_value = QString::fromUtf8(value) + "℃";
            qDebug() << "error temperature data" << " " << error_value << "℃";
            setStyleSheet("background : green");
            effect->play();
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
