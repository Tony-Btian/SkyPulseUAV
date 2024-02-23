#include "TCP.h"
#include <QThread>

TCP::TCP(QObject *parent) : QObject(parent), TCPSocket(new QTcpSocket(this)) {
    connect(TCPSocket, &QTcpSocket::readyRead, this, &TCP::readMessage);
    connect(TCPSocket, &QTcpSocket::connected, this, &TCP::onConnected);
    connect(TCPSocket, &QTcpSocket::errorOccurred, this, &TCP::onErrorOccurred);
    connect(TCPSocket, &QTcpSocket::disconnected, this, &TCP::onDisconnected);
}

/*TCP服务连接函数*/
void TCP::connectToServer(const QString &host, quint16 port)
{
    TCPSocket->connectToHost(host, port);
}

/*TCP服务断开连接函数*/
void TCP::disconnectFromServer()
{
    if(TCPSocket->state() == QTcpSocket::ConnectedState){  // 判断连接状态之后再断开连接
        TCPSocket->disconnectFromHost();
    }
}

/*TCP数据发送函数*/
void TCP::sendMessage(const QString &message)
{
    if(TCPSocket->state() == QTcpSocket::ConnectedState)
    {
        TCPSocket->write(message.toUtf8());
    }
}

/*TCP数据接收函数*/
void TCP::readMessage()
{
    QByteArray data = TCPSocket->readAll();
    qDebug() << "TCP Thread ID: " << QThread::currentThreadId();
    emit sig_receivedMessage(QString::fromUtf8(data));
}

/*TCP连接成功信号*/
void TCP::onConnected()
{
    emit sig_connectionSuccessful(); // 当连接成功时发出信号
}

/*TCP断开成功信号*/
void TCP::onDisconnected()
{
    emit sig_disconnectionSuccessful(); // 当断开连接成功时发出信号
}

/*TCP连接错误信号*/
void TCP::onErrorOccurred()
{
    emit sig_connectionError(); // 当连接错误时发出信号
}
