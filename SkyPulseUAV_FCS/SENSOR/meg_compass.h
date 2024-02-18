#ifndef MEG_COMPASS_H
#define MEG_COMPASS_H

#include <QObject>
#include "i2c_device.h"

#define DEVICE_ADDR 0x3C

class MEG_Compass : public QObject
{
    Q_OBJECT

public:
    explicit MEG_Compass(I2C_Device * device, QObject *parent = nullptr);
    void readRawData();


private:
    I2C_Device* device;
    int16_t convertToRawData(const QByteArray& bytes, int offset);

signals:
    void rawDataRead(int x, int y, int z);

};

#endif // MEG_COMPASS_H
