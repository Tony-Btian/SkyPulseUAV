#include "gpiointerrupthandler.h"

GpioInterruptHandler::GpioInterruptHandler(QObject *parent)
{
    GpioInterruptThread = new QThread(this); // Initializes a new thread for GPIO interrupt handling
    this->moveToThread(GpioInterruptThread); // Moves this instance to the newly created thread
    GpioInterruptThread->start(); // Starts the thread, allowing for asynchronous operation
}

GpioInterruptHandler::~GpioInterruptHandler()
{
    deinitializeGpio(); // Cleans up GPIO configuration before the object is destroyed
    GpioInterruptThread->quit(); // Signals the thread to quit its event loop
    GpioInterruptThread->wait(); // Waits for the thread to finish processing any pending events
    GpioInterruptThread->deleteLater(); // Schedules the thread object for deletion
}

void GpioInterruptHandler::onUpdate(bool isInitialised)
{
    if(isInitialised){
        qWarning("GPIO Interrupt: GPIO initialized."); // Warns if the GPIO was already initialized
    }
    else{
        if (gpioInitialise() < 0) { // Attempts to initialize the GPIO library and checks for failure
            qWarning("Failed to initialize pigpio library"); // Logs failure to initialize the pigpio library
        }
    }
    initializeGpio(); // Proceeds to initialize GPIO settings for interrupt handling
}

bool GpioInterruptHandler::initializeGpio()
{
    if (gpioSetMode(17, PI_INPUT) < 0) { // Sets GPIO pin 17 to input mode
        return false;
    }
    if (gpioSetPullUpDown(17, PI_PUD_DOWN) < 0) { // Activates pull-down resistor on pin 17
        return false;
    }
    if (gpioSetAlertFuncEx(17, gpioInterruptCallback, this) < 0) { // Registers a callback function for GPIO pin 17 interrupts
        return false;
    }
    qWarning("GPIO Interrupt: GPIO Configed."); // Logs successful GPIO configuration
    return true; // Indicates successful GPIO initialization
}

void GpioInterruptHandler::deinitializeGpio()
{
    gpioSetAlertFunc(17, nullptr); // Removes the interrupt handler for GPIO pin 17
}

void GpioInterruptHandler::gpioInterruptCallback(int gpio, int level, uint32_t tick, void *user)
{
    Q_UNUSED(gpio) // Marks the gpio parameter as unused to avoid compiler warnings
    Q_UNUSED(tick) // Marks the tick parameter as unused to avoid compiler warnings

    auto *handler = static_cast<GpioInterruptHandler *>(user); // Casts the user pointer back to a GpioInterruptHandler instance
    if(!handler){
        return; // Early return if the handler is null, providing a basic form of error checking
    }

    bool currentState = (level == 1); // Determines the current state based on the interrupt level
    if(currentState != handler->lastState){ // Checks if there has been a change in state
        handler->debounceCounter++; // Increments debounce counter to filter out noise
        if(handler->debounceCounter >= handler->debounceThreshold){ // Checks if debounce threshold has been reached
            qDebug() << "Debounced GPIO state change detected"; // Logs a debounced state change
            handler->debounceCounter = 0; // Resets the debounce counter
            emit handler->mpu6050Interrupt(); // Emits a signal indicating an MPU6050 interrupt
        }
    }
    else{
        handler->debounceCounter = 0; // Resets the debounce counter if the state hasn't changed
    }

    handler->lastState = currentState; // Updates the last known state to the current state
}
