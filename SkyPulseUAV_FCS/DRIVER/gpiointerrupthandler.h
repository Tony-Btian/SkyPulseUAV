#ifndef GPIOINTERRUPTHANDLER_H
#define GPIOINTERRUPTHANDLER_H

#include <QObject>
#include <QThread>
#include <pigpio.h>

class GpioInterruptHandler : public QObject
{
    Q_OBJECT

public:
    GpioInterruptHandler(int pin, QObject *parent = nullptr);
    ~GpioInterruptHandler();

    void startListening();
    void stopListening();

signals:
    void interruptOccurred();

private:
    QThread workerThread;
    int gpioPin;
    static void gpioInterruptCallback(int gpio, int level, uint32_t tick, void *userData);

};

#endif // GPIOINTERRUPTHANDLER_H
