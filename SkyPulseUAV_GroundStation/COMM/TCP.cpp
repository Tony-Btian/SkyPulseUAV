#include "TCP.h"
#include "decodetask.h"
#include <QThreadPool>

TCP::TCP(QObject *parent, MediatorInterface *mediator)
    : QObject(parent), TCPSocket(new QTcpSocket(this)), mediator(mediator) // Initialize TCP with a parent and a mediator interface
{
    TCPThread = new QThread(this); // Create a new thread
    connect(TCPThread, &QThread::started, this, &TCP::tcpInitial); // Connect thread start to TCP initialization
    connect(TCPThread, &QThread::finished, TCPThread, &QObject::deleteLater); // Ensure thread is cleaned up after finishing
    this->moveToThread(TCPThread); // Move this TCP instance to the new thread
    TCPThread->start(); // Start the thread
}

TCP::~TCP()
{
    if (TCPThread->isRunning()){ // Check if the thread is still running
        TCPThread->wait(); // Wait for thread operations to finish
        TCPThread->quit(); // Ask the thread to quit
    }
}

/* Initialize TCP services */
void TCP::tcpInitial()
{
    connect(TCPSocket, &QTcpSocket::connected, this, &TCP::onConnected); // Setup signal for successful connection
    connect(TCPSocket, &QTcpSocket::disconnected, this, &TCP::onDisconnected); // Setup signal for disconnection
    connect(TCPSocket, &QTcpSocket::readyRead, this, &TCP::readMessage); // Setup signal for reading incoming data
    connect(TCPSocket, &QTcpSocket::errorOccurred, this, &TCP::onErrorOccurred); // Setup signal for any connection errors
}

/* TCP service connection function */
void TCP::connectToServer(const QString &host, quint16 port)
{
    TCPSocket->connectToHost(host, port); // Initiate connection to server with specified host and port
}

/* TCP successful connection signal */
void TCP::onConnected()
{
    emit sig_connectionSuccessful(); // Emit signal indicating connection success
}

/* TCP service disconnect function */
void TCP::disconnectToServer()
{
    if(TCPSocket->state() == QTcpSocket::ConnectedState){ // Only attempt to disconnect if the socket is connected
        TCPSocket->disconnectFromHost();
    }
}

/* TCP successful disconnection signal */
void TCP::onDisconnected()
{
    emit sig_disconnectionSuccessful(); // Emit signal indicating successful disconnection
}

/* TCP connection error signal */
void TCP::onErrorOccurred()
{
    emit sig_connectionError(); // Emit signal indicating a connection error occurred
}

/* TCP data sending function */
void TCP::sendMessage(const QString &message)
{
    if(TCPSocket->state() == QTcpSocket::ConnectedState) // Only send message if the socket is connected
    {
        TCPSocket->write(message.toUtf8()); // Send UTF-8 encoded data
    }
}

/* TCP data receiving function */
void TCP::readMessage()
{
    QByteArray data = TCPSocket->readAll(); // Read all available data from socket
    qDebug() << "TCP Row Message: " << data; // Debug print raw data
    qDebug() << "TCP Thread ID: " << QThread::currentThreadId(); // Debug print the ID of the current thread

    DecodeTask *task = new DecodeTask(data, mediator); // Create a new decode task
    task->setAutoDelete(true); // Set task to delete itself after running
    QThreadPool::globalInstance()->start(task); // Start the task using the global thread pool
}

void TCP::PWM_Controler(const int &code, const int &value)
{
    QByteArray data; // Prepare a QByteArray to send
    data.append(reinterpret_cast<const char*>(&code), sizeof(code)); // Append the integer code
    data.append(reinterpret_cast<const char*>(&value), sizeof(value)); // Append the integer value
    qDebug() << "Code: " << code << ", " << "Value: " << value; // Debug print the code and value
    qDebug() << data.constData(); // Debug print the constructed data
    sendMessageQByte(data); // Send the constructed QByteArray
}

/* TCP command receiver */
void TCP::commendToFCS(const uint8_t &command_code)
{
    QByteArray message; // Prepare a QByteArray for the command
    message.append(command_code); // Append the command code
    sendMessage(message); // Send the command
}

/* TCP data sending function */
void TCP::sendMessageQByte(const QByteArray &message)
{
    if(TCPSocket->state() == QTcpSocket::ConnectedState) // Only send data if the socket is connected
    {
        TCPSocket->write(message); // Write the QByteArray to the socket
    }
}

/* TCP data validity check */
// QString TCP::dataCheckOut(const QByteArray &data)
// {

// }
