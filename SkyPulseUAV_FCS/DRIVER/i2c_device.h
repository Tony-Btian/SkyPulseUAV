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

#endif // I2C_DEVICE_H
