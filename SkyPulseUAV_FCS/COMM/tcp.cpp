#include "tcp.h"

TCP::TCP(QObject *parent)
    : QTcpServer(parent)
{
    TCPThread = new QThread(this);
    connect(TCPThread, &QThread::started, this, &TCP::startServer);
    connect(TCPThread, &QThread::finished, TCPThread, &QObject::deleteLater);
    this->moveToThread(TCPThread);
    TCPThread->start();

//    motor_pwm = new MotorPWM();
}

TCP::~TCP()
{
    if (TCPThread->isRunning()){
//        delete motor_pwm;
        TCPThread->wait();
        TCPThread->quit();
    }
}

void TCP::startServer()
{
    qDebug() << "TCP Initialized Thread:" << QThread::currentThreadId();
    if(this->listen(QHostAddress::Any, PORT)){
        qDebug() << "TCP Server started on port:" << PORT;
    }
    else
    {
        qDebug() << "TCP Server failed to start:" << this->errorString();
    }
}

void TCP::incomingConnection(qintptr socketDescriptor)
{
    QTcpSocket *client = new QTcpSocket(this);
    client->setSocketDescriptor(socketDescriptor);

    connect(client, &QTcpSocket::disconnected, this, &TCP::onClientDisconnected);
    connect(client, &QTcpSocket::readyRead, this, &TCP::onReadyRead);

    clients.append(client);
    qDebug() << "Client connected:" << client->peerAddress().toString();
}

void TCP::onClientDisconnected()
{
    QTcpSocket *client = qobject_cast<QTcpSocket*>(sender());
    if(client){
        clients.removeAll(client);
        client->deleteLater();
        qWarning("Client disconnected");
    }
}

void TCP::onReadyRead()
{
    // Any function here
    QTcpSocket *clients = qobject_cast<QTcpSocket*>(sender());
    if(!clients) return;
    QByteArray data = clients->readAll();

//    DecodeTask *task = new DecodeTask(data, mediator);
//    task->setAutoDelete(true);
//    QThreadPool::globalInstance()->start(task);

    this->dataTranslator(data);
}

void TCP::broadcastMessage(const QByteArray &message)
{
    // BroadcastMessage
    qDebug() << "The TCP Thread ID is:" << QThread::currentThreadId();
    for(QTcpSocket *client : qAsConst(clients)){
        if(client->state() == QTcpSocket::ConnectedState){
            client->write(message);
        }
    }
}

void TCP::sendMessage64Bytes(const QByteArray &datapackage_u64)
{
    QByteArray messageToSend = datapackage_u64;
    // Make sure the message is exactly 64 bytes
    messageToSend.resize(64);  // If the message is shorter than 64 bytes,
                               // it will be zero-padded; if it is longer
                               // than 64 bytes, it will be truncated
    broadcastMessage(messageToSend);
}

void TCP::dataTranslator(const QByteArray &data)
{
    if(data.isEmpty()) return;
    switch (static_cast<unsigned char>(data[0])) {
    case 0x00:
        emit sig_requestReadAllReg_MPU6050();
        break;
    case 0x01:
        emit sig_requestReadAllReg_BMP180();
        break;
    case 0x02:
        emit sig_requestReadAllReg_GY271();
        break;
    case 0x03:
    {
        QVector<quint8> PWM = {static_cast<quint8>(data[1]),
                               static_cast<quint8>(data[2]),
                               static_cast<quint8>(data[3]),
                               static_cast<quint8>(data[4])};
        emit sig_sendPWMSignal(PWM);
    }
        break;
    default:
        break;
    }
}
