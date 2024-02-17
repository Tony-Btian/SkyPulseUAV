#ifndef BLUETOOTH_H
#define BLUETOOTH_H

#include <QObject>
#include <QtBluetooth/QBluetoothDeviceDiscoveryAgent>
#include <QtBluetooth/QBluetoothSocket>


class Bluetooth : public QObject
{
    Q_OBJECT
public:
    explicit Bluetooth(QObject *parent = nullptr);
    ~Bluetooth();

    void startDeviceDiscovery();
    void connectToDevice(const QBluetoothDeviceInfo &deviceInfo);
    void send(const QByteArray &data);

signals:
    void deviceDiscovered(const QBluetoothDeviceInfo &deviceInfro);
    void connected();
    void disconnected();
    void dataReceived(const QByteArray &data);

private slots:
    void onDeviceDiscovered(const QBluetoothDeviceInfo &deviceInfo);
    void onConnected();
    void onDisconnected();
    void onReadyRead();

private:
    QBluetoothDeviceDiscoveryAgent *discoveryAgent;
    QBluetoothSocket *socket;

};

#endif // BLUETOOTH_H
