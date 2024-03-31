#ifndef UDP_H
#define UDP_H

#include <QThread>
#include <QObject>
#include <QUdpSocket>

class UDP : public QObject
{
    Q_OBJECT
public:
    explicit UDP(QObject *parent = nullptr);
    ~UDP();

public slots:
    void startUDPServer(quint16 port);
    void stopUDPServer();

private:
    QUdpSocket *udpSocket;
    QThread *UDPThread;

private slots:
    void udpInitial();
    void readPendingDatagrams();

signals:
    void messageReceived(const QString &message);
    void ServerStartSucessful();
    void ServerStopSucessful();

};

#endif // UDP_H
