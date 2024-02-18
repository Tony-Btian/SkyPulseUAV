#ifndef I2C_DEVICE_H
#define I2C_DEVICE_H

#include <QObject>
#include <QMutex>

class I2C_Device : public QObject
{
    Q_OBJECT

public:
    explicit I2C_Device(int deviceAddress, QObject *parent = nullptr);
    ~I2C_Device();

    bool initialize();
    QByteArray readBytes(quint8 reg, quint8 count);
    bool writeBytes(quint8 reg, const QByteArray &data);


private:
    int deviceAddress;
    int handle;
    static QMutex mutex; // Mutex locks for synchronized access


};

#endif // I2C_DEVICE_H
