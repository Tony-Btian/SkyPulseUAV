#ifndef MEG_COMPASS_H
#define MEG_COMPASS_H

#include <QObject>
#include "i2c_device.h"


class MEG_Compass : public QObject
{
    Q_OBJECT

public:
    explicit MEG_Compass(I2C_Device *device, QObject *parent = nullptr);
    void readRawData();

private:
    I2C_Device *device;

    static int i2cHandle; // Handle for I2C communication

    int16_t convertToRawData(const QByteArray &bytes, int offset);

signals:
    void sig_rawDataRead(int x, int y, int z);

};

#endif // MEG_COMPASS_H
