// GpioInterruptHandler.h

#ifndef GPIOINTERRUPTHANDLER_H
#define GPIOINTERRUPTHANDLER_H

#include <QObject>
#include <pigpio.h>

class GpioInterruptHandler : public QObject {
    Q_OBJECT
public:
    explicit GpioInterruptHandler(QObject *parent = nullptr);
    ~GpioInterruptHandler();
    void startListening();
    static void gpioInterruptCallback(int gpio, int level, uint32_t tick, void* userData);

signals:
    void interruptOccurred();
};

#endif // GPIOINTERRUPTHANDLER_H
