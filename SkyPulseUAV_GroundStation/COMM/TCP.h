#ifndef TCP_H
#define TCP_H

#include <QThread>
#include <QObject>
#include <QTcpSocket>
#include <QVector>
#include <QThreadPool>
#include <QtConcurrent/QtConcurrent>
#include "MediatorInterface.h"

#define WRITE 0x01
#define READ  0x00

class TCP : public QObject {
    Q_OBJECT

public:
    explicit TCP(QObject *parent = nullptr, MediatorInterface* mediator = nullptr);
    ~TCP();
    
    void startTCPServer(const QString &host_ip, quint16 port);
    void stopTCPServer();

private:
    QTcpSocket *TCPSocket;
    QThread *TCPThread;
    MediatorInterface* mediator;

    QString dataCheckOut(const QByteArray &data);
    void dataDecoder(const QByteArray &data_to_decode);

public slots:
    void sendMessage(const QString &message);
    void sendMessageQByte(const QByteArray &message);
    void readMessage();
    void PWM_Controler(const QVector<uint8_t> &pwm_value);
    void Flight_Controler(const QVector<uint8_t> &control_data);
    void Flight_Config_Setting(const QVector<uint8_t> &config_data);
    void commendToFCS(const uint8_t &command_code);

private slots:
    void tcpInitial();

    void onConnected();
    void onDisconnected();
    void onErrorOccurred();

signals:
    void sig_startSuccessful();  // 判断是否连接成功的信号
    void sig_stopSuccessful();   // 判断是否成功断开的信号
    void sig_connectionError();
    void sig_UIupdate(QStringList datalist);
};

#endif // TCP_H
