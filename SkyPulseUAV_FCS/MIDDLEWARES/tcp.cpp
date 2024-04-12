#include "tcp.h"
#include "decodetask.h"
#include <QHostAddress>
#include <QThreadPool>
#include <QDataStream>

TCP::TCP(QObject *parent) : QTcpServer(parent)
{
    TCPThread = new QThread(this); // Create a new thread for the TCP server operations
    connect(TCPThread, &QThread::started, this, &TCP::startServer); // Connect thread start to server start
    connect(TCPThread, &QThread::finished, TCPThread, &QObject::deleteLater); // Ensure thread is deleted after finishing
    this->moveToThread(TCPThread); // Move TCP server object to the newly created thread
    TCPThread->start(); // Start the thread, triggering the server to start
}

TCP::~TCP()
{
    if (TCPThread->isRunning()){ // Check if the thread is still running
        TCPThread->wait(); // Wait for the ongoing operations to finish
        TCPThread->quit(); // Request the thread to quit
    }
}

void TCP::startServer()
{
    if(this->listen(QHostAddress::Any, PORT)){ // Attempt to start listening for connections
//        qDebug() << "TCP Server started on port" << PORT << "!";
    }
    else
    {
        qDebug() << "TCP Server failed to start: " << this->errorString(); // Log failure to start server
    }
}

void TCP::incomingConnection(qintptr socketDescriptor)
{
    QTcpSocket *client = new QTcpSocket(this); // Create a new socket for the incoming connection
    client->setSocketDescriptor(socketDescriptor); // Set the socket descriptor from the incoming connection

    connect(client, &QTcpSocket::disconnected, this, &TCP::onClientDisconnected); // Connect client disconnect signal
    connect(client, &QTcpSocket::readyRead, this, &TCP::onReadyRead); // Connect client readyRead signal to handle incoming data

    clients.append(client); // Add the new client to the list of clients
    qDebug() << "Client connected:" << client->peerAddress().toString(); // Log the new connection
}

void TCP::onClientDisconnected()
{
    QTcpSocket *client = qobject_cast<QTcpSocket*>(sender()); // Cast the sender to a QTcpSocket
    if(client){
        clients.removeAll(client); // Remove the client from the list
        client->deleteLater(); // Schedule the client socket for deletion
        qDebug() << "Client disconnected"; // Log the disconnection
    }
}

void TCP::onReadyRead()
{
    // Any function here
    QTcpSocket *clients = qobject_cast<QTcpSocket*>(sender()); // Cast the sender to a QTcpSocket
    if(!clients) return; // Return if casting failed

    QByteArray data = clients->readAll(); // Read all available data from the client
//    qDebug() << "Received data from" << clients->peerAddress().toString() << ": " << data;
    DecodeTask *task = new DecodeTask(data); // Create a new DecodeTask with the received data
    task->setAutoDelete(true); // Set the task to auto-delete after running
    QThreadPool::globalInstance()->start(task); // Start the task using the global thread pool

    dataTranslator(data); // Translate the data received from the client
}

void TCP::broadcastMessage(const QByteArray &message)
{
    // BroadcastMessage
    qDebug() << "The TCP Thread ID is:" << QThread::currentThreadId(); // Log the current thread ID
    for(QTcpSocket *client : qAsConst(clients)){ // Iterate through all connected clients
        if(client->state() == QTcpSocket::ConnectedState){ // Check if client is connected
            client->write(message); // Send the message to the client
        }
    }
}

void TCP::sendMessage64Bytes(const QByteArray &datapackage_u64)
{
    QByteArray messageToSend = datapackage_u64; // Prepare the message to send
    // Make sure the message is exactly 64 bytes
    messageToSend.resize(64);  // If the message is shorter than 64 bytes,
                               // it will be zero-padded; if it is longer
                               // than 64 bytes, it will be truncated
    broadcastMessage(messageToSend); // Broadcast the message to all clients
}

void TCP::dataTranslator(const QByteArray &data)
{
    if(data.at(0) == 0x00){
        qDebug() << "0:" << data.toHex(); // Log the data in hex format for debugging
        switch (data.at(1)) {
        case 0x00:
            // Handle case 0x00
            break;
        case 0x01:
            // Handle case 0x01
            break;
        case 0x02:
            // Handle case 0x02
            break;
        case 0x03:
            qDebug() << "TCP Thread ID :" << QThread::currentThreadId(); // Log the current thread ID for case 0x03
            break;
        default:
            // Handle default case
            break;
        }
    }
    else if(data.at(0) == 0x01){
        qDebug() << "1" << data.toHex(); // Log the data in hex format for debugging for case 0x01
    }

//    QDataStream stream(data);
//    stream.setByteOrder(QDataStream::LittleEndian);
//    int firstInt, secondInt;

//    // Make sure there is enough data in the stream to read two integers.
//    if (stream.atEnd()) {
//        qDebug() << "Error: Not enough data to read the first integer.";
//        return;
//    }
//    stream >> firstInt; // Read the first integer from the data stream

//    if (stream.atEnd()) {
//        qDebug() << "Error: Not enough data to read the second integer.";
//        return;
//    }
//    stream >> secondInt; // Read the second integer from the stream

//    qDebug() << "First integer: " << firstInt;
//    qDebug() << "Second integer: " << secondInt;
//    emit sig_sendPWMSignal(firstInt, secondInt);
}
