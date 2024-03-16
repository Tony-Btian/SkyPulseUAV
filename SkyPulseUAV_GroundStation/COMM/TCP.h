#ifndef TCP_H
#define TCP_H

#include <QObject>
#include <QTcpSocket>

class TCP : public QObject {
    Q_OBJECT

public:
    explicit TCP(QObject *parent = nullptr);
    void connectToServer(const QString &host, quint16 port);
    void disconnectToServer();
    void dataTrasnlate(const QByteArray &data);

private:
    QTcpSocket *TCPSocket;
    void tcpInitial();
    QString dataCheckOut(const QByteArray &data);

public slots:
    void sendMessage(const QString &message);
    void sendMessageQByte(const QByteArray &message);
    void readMessage();
    void PWM_Controler(const int &code, const int &value);

private slots:
    void onConnected();
    void onDisconnected();
    void onErrorOccurred();

signals:
    void sig_receivedMessage(const QString &message);
    void sig_connectionSuccessful();  // 判断是否连接成功的信号
    void sig_disconnectionSuccessful();  // 判断是否成功断开的信号
    void sig_connectionError();
};

#endif // TCP_H
