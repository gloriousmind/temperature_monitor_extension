#include "mywidget.h"
#include "ui_mywidget.h"

QRegularExpression MyWidget::address_pattern;

MyWidget::MyWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MyWidget)
{
    ui->setupUi(this);
    QMessageBox::information(this, "环回测试信息", "环回测试默认开启");
    ui->automode_button->setText("自动发送");
    ui->singleshot_button->setText("单次发送");
    udp_socket = new QUdpSocket(this);
    udp_socket->bind(QHostAddress::Any, udp_port_number, QAbstractSocket::ShareAddress | QAbstractSocket::ReuseAddressHint);
    udp_socket_loopback = new QUdpSocket(this);
    udp_socket_loopback->bind(QHostAddress::LocalHost, udp_server_loopback_port);
    tcp_socket = new QTcpSocket(this);
    tcp_socket_loopback = new QTcpSocket(this);
    timer_sending_data = new QTimer(this);
    reply_timeout = new QTimer(this);
    connect(ui->automode_button, &QPushButton::clicked, this, &MyWidget::automode_start);
    connect(ui->singleshot_button, &QPushButton::clicked, this, &MyWidget::singleshot_send_value);
    connect(timer_sending_data, &QTimer::timeout, this, &MyWidget::automode_send_value);
    connect(udp_socket, &QUdpSocket::readyRead, this, &MyWidget::read_server_message);
    connect(udp_socket_loopback, &QUdpSocket::readyRead, this, &MyWidget::read_server_message_loopback);
    connect(ui->comboBox, &QComboBox::currentTextChanged, this, &MyWidget::change_transport_protocol);
    connect(ui->loopback_button, &QPushButton::clicked, this, &MyWidget::loopback_button_statechanged);

}

void MyWidget::automode_start()
{
    if (ui->automode_button->text() == "自动发送")
    {
        ui->automode_button->setText("停止发送");
        timer_sending_data->start(1000);
    }
    else
    {
        ui->automode_button->setText("自动发送");
        timer_sending_data->stop();
    }
}

void MyWidget::automode_send_value()
{
    double temperature_value = -50 + QRandomGenerator::global()->generateDouble() * 500;
    if (sending_mode_udp)
    {
        if (loopback_activated)
        {
            udp_socket_loopback->writeDatagram(QByteArray::number(temperature_value, 'f', 1), QHostAddress::LocalHost, udp_client_loopback_port);
        }
        else
            udp_socket->writeDatagram(QByteArray::number(temperature_value, 'f', 1), QHostAddress::Broadcast, udp_port_number);
    }
    else
    {
        QByteArray tcp_message;
        tcp_message = QByteArray::number(temperature_value, 'f', 1) + '\n';
        if (loopback_activated)
            tcp_socket_loopback->write(tcp_message);
        else
            tcp_socket->write(tcp_message);
    }
}

void MyWidget::singleshot_send_value()
{
    timer_sending_data->stop();
    ui->automode_button->setText("自动发送");
    double temperature_value = -50 + QRandomGenerator::global()->generateDouble() * 500;
    if (sending_mode_udp)
    {
        if (loopback_activated)
        {
            udp_socket_loopback->writeDatagram(QByteArray::number(temperature_value, 'f', 1), QHostAddress::LocalHost, udp_client_loopback_port);
        }
        else
            udp_socket->writeDatagram(QByteArray::number(temperature_value, 'f', 1), QHostAddress::Broadcast, udp_port_number);
    }
    else
    {
        QByteArray tcp_message;
        tcp_message = QByteArray::number(temperature_value, 'f', 1) + '\n';
        if (loopback_activated)
            tcp_socket_loopback->write(tcp_message);
        else
            tcp_socket->write(tcp_message);
    }
}

void MyWidget::change_transport_protocol(const QString &protocol_text)
{
    timer_sending_data->stop();
    if (protocol_text == "Udp")
    {
        sending_mode_udp = true;
        if (loopback_activated)
            tcp_socket_loopback->close();
        else
            tcp_socket->close();
    }
    else
    {
        QByteArray sending_message("服务器地址");
        if (loopback_activated)
        {
            udp_socket_loopback->writeDatagram(sending_message, QHostAddress::LocalHost, udp_client_loopback_port);
        }
        else
            udp_socket->writeDatagram(sending_message, QHostAddress::Broadcast, udp_port_number);
        sending_mode_udp = false;
    }
}

