#ifndef TCP_H
#define TCP_H

#include <QTcpServer>
#include <QTcpSocket>
#include <QTimer>
#include <QThread>

/**
 * @class TCP Server
 * @brief TCP Server Class
 *
 * This TCP Server Class is used for the data and communication
 * interaction with SkyPulse UAV ground stations. This class
 * directly inherits QTCPServer.
 */
class TCP : public QTcpServer
{
    Q_OBJECT

public:
    explicit TCP(QObject *parent = nullptr); // Constructor to create TCP server with optional parent
    ~TCP(); // Destructor to clean up when the server is deleted

public slots:
    void startServer(); // Slot to start the server listening for incoming connections
    void broadcastMessage(const QByteArray &message); // Slot to broadcast a message to all connected clients
    void sendMessage64Bytes(const QByteArray &datapackage_u64); // Slot to send a 64-byte message to all connected clients

protected:
    void incomingConnection(qintptr socketDescriptor) override; // Handles incoming client connections

private slots:
    void onClientDisconnected(); // Slot triggered when a client disconnects
    void onReadyRead(); // Slot triggered when there is data ready to be read from a client

private:
    QList<QTcpSocket*> clients; // List of pointers to connected clients
    QThread *TCPThread; // Pointer to the thread that the server operates in
    static constexpr quint16 PORT = 12345; // Port number on which the server listens

    void dataTranslator(const QByteArray &data); // Translates received data into meaningful information

signals:
    void sig_sendPWMSignal(const int &gpio_pin, const int &duty_cycle); // Signal to send a PWM signal
    void sig_errorOccured_TCP(const QString &error_message); // Signal emitted when an error occurs

};

#endif // TCP_H

