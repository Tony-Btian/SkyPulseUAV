// GpioInterruptHandler.cpp

#include "gpiointerrupthandler.h"
#include <QDebug>

GpioInterruptHandler::GpioInterruptHandler(int pin, QObject *parent)
    : gpioPin(pin), QObject(parent) {
    initializeGpio();
}

GpioInterruptHandler::~GpioInterruptHandler() {
    gpioSetISRFunc(gpioPin, EITHER_EDGE, 0, nullptr); // Remove interrupt callback
}

void GpioInterruptHandler::initializeGpio() {
    if (gpioInitialise() < 0) {
        qWarning() << "gpioInitialise failed";
        return;
    }

    gpioSetMode(gpioPin, PI_INPUT); // Set GPIO 17 as input
    gpioSetPullUpDown(gpioPin, PI_PUD_UP); // Enable pull-up

    // Register the callback function for the interrupt
    gpioSetISRFuncEx(gpioPin, EITHER_EDGE, 0, gpioCallback, this);
}

void GpioInterruptHandler::gpioCallback(int pin, int level, uint32_t tick, void* user) {
    Q_UNUSED(pin)
    Q_UNUSED(level)
    Q_UNUSED(tick)

    GpioInterruptHandler* handler = static_cast<GpioInterruptHandler*>(user);
    emit handler->interruptOccurred();
}
