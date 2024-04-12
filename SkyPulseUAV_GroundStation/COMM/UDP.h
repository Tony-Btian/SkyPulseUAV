#ifndef UDP_H
#define UDP_H

#include <QThread>
#include <QObject>
#include <QUdpSocket>

class UDP : public QObject
{
    Q_OBJECT
public:
    explicit UDP(QObject *parent = nullptr); // Constructor with optional QObject parent
    ~UDP(); // Destructor cleans up resources

public slots:
    void startServer(quint16 port); // Start UDP server on specified port
    void stopServer(); // Stop the UDP server

private:
    QUdpSocket *udpSocket; // UDP socket for network communication
    QThread *UDPThread; // Thread to handle asynchronous operations

private slots:
    void udpInitial(); // Initialize UDP settings
    void readPendingDatagrams(); // Read and process incoming UDP datagrams

signals:
    void messageReceived(const QString &message); // Signal emitted when a message is received
    void ServerStartSucessful(); // Signal emitted when server successfully starts
    void ServerStopSucessful(); // Signal emitted when server is successfully stopped

};

#endif // UDP_H

