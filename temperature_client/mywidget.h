#ifndef MYWIDGET_H
#define MYWIDGET_H

#include <QWidget>
#include <QTimer>
#include <QRandomGenerator>
#include <QUdpSocket>
#include <QTcpSocket>
#include <QMessageBox>

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
    QTimer *timer_sending_data;
    QTimer *timer_tcp_connection;
    bool sending_mode_udp = true;
    QUdpSocket *udp_socket;
    QTcpSocket *tcp_socket;
    int udp_port_number = 2000;
    int tcp_port_number = 2200;
    QHostAddress local_address;
    QHostAddress server_address;
    static QRegularExpression address_pattern;


private slots:
    void automode_start();
    void automode_send_value();
    void singleshot_send_value();
    void read_server_message();
    void change_transport_protocol(const QString &protocol_text);
    void display_connection_state();
};
#endif // MYWIDGET_H
