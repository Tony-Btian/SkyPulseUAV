#ifndef TCP_H
#define TCP_H

#include <QTcpServer>
#include <QTcpSocket>
#include <QTimer>

class TCP : public QTcpServer
{
    Q_OBJECT

public:
    explicit TCP(QObject *parent = nullptr);
    void startServer(quint16 port);
    void broadcastMessage(const QByteArray &message);

protected:
    void incomingConnection(qintptr socketDescriptor) override;

private slots:
    void onClientDisconnected();
    void onReadyRead();

private:
    QList<QTcpSocket*> clients;
    void dataTranslator(const QByteArray &data);

signals:
    void sig_sendPWMSignal(const int &gpio_pin, const int &duty_cycle);
};

#endif // TCP_H
