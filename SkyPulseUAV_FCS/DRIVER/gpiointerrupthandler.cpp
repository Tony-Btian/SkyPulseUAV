#include "gpiointerrupthandler.h"

GpioInterruptHandler::GpioInterruptHandler(int pin, QObject *parent)
    : QObject(parent), gpioPin(pin) {
    moveToThread(&workerThread);
    connect(&workerThread, &QThread::started, this, &GpioInterruptHandler::startListening);
    connect(&workerThread, &QThread::finished, this, &GpioInterruptHandler::stopListening);
    workerThread.start();
}

GpioInterruptHandler::~GpioInterruptHandler() {
    workerThread.quit();
    workerThread.wait();
    workerThread.deleteLater();
}

void GpioInterruptHandler::startListening() {
    if (gpioInitialise() < 0) {
        // Initial failed Operation
        return;
    }
    gpioSetISRFuncEx(gpioPin, EITHER_EDGE, 0, gpioInterruptCallback, this);
}

void GpioInterruptHandler::stopListening() {
    gpioSetISRFuncEx(gpioPin, EITHER_EDGE, 0, nullptr, nullptr);
    gpioTerminate();
}

void GpioInterruptHandler::gpioInterruptCallback(int gpio, int level, uint32_t tick, void *userData) {
    Q_UNUSED(gpio)
    Q_UNUSED(level)
    Q_UNUSED(tick)
    auto handler = static_cast<GpioInterruptHandler*>(userData);
    emit handler->interruptOccurred();
}
