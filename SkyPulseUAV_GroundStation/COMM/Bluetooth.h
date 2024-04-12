#ifndef BLUETOOTH_H
#define BLUETOOTH_H

#include <QObject>
#include <QtBluetooth/QBluetoothDeviceDiscoveryAgent>
#include <QtBluetooth/QBluetoothSocket>


class Bluetooth : public QObject
{
    Q_OBJECT
public:
    explicit Bluetooth(QObject *parent = nullptr); // Constructor with an optional QObject parent
    ~Bluetooth(); // Destructor to clean up resources

    void startDeviceDiscovery(); // Initiates discovery of Bluetooth devices
    void connectToDevice(const QBluetoothDeviceInfo &deviceInfo); // Connects to a specified Bluetooth device
    void send(const QByteArray &data); // Sends data over a Bluetooth connection

signals:
    void deviceDiscovered(const QBluetoothDeviceInfo &deviceInfo); // Emitted when a new device is discovered
    void connected(); // Emitted when a Bluetooth connection is established
    void disconnected(); // Emitted when a Bluetooth connection is disconnected
    void dataReceived(const QByteArray &data); // Emitted when data is received over Bluetooth

private slots:
    void onDeviceDiscovered(const QBluetoothDeviceInfo &deviceInfo); // Slot to handle newly discovered devices
    void onConnected(); // Slot to handle Bluetooth connection establishment
    void onDisconnected(); // Slot to handle Bluetooth disconnection
    void onReadyRead(); // Slot to handle readiness to read data from Bluetooth socket

private:
    QBluetoothDeviceDiscoveryAgent *discoveryAgent; // Manages device discovery
    QBluetoothSocket *socket; // Manages Bluetooth connections

};

#endif // BLUETOOTH_H

