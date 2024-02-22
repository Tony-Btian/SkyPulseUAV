#include "Bluetooth.h"

Bluetooth::Bluetooth(QObject *parent) : QObject(parent) {
    discoveryAgent = new QBluetoothDeviceDiscoveryAgent(this);
    socket = new QBluetoothSocket(QBluetoothServiceInfo::RfcommProtocol, this);

    connect(discoveryAgent, &QBluetoothDeviceDiscoveryAgent::deviceDiscovered, this, &Bluetooth::onDeviceDiscovered);
    connect(discoveryAgent, &QBluetoothDeviceDiscoveryAgent::finished, discoveryAgent, &QBluetoothDeviceDiscoveryAgent::deleteLater);
    connect(socket, &QBluetoothSocket::connected, this, &Bluetooth::onConnected);
    connect(socket, &QBluetoothSocket::disconnected, this, &Bluetooth::onDisconnected);
    connect(socket, &QBluetoothSocket::readyRead, this, &Bluetooth::onReadyRead);
}

Bluetooth::~Bluetooth()
{
    socket->disconnectFromService();
}

void Bluetooth::startDeviceDiscovery()
{
    discoveryAgent->start();
}

void Bluetooth::connectToDevice(const QBluetoothDeviceInfo &deviceInfo)
{
    socket->connectToService(deviceInfo.address(), deviceInfo.deviceUuid());
}

void Bluetooth::send(const QByteArray &data)
{
    if (socket->state() == QBluetoothSocket::SocketState::ConnectedState){
        socket->write(data);
    }
}

void Bluetooth::onDeviceDiscovered(const QBluetoothDeviceInfo &deviceInfo)
{
    emit deviceDiscovered(deviceInfo);
}

void Bluetooth::onConnected()
{
    emit connected();
}

void Bluetooth::onDisconnected()
{
    emit disconnected();
}

void Bluetooth::onReadyRead()
{
    QByteArray data = socket->readAll();
    emit dataReceived(data);
}
