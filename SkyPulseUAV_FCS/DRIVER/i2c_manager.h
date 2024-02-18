#ifndef I2C_MANAGER_H
#define I2C_MANAGER_H

#include <QObject>
#include <QtConcurrent>
#include "i2c_device.h"


class I2C_Manager : public QObject
{
    Q_OBJECT

public:    
    explicit I2C_Manager(QObject *parent = nullptr);
    ~I2C_Manager();

    void addDevice(int deviceAddress);
    void asyncReadSensorData(int deviceAddress, quint8 reg, quint8 count);
    I2C_Device *getDevice(int deviceAddress);


signals:
    void dataRead(int deviceAddress, const QByteArray &data);


private:
    QMap<int, I2C_Device*> devices;
    static QByteArray readSensorData(I2C_Device* device, quint8 reg, quint8 count);

};

#endif // I2C_MANAGER_H
