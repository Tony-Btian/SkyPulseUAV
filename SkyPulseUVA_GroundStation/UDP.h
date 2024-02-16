#ifndef UDP_H
#define UDP_H

#include <QObject>
#include <QUdpSocket>

class UDP : public QObject
{
    Q_OBJECT
public:
    explicit UDP(QObject *parent = nullptr);

public slots:
    void startServer(quint16 port);
    void stopServer();

private:
    QUdpSocket *udpSocket;

private slots:
    void readPendingDatagrams();

signals:
    void messageReceived(const QString &message);
    void ServerStartSucessful();
    void ServerStopSucessful();

};

#endif // UDP_H
