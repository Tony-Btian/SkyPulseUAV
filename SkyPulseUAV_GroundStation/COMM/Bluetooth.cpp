#include "Bluetooth.h"

Bluetooth::Bluetooth(QObject *parent) : QObject(parent) {
    discoveryAgent = new QBluetoothDeviceDiscoveryAgent(this); // Initialize the Bluetooth device discovery agent
    socket = new QBluetoothSocket(QBluetoothServiceInfo::RfcommProtocol, this); // Initialize the Bluetooth socket for RFCOMM protocol

    // Connect signals and slots for Bluetooth discovery and connection
    connect(discoveryAgent, &QBluetoothDeviceDiscoveryAgent::deviceDiscovered, this, &Bluetooth::onDeviceDiscovered);
    connect(discoveryAgent, &QBluetoothDeviceDiscoveryAgent::finished, discoveryAgent, &QBluetoothDeviceDiscoveryAgent::deleteLater);
    connect(socket, &QBluetoothSocket::connected, this, &Bluetooth::onConnected);
    connect(socket, &QBluetoothSocket::disconnected, this, &Bluetooth::onDisconnected);
    connect(socket, &QBluetoothSocket::readyRead, this, &Bluetooth::onReadyRead);
}

Bluetooth::~Bluetooth()
{
    socket->disconnectFromService(); // Disconnect the socket from the Bluetooth service when the object is destroyed
}

void Bluetooth::startDeviceDiscovery()
{
    discoveryAgent->start(); // Start the Bluetooth device discovery process
}

void Bluetooth::connectToDevice(const QBluetoothDeviceInfo &deviceInfo)
{
    socket->connectToService(deviceInfo.address(), deviceInfo.deviceUuid()); // Connect to the selected Bluetooth device service
}

void Bluetooth::send(const QByteArray &data)
{
    if (socket->state() == QBluetoothSocket::SocketState::ConnectedState){
        socket->write(data); // Send data if the socket is connected
    }
}

void Bluetooth::onDeviceDiscovered(const QBluetoothDeviceInfo &deviceInfo)
{
    emit deviceDiscovered(deviceInfo); // Emit a signal when a new device is discovered
}

void Bluetooth::onConnected()
{
    emit connected(); // Emit a signal when the Bluetooth connection is successfully established
}

void Bluetooth::onDisconnected()
{
    emit disconnected(); // Emit a signal when the Bluetooth connection is disconnected
}

void Bluetooth::onReadyRead()
{
    QByteArray data = socket->readAll(); // Read all available data from the Bluetooth socket
    emit dataReceived(data); // Emit a signal with the received data
}

