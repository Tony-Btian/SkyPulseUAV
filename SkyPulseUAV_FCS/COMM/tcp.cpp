#include "tcp.h"
#include <QHostAddress>

TCP::TCP(QObject *parent) : QTcpServer(parent)
{

}

void TCP::startServer(quint16 port)
{
    if(this->listen(QHostAddress::Any, port)){
        qDebug() << "Server started on port" << port;
    }
    else
    {
        qDebug() << "Server failed to start: " << this->errorString();
    }
}

void TCP::incomingConnection(qintptr socketDescriptor)
{
    QTcpSocket *client = new QTcpSocket(this);
    client->setSocketDescriptor(socketDescriptor);

    connect(client, &QTcpSocket::disconnected, this, &TCP::onClientDisconnected);
    connect(client, &QTcpSocket::readyRead, this, &TCP::onReadyRead);

    clients.append(client);
    qDebug() << "Client connected: " << client->peerAddress().toString();
}

void TCP::broadcastMessage(const QByteArray &message)
{
    for(QTcpSocket *client : qAsConst(clients)){
        if(client->state() == QTcpSocket::ConnectedState){
            client->write(message);
        }
    }
}

void TCP::onClientDisconnected()
{
    QTcpSocket *client = qobject_cast<QTcpSocket*>(sender());
    if(client){
        clients.removeAll(client);
        client->deleteLater();
        qDebug() << "Client disconnected";
    }
}

void TCP::onReadyRead()
{
    // Any function here
}
