#include "gpiointerrupthandler.h"

GpioInterruptHandler::GpioInterruptHandler(QObject *parent)
{
    GpioInterruptThread = new QThread(this);
    this->moveToThread(GpioInterruptThread);
    GpioInterruptThread->start();
}

GpioInterruptHandler::~GpioInterruptHandler()
{
    deinitializeGpio();
    GpioInterruptThread->quit();
    GpioInterruptThread->wait();
    GpioInterruptThread->deleteLater();
}

void GpioInterruptHandler::onUpdate(bool isInitialised)
{
    if(isInitialised){
        qWarning("GPIO Interrupt: GPIO initialized.");
    }
    else{
        if (gpioInitialise() < 0) {
            qWarning("Failed to initialize pigpio library");
        }
    }
    initializeGpio();
}

bool GpioInterruptHandler::initializeGpio()
{
    // Set GPIO17 to input mode and register interrupt callback function
    if (gpioSetMode(17, PI_INPUT) < 0) {
        return false;
    }
    if (gpioSetPullUpDown(17, PI_PUD_DOWN) < 0) { // Setting up internal pull-ups
        return false;
    }
    if (gpioSetAlertFuncEx(17, gpioInterruptCallback, this) < 0) {
        return false;
    }
    qWarning("GPIO Interrupt: GPIO Configed.");
    return true;
}

void GpioInterruptHandler::deinitializeGpio()
{
    gpioSetAlertFunc(17, nullptr); // Remove the interrupt handler
}

void GpioInterruptHandler::gpioInterruptCallback(int gpio, int level, uint32_t tick, void *user)
{
    Q_UNUSED(gpio)
    Q_UNUSED(level)
    Q_UNUSED(tick)
    qDebug() << "Call Back Thread: " << QThread::currentThreadId();
    auto *handler = static_cast<GpioInterruptHandler *>(user);
    if (handler) {
        emit handler->mpu6050Interrupt(); // transmitting signal
    }
}
