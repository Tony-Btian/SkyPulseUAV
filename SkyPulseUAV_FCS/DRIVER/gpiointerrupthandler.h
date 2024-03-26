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

    void initializeGpio();

private:
    int gpioPin;
    static void gpioCallback(int pin, int level, uint32_t tick, void *user);

signals:
    void interruptOccurred();
};

#endif // GPIOINTERRUPTHANDLER_H
