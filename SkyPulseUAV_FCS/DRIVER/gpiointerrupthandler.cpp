// GpioInterruptHandler.cpp

#include "gpiointerrupthandler.h"
#include <QDebug>

GpioInterruptHandler::GpioInterruptHandler(QObject *parent) : QObject(parent) {

}

GpioInterruptHandler::~GpioInterruptHandler() {
    gpioSetISRFuncEx(17, EITHER_EDGE, 0, nullptr, nullptr); // Remove interrupt callback
}

void GpioInterruptHandler::startListening() {
    if (gpioInitialise() < 0) {
        qWarning() << "gpioInitialise failed";
        return;
    }

    gpioSetMode(17, PI_INPUT); // Set GPIO 17 as input
    gpioSetPullUpDown(17, PI_PUD_UP); // Enable pull-up

    // Register the callback function for the interrupt
    gpioSetISRFuncEx(17, EITHER_EDGE, 0, gpioInterruptCallback, this);
}

void GpioInterruptHandler::gpioInterruptCallback(int gpio, int level, uint32_t tick, void* userData) {
    Q_UNUSED(gpio)
    Q_UNUSED(level)
    Q_UNUSED(tick)
    auto* instance = static_cast<GpioInterruptHandler*>(userData);
    emit instance->interruptOccurred();
}
