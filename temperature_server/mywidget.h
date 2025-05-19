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
    QTcpSocket *tcp_socket;
    QTcpServer *tcp_server;
    int udp_port_number = 2000;
    int tcp_port_number = 2200;
    QByteArray buffer_information;
    QSoundEffect *effect;
    static QRegularExpression address_pattern;

private slots:
    void read_udp_message();
    void read_tcp_message();
    void get_tcpsocket();
};
#endif // MYWIDGET_H
