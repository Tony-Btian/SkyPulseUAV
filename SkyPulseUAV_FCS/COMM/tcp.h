#ifndef TCP_H
#define TCP_H

#include <QObject>
#include <QVector>
#include <QTcpServer>
#include <QTcpSocket>
#include <QTimer>
#include <QThread>
#include <QHostAddress>
#include <QThreadPool>
#include <QDataStream>
#include <QDebug>

#include "motorpwm.h"

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
//    MotorPWM *motor_pwm;

    static constexpr quint16 PORT = 12345;
    void dataTranslator(const QByteArray &data);

signals:
    void sig_sendPWMSignal(const QVector<quint8> &MotorPWM);
    void sig_errorOccured_TCP(const QString &error_message);
    void sig_requestReadAllReg_BMP180();
    void sig_requestReadAllReg_MPU6050();
    void sig_requestReadAllReg_GY271();
};

#endif // TCP_H
