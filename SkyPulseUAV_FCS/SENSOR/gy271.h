#ifndef GY271_H
#define GY271_H

#include <QObject>
#include "i2cdriver.h"

class GY271 : public QObject
{
    Q_OBJECT

public:
    explicit GY271(uint8_t i2cAddress = 0x0D, QObject *parent = nullptr);
    bool initializeGY271();

public slots:
    void readRawData(int &x, int &y, int &z);

private:
    I2CDriver *i2cDriver;
    bool writeByte(uint8_t reg, uint8_t value);
    int16_t convertToRawData(const QByteArray &bytes, int offset);
};

#endif // GY271_H
