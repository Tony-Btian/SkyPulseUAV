#ifndef TCP_H
#define TCP_H

#include <QThread>
#include <QObject>
#include <QTcpSocket>
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

public slots:
    void sendMessage(const QString &message);
    void sendMessageQByte(const QByteArray &message);
    void readMessage();
    void PWM_Controler(const int &code, const int &pin, const int &value);
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
};

#endif // TCP_H
