#ifndef GPIOINTERRUPTHANDLER_H
#define GPIOINTERRUPTHANDLER_H

#include "pigpio.h"
#include "observer.h"
#include <QObject>
#include <QThread>
#include <QDebug>

class GpioInterruptHandler : public QObject, public Observer
{
    Q_OBJECT
public:
    explicit GpioInterruptHandler(QObject *parent = nullptr);
    ~GpioInterruptHandler();

    void onUpdate(bool isInitialised) override;
    bool initializeGpio();  // Initialise GPIOs, register interrupt handlers
    void deinitializeGpio();  // Deinitialise GPIOs

private:
    static void gpioInterruptCallback(int gpio, int level, uint32_t tick, void *user);
    QThread *GpioInterruptThread;

signals:
    void mpu6050Interrupt();  // Signals emitted when an interrupt occurs in the MPU6050
};

#endif // GPIOINTERRUPTHANDLER_H