void MyWidget::read_server_message()
{
    QByteArray server_message;
    while (udp_socket->hasPendingDatagrams())
    {
        qint64 size = udp_socket->pendingDatagramSize();
        server_message.resize(size);
        udp_socket->readDatagram(server_message.data(), size);
        address_pattern.setPattern(".*\\..*\\..*\\..*");
        if (address_pattern.match(QString::fromUtf8(server_message.data())).hasMatch())
        {
            server_address.setAddress(server_message.data());
            tcp_socket->abort();
            tcp_socket->connectToHost(server_address, tcp_port_number);
            ui->automode_button->setEnabled(false);
            ui->singleshot_button->setEnabled(false);
            connect(tcp_socket, &QTcpSocket::connected, this, &MyWidget::wait_for_connection, Qt::UniqueConnection);
        }
    }
}

void MyWidget::read_server_message_loopback()
{
    QByteArray server_message;
    while (udp_socket_loopback->hasPendingDatagrams())
    {
        qint64 size = udp_socket_loopback->pendingDatagramSize();
        server_message.resize(size);
        udp_socket_loopback->readDatagram(server_message.data(), size);
        address_pattern.setPattern(".*\\..*\\..*\\..*");
        if (address_pattern.match(QString::fromUtf8(server_message.data())).hasMatch())
        {
            server_address.setAddress(server_message.data());
            tcp_socket_loopback->abort();
            tcp_socket_loopback->connectToHost(server_address, tcp_port_number_loopback);
            ui->automode_button->setEnabled(false);
            ui->singleshot_button->setEnabled(false);
            connect(tcp_socket_loopback, &QTcpSocket::connected, this, &MyWidget::wait_for_connection);//Qt::UniqueConnection);
        }
    }
}

void MyWidget::wait_for_connection()
{
    QMessageBox::information(this, "信息", "tcp连接成功");
    ui->automode_button->setEnabled(true);
    ui->singleshot_button->setEnabled(true);
}

void MyWidget::loopback_button_statechanged()
{
    ui->automode_button->setEnabled(false);
    ui->singleshot_button->setEnabled(false);
    ui->comboBox->setEnabled(false);
    if(ui->loopback_button->text() == "关闭环回测试")
    {
        QNetworkRequest request(QUrl("https://www.qt.io/"));
        manager = new QNetworkAccessManager(this);
        connect(manager, &QNetworkAccessManager::finished, this, &MyWidget::network_connectivity_check);
        reply = manager->head(request);
        reply_timeout->setSingleShot(true);
        connect(reply_timeout, &QTimer::timeout, this, &MyWidget::http_connection_timeout, Qt::UniqueConnection);
        reply_timeout->start(5000);
    }
    else
    {
        ui->loopback_button->setText("关闭环回测试");
        loopback_activated = true;
        udp_socket_loopback->writeDatagram(QByteArray("打开环回测试"), QHostAddress::LocalHost, udp_client_loopback_port);
        ui->automode_button->setEnabled(true);
        ui->singleshot_button->setEnabled(true);
        ui->comboBox->setEnabled(true);
    }
}

void MyWidget::network_connectivity_check(QNetworkReply *reply)
{
    reply_timeout->stop();
    if (reply->error() == QNetworkReply::NoError)
    {
        QMessageBox::information(this, "网络信息", "网络已连接，可以关闭环回测试模式!");
        ui->loopback_button->setText("打开环回测试");
        loopback_activated = false;
        udp_socket_loopback->writeDatagram(QByteArray("关闭环回测试"), QHostAddress::LocalHost, udp_client_loopback_port);
        QByteArray sending_message("服务器地址");
        if (loopback_activated)
            udp_socket_loopback->writeDatagram(sending_message, QHostAddress::LocalHost, udp_client_loopback_port);
        else
            udp_socket->writeDatagram(sending_message, QHostAddress::Broadcast, udp_port_number);
        sending_mode_udp = false;
    }
    else
        QMessageBox::information(this, "网络信息", "网络未连接，关闭环回测试失败!");
    ui->automode_button->setEnabled(true);
    ui->singleshot_button->setEnabled(true);
    ui->comboBox->setEnabled(true);
}

void MyWidget::http_connection_timeout()
{
    if (reply && reply->isRunning())
        reply->abort();
    QMessageBox::information(this, "网络信息", "测试网络连同请求超时");
    ui->automode_button->setEnabled(true);
    ui->singleshot_button->setEnabled(true);
    ui->comboBox->setEnabled(true);
}

MyWidget::~MyWidget()
{
    delete ui;
}
