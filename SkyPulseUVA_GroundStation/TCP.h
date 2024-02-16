#ifndef TCP_H
#define TCP_H

#include <QObject>
#include <QTcpSocket>

class TCP : public QObject {
    Q_OBJECT

public:
    explicit TCP(QObject *parent = nullptr);
    void connectToServer(const QString &host, quint16 port);
    void sendMessage(const QString &message);
    void disconnectFromServer();

private:
    QTcpSocket *TCPSocket;

private slots:
    void readMessage();
    void onConnected();
    void onErrorOccurred();
    void onDisconnected();

signals:
    void sig_receivedMessage(const QString &message);
    void sig_connectionSuccessful();  // 判断是否连接成功的信号
    void sig_disconnectionSuccessful();  // 判断是否成功断开的信号
    void sig_connectionError();

};

#endif // TCP_H
