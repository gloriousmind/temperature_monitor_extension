#ifndef MYWIDGET_H
#define MYWIDGET_H

#include <QWidget>
#include <QTimer>
#include <QRandomGenerator>
#include <QUdpSocket>
#include <QTcpSocket>
#include <QMessageBox>
#include <QNetworkRequest>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QSerialPort>
#include <QBuffer>

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
    //网络通信
    QTimer *timer_sending_data;
    QTimer *reply_timeout;
    bool sending_mode_udp = true;
    QUdpSocket *udp_socket;
    QUdpSocket *udp_socket_loopback;
    QTcpSocket *tcp_socket;
    QTcpSocket *tcp_socket_loopback;
    int udp_port_number = 2000;
    int tcp_port_number = 2200;
    int udp_client_loopback_port = 3000;
    int udp_server_loopback_port = 3001;
    int tcp_port_number_loopback = 3002;
    QHostAddress local_address;
    QHostAddress server_address;
    QNetworkAccessManager *manager;
    QNetworkReply *reply;
    static QRegularExpression address_pattern;
    bool loopback_activated = true;
    //串口通信
    QSerialPort *serial_port;
    QStringList existing_serial_port;
    QByteArray received_serialPort_data;

private slots:
    //网络通信
    void automode_start();
    void automode_send_value();
    void singleshot_send_value();
    void read_server_message();
    void read_server_message_loopback();
    void wait_for_connection();
    void change_transport_protocol(const QString &protocol_text);
    void loopback_button_statechanged();
    void network_connectivity_check(QNetworkReply *reply);
    void http_connection_timeout();
    //串口通信
    void update_serial_port();
    void store_serialPort_data();
    double extract_serialPort_data();
    void SerialPort_box_textchanged(QString text);
    void BaudRate_box_textchange(QString text);
    void DataBits_box_textchange(QString text);
    void FlowControl_box_textchange(QString text);
    void Parity_box_textchange(QString text);
    void StopBits_box_textchange(QString text);
};
#endif // MYWIDGET_H
