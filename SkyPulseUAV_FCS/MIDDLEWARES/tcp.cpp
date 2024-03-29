#include "tcp.h"
#include <QHostAddress>
#include <QThread>
#include <QDataStream>

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
    qDebug() << "The TCP Thread ID is: " << QThread::currentThreadId();
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
    QTcpSocket *clients = qobject_cast<QTcpSocket*>(sender());
    if(!clients) return;

    QByteArray data = clients->readAll();
//    qDebug() << "Received data from" << clients->peerAddress().toString() << ": " << data;
    dataTranslator(data);

}

void TCP::dataTranslator(const QByteArray &data)
{
    QDataStream stream(data);
    stream.setByteOrder(QDataStream::LittleEndian);
    int firstInt, secondInt;

    // Make sure there is enough data in the stream to read two integers.
    if (stream.atEnd()) {
        qDebug() << "Error: Not enough data to read the first integer.";
        return;
    }
    stream >> firstInt; // Read the first integer from the data stream

    if (stream.atEnd()) {
        qDebug() << "Error: Not enough data to read the second integer.";
        return;
    }
    stream >> secondInt; // Read the second integer from the stream

    qDebug() << "First integer: " << firstInt;
    qDebug() << "Second integer: " << secondInt;
    emit sig_sendPWMSignal(firstInt, secondInt);
}

