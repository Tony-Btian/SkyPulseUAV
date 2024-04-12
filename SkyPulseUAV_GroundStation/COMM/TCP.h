#ifndef TCP_H
#define TCP_H

#include <QThread>
#include <QObject>
#include <QTcpSocket>
#include "MediatorInterface.h"

#define WRITE 0x01 // Define WRITE operation code
#define READ  0x00 // Define READ operation code

class TCP : public QObject {
    Q_OBJECT

public:
    explicit TCP(QObject *parent = nullptr, MediatorInterface* mediator = nullptr); // Constructor with optional parent and mediator
    ~TCP(); // Destructor

    void connectToServer(const QString &host, quint16 port); // Connect to a TCP server
    void disconnectToServer(); // Disconnect from the TCP server

private:
    QTcpSocket *TCPSocket; // TCP socket for communication
    QThread *TCPThread; // Thread for handling TCP operations
    MediatorInterface* mediator; // Mediator for handling interactions

    QString dataCheckOut(const QByteArray &data); // Method to check data validity

public slots:
    void sendMessage(const QString &message); // Send message as a string
    void sendMessageQByte(const QByteArray &message); // Send message as QByteArray
    void readMessage(); // Slot to handle incoming messages
    void PWM_Controler(const int &code, const int &value); // Control PWM via TCP
    void commendToFCS(const uint8_t &command_code); // Send command to the Flight Control System

private slots:
    void tcpInitial(); // Initialize TCP connections

    void onConnected(); // Slot triggered on successful connection
    void onDisconnected(); // Slot triggered on successful disconnection
    void onErrorOccurred(); // Slot triggered on connection error

signals:
    void sig_connectionSuccessful();  // Signal for successful connection
    void sig_disconnectionSuccessful();  // Signal for successful disconnection
    void sig_connectionError(); // Signal for connection errors
};

#endif // TCP_H

