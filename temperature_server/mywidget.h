#ifndef MYWIDGET_H
#define MYWIDGET_H

#include <QWidget>
#include <QUdpSocket>
#include <QTcpSocket>
#include <QTcpServer>
#include <QNetworkInterface>
#include <QFile>
#include <QDateTime>
#include <QRegularExpression>
#include <QSoundEffect>

QT_BEGIN_NAMESPACE
namespace Ui {
class MyWidget;
}
QT_END_NAMESPACE

class MyWidget : public QWidget
{
    Q_OBJECT

public:
    MyWidget(QWidget *parent = nullptr);
    ~MyWidget();

private:
    Ui::MyWidget *ui;
    QUdpSocket *udp_socket;
    QUdpSocket *udp_socket_loopback;
    QTcpSocket *tcp_socket;
    QTcpServer *tcp_server;
    QTcpSocket *tcp_socket_loopback;
    QTcpServer *tcp_server_loopback;
    int udp_port_number = 2000;
    int tcp_port_number = 2200;
    int udp_client_loopback_port = 3000;
    int udp_server_loopback_port = 3001;
    int tcp_port_number_loopback = 3002;
    QHostAddress local_address;
    bool loopback_activated = true;
    QByteArray buffer_information;
    QSoundEffect *effect;
    static QRegularExpression address_pattern;

private slots:
    void read_udp_message();
    void read_udp_message_loopback();
    void read_tcp_message();
    void get_tcpsocket();
    void get_tcpsocket_loopback();
};
#endif // MYWIDGET_H
