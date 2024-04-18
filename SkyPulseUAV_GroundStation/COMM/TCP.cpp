#include "TCP.h"

TCP::TCP(QObject *parent, MediatorInterface *mediator)
    : QObject(parent), TCPSocket(new QTcpSocket(this)), mediator(mediator)
{
    TCPThread = new QThread(this);
    connect(TCPThread, &QThread::started, this, &TCP::tcpInitial);
    connect(TCPThread, &QThread::finished, TCPThread, &QObject::deleteLater);
    this->moveToThread(TCPThread);
    TCPThread->start();
}

TCP::~TCP()
{
    if (TCPThread->isRunning()){
        TCPThread->wait();
        TCPThread->quit();
    }
}

/*TCP服务初始化*/
void TCP::tcpInitial()
{
    connect(TCPSocket, &QTcpSocket::connected, this, &TCP::onConnected);
    connect(TCPSocket, &QTcpSocket::disconnected, this, &TCP::onDisconnected);
    connect(TCPSocket, &QTcpSocket::errorOccurred, this, &TCP::onErrorOccurred);
    connect(TCPSocket, &QTcpSocket::readyRead, this, &TCP::readMessage);
}

/*TCP服务连接函数*/
void TCP::startTCPServer(const QString &host_ip, quint16 port)
{
    TCPSocket->connectToHost(host_ip, port);
}

/*TCP连接成功信号*/
void TCP::onConnected()
{
    emit sig_startSuccessful(); // 当连接成功时发出信号
}

/*TCP服务断开连接函数*/
void TCP::stopTCPServer()
{
    if(TCPSocket->state() == QTcpSocket::ConnectedState){  // 判断连接状态之后再断开连接
        TCPSocket->disconnectFromHost();
    }
}

/*TCP断开成功信号*/
void TCP::onDisconnected()
{
    emit sig_stopSuccessful(); // 当断开连接成功时发出信号
}

/*TCP错误信号*/
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
    qDebug() << "TCP Thread ID: " << QThread::currentThreadId();
    dataDecoder(data);
}

/*TCP 控制信息接收器*/
void TCP::commendToFCS(const uint8_t &command_code)
{
    QByteArray message;
    message.append(command_code);
    sendMessage(message);
}

/*TCP数据发送函数*/
void TCP::sendMessageQByte(const QByteArray &message)
{
    if(TCPSocket->state() == QTcpSocket::ConnectedState)
    {
        TCPSocket->write(message);
    }
}

/*PWM 控制信息接收器*/
void TCP::PWM_Controler(const QVector<uint8_t> &pwm_value)
{
    sendMessage(QByteArray(reinterpret_cast<const char*>(pwm_value.data()), pwm_value.size()));
}

/*Flight Control*/
void TCP::Flight_Controler(const QVector<uint8_t> &control_data)
{
    sendMessage(QByteArray(reinterpret_cast<const char*>(control_data.data()), control_data.size()));
}

/*Flight Config*/
void TCP::Flight_Config_Setting(const QVector<uint8_t> &config_data)
{

}

void TCP::dataDecoder(const QByteArray &data_to_decode)
{
    QFuture<void> future = QtConcurrent::run([this, data_to_decode](){
        qDebug() << "Data Decoder Thread: " << QThread::currentThreadId();
        QDataStream stream(data_to_decode);
        stream.setByteOrder(QDataStream::LittleEndian);

        float ax, ay, az, gx, gy, gz;
        double pressure, temperature, heading;
        int x, y, z;

        stream >> ax >> ay >> az >> gx >> gy >> gz >> pressure >> temperature >> x >> y >> z >> heading;

        if (stream.status() != QDataStream::Ok) {
            qWarning() << "Failed to decode data from stream";
            return;
        }

        QStringList dataList;
        dataList << QString::number(ax, 'f', 2) << QString::number(ay, 'f', 2) << QString::number(az, 'f', 2)
                 << QString::number(gx, 'f', 2) << QString::number(gy, 'f', 2) << QString::number(gz, 'f', 2)
                 << QString::number(pressure) << QString::number(temperature)
                 << QString::number(x) << QString::number(y) << QString::number(z)
                 << QString::number(heading);

        emit sig_UIupdate(dataList);
    });
    future.waitForFinished();
}
