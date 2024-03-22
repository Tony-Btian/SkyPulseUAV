#ifndef TCP_H
#define TCP_H

#include <QTcpServer>
#include <QTcpSocket>
#include <QTimer>
#include <QThread>

class TCP : public QTcpServer
{
    Q_OBJECT

public:
    explicit TCP(QObject *parent = nullptr);
    ~TCP();

public slots:
    void startServer(quint16 port);
    void broadcastMessage(const QByteArray &message);

protected:
    void incomingConnection(qintptr socketDescriptor) override;

private slots:
    void onClientDisconnected();
    void onReadyRead();

private:
    QList<QTcpSocket*> clients;
    QThread *TCPThread;

    void dataTranslator(const QByteArray &data);

signals:
    void sig_sendPWMSignal(const int &gpio_pin, const int &duty_cycle);
};

#endif // TCP_H
