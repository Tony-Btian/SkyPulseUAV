#ifndef I2CDRIVER_H
#define I2CDRIVER_H

#include <QObject>
#include <QMutex>
#include <QMutexLocker>
#include <QByteArray>
#include <pigpio.h>

class I2CDriver : public QObject
{
    Q_OBJECT

public:
    explicit I2CDriver(int deviceAddress, QObject *parent = nullptr);
    ~I2CDriver();

    bool initialize();
    QByteArray readBytes(quint8 registerAddress, quint8 count);
    bool readByte(quint8 reg, quint8 &value);
    bool writeBytes(quint8 registerAddress, const QByteArray &data);
    bool writeByte(quint8 reg, quint8 value);

private:
    int deviceAddress;
    int handle;
    static QMutex mutex; // Mutex locks for synchronized access

signals:
    void errorOccurred(const QString &message);
};

#endif // I2CDRIVER_H
