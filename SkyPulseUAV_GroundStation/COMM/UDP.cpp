#include "UDP.h"
#include <QNetworkDatagram>

UDP::UDP(QObject *parent) : QObject(parent), udpSocket(new QUdpSocket(this))
{
    UDPThread = new QThread(this); // Initialize a new thread for UDP operations
    connect(UDPThread, &QThread::started, this, &UDP::udpInitial); // Connect thread start to UDP initialization
    connect(UDPThread, &QThread::finished, this, &QObject::deleteLater); // Ensure thread is deleted when finished
    this->moveToThread(UDPThread); // Move this UDP instance to the newly created thread
    UDPThread->start(); // Start the thread
}

UDP::~UDP()
{
    if (UDPThread->isRunning()){ // Check if the thread is still running
        UDPThread->wait(); // Wait for the thread to finish its operations
        UDPThread->quit(); // Request the thread to quit
    }
}

void UDP::udpInitial()
{
    connect(udpSocket, &QUdpSocket::readyRead, this, &UDP::readPendingDatagrams); // Setup signal for reading incoming data
}

void UDP::startServer(quint16 port)
{
    bool result = udpSocket->bind(port, QUdpSocket::ShareAddress); // Attempt to bind the UDP socket to the specified port
    if(!result){
        // Binding failed, handle error, such as logging or notifying user
        qDebug() << "Unable to bind UDP socket on port" << port << ":" << udpSocket->errorString();
        return;
    }
    emit ServerStartSucessful(); // Emit signal indicating server started successfully
}

void UDP::stopServer()
{
    udpSocket->close(); // Close the UDP socket
    if (udpSocket->state() == QAbstractSocket::UnconnectedState) {
        qDebug() << "UDP socket closed successfully."; // Log successful closure
        emit ServerStopSucessful(); // Emit signal indicating server stopped successfully
    } else {
        // This scenario is unlikely but can be handled if necessary
        qDebug() << "UDP socket might not have closed properly.";
    }
}

void UDP::readPendingDatagrams()
{
    qDebug() << "UDP Current Thread ID: " << QThread::currentThreadId(); // Log the current thread ID
    while (udpSocket->hasPendingDatagrams()) {
        QNetworkDatagram datagram = udpSocket->receiveDatagram(); // Receive incoming datagram
        QString message = QString::fromUtf8(datagram.data()); // Convert datagram data to string
        emit messageReceived(message); // Emit signal with the received message
    }
}

