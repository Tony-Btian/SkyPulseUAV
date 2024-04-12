#ifndef I2C_DEVICE_H
#define I2C_DEVICE_H

#include <QObject>
#include <QMutex>

class I2C_Device : public QObject
{
    Q_OBJECT

public:
    explicit I2C_Device(int deviceAddress, QObject *parent = nullptr); // Constructor with device address and optional parent
    ~I2C_Device(); // Destructor to clean up resources

    bool initialize(); // Initializes the I2C connection
    QByteArray readBytes(quint8 registerAddress, quint8 count); // Reads bytes from a register
    bool readByte(quint8 reg, quint8 &value); // Reads a single byte from a register
    bool writeBytes(quint8 registerAddress, const QByteArray &data); // Writes bytes to a register
    bool writeByte(quint8 reg, quint8 value); // Writes a single byte to a register

private:
    int deviceAddress; // I2C device address
    int handle; // Handle to the opened I2C device
    static QMutex mutex; // Static mutex for thread-safe operations

signals:
    void errorOccurred(const QString &message); // Signal emitted on error

};

#endif // I2C_DEVICE_H

