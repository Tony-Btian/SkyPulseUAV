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
    explicit TCP(QObject *parent = nullptr);
    ~TCP();

public slots:
    void startServer();
    void broadcastMessage(const QByteArray &message);
    void sendMessage64Bytes(const QByteArray &datapackage_u64);

protected:
    void incomingConnection(qintptr socketDescriptor) override;

private slots:
    void onClientDisconnected();
    void onReadyRead();

private:
    QList<QTcpSocket*> clients;
    QThread *TCPThread;
    static constexpr quint16 PORT = 12345;

    void dataTranslator(const QByteArray &data);

signals:
    void sig_sendPWM0Signal(const int &duty_cycle);
    void sig_errorOccured_TCP(const QString &error_message);
    void sig_requestReadAllReg_BMP180();

};

#endif // TCP_H
