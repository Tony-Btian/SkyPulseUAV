#include "TCP.h"
#include <QThread>

TCP::TCP(QObject *parent) : QObject(parent), TCPSocket(new QTcpSocket(this)) {
    tcpInitial();
}

/*TCP服务初始化*/
void TCP::tcpInitial()
{
    connect(TCPSocket, &QTcpSocket::connected, this, &TCP::onConnected);
    connect(TCPSocket, &QTcpSocket::disconnected, this, &TCP::onDisconnected);
    connect(TCPSocket, &QTcpSocket::readyRead, this, &TCP::readMessage);
    connect(TCPSocket, &QTcpSocket::errorOccurred, this, &TCP::onErrorOccurred);
}

/*TCP服务连接函数*/
void TCP::connectToServer(const QString &host, quint16 port)
{
    TCPSocket->connectToHost(host, port);
}

/*TCP连接成功信号*/
void TCP::onConnected()
{
    emit sig_connectionSuccessful(); // 当连接成功时发出信号
}

/*TCP服务断开连接函数*/
void TCP::disconnectToServer()
{
    if(TCPSocket->state() == QTcpSocket::ConnectedState){  // 判断连接状态之后再断开连接
        TCPSocket->disconnectFromHost();
    }
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
    qDebug() << "TCP Row Message: " << data;
    // qDebug() << "TCP Thread ID: " << QThread::currentThreadId();
    emit sig_receivedMessage(QString::fromUtf8(data));
}

/*TCP数据转译*/
void TCP::dataTrasnlate(const QByteArray &data)
{

}

/*TCP数据有效性检查*/
QString dataCheckOut(const QByteArray &data)
{

}
