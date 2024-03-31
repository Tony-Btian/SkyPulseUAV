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

    void connectToServer(const QString &host, quint16 port);
    void disconnectToServer();

private:
    QTcpSocket *TCPSocket;
    QThread *TCPThread;
    MediatorInterface* mediator;

    QString dataCheckOut(const QByteArray &data);

public slots:
    void sendMessage(const QString &message);
    void sendMessageQByte(const QByteArray &message);
    void readMessage();
    void PWM_Controler(const int &code, const int &value);
    void commendToFCS(const uint8_t &command_code);

private slots:
    void tcpInitial();

    void onConnected();
    void onDisconnected();
    void onErrorOccurred();

signals:
    void sig_connectionSuccessful();  // 判断是否连接成功的信号
    void sig_disconnectionSuccessful();  // 判断是否成功断开的信号
    void sig_connectionError();
};

#endif // TCP_H
