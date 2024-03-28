// GpioInterruptHandler.h

#ifndef GPIOINTERRUPTHANDLER_H
#define GPIOINTERRUPTHANDLER_H

#include <QObject>
#include <pigpio.h>

class GpioInterruptHandler : public QObject {
    Q_OBJECT

public:
    explicit GpioInterruptHandler(int pin, QObject *parent = nullptr);
    ~GpioInterruptHandler();

    bool initializeGpio();
    void deinitializeGpio();

private:
    static void gpioInterruptCallback(int gpio, int level, uint32_t tick, void *user);

signals:
    void mpu6050Interrupt();
};

#endif // GPIOINTERRUPTHANDLER_H
