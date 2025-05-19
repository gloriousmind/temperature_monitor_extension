#include "mywidget.h"
#include "ui_mywidget.h"

QRegularExpression MyWidget::address_pattern;

MyWidget::MyWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MyWidget)
{
    ui->setupUi(this);
    ui->automode_button->setText("自动发送");
    ui->singleshot_button->setText("单次发送");
    udp_socket = new QUdpSocket(this);
    udp_socket->bind(udp_port_number, QAbstractSocket::ShareAddress | QAbstractSocket::ReuseAddressHint);
    timer_sending_data = new QTimer(this);
    connect(ui->automode_button, &QPushButton::clicked, this, &MyWidget::automode_start);
    connect(ui->singleshot_button, &QPushButton::clicked, this, &MyWidget::singleshot_send_value);
    connect(timer_sending_data, &QTimer::timeout, this, &MyWidget::automode_send_value);
    connect(udp_socket, &QUdpSocket::readyRead, this, &MyWidget::read_server_message);
    connect(ui->comboBox, &QComboBox::currentTextChanged, this, &MyWidget::change_transport_protocol);
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
        udp_socket->writeDatagram(QByteArray::number(temperature_value, 'f', 1), QHostAddress::Broadcast, udp_port_number);
    else
    {
        QByteArray tcp_message;
        tcp_message = QByteArray::number(temperature_value, 'f', 1) + '\n';
        tcp_socket->write(tcp_message);
    }
}

void MyWidget::singleshot_send_value()
{
    timer_sending_data->stop();
    ui->automode_button->setText("自动发送");
    double temperature_value = -50 + QRandomGenerator::global()->generateDouble() * 500;
    if (sending_mode_udp)
        udp_socket->writeDatagram(QByteArray::number(temperature_value, 'f', 1), QHostAddress::Broadcast, udp_port_number);
    else
    {
        QByteArray tcp_message;
        tcp_message = QByteArray::number(temperature_value, 'f', 1) + '\n';
        tcp_socket->write(tcp_message);
    }
}

void MyWidget::change_transport_protocol(const QString &protocol_text)
{
    timer_sending_data->stop();
    if (tcp_socket)
    {
        tcp_socket->abort();
        delete tcp_socket;
        tcp_socket = nullptr;
    }

    if (protocol_text == "Udp")
    {
        sending_mode_udp = true;
    }
    else
    {
        tcp_socket = new QTcpSocket(this);
        QByteArray sending_message("服务器地址");
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
            tcp_socket->connectToHost(server_address, tcp_port_number);
            if (!timer_tcp_connection)
            {
                timer_tcp_connection = new QTimer(this);
                timer_tcp_connection->start(1000);
                connect(timer_tcp_connection, &QTimer::timeout, this, &MyWidget::display_connection_state);
            }
        }
    }
}

void MyWidget::display_connection_state()
{
    if (tcp_socket->state() != QAbstractSocket::ConnectedState)
    {
        qDebug() << "client is trying to connect";
    }
    else
    {
        QMessageBox::information(this, "信息", "连接成功");
        timer_tcp_connection->stop();
    }
}

MyWidget::~MyWidget()
{
    delete ui;
}
