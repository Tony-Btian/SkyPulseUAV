#include "esc_pwm_driver.h"
#include <pigpio.h>
#include <QDebug>

ESC_PWM_Driver::ESC_PWM_Driver(QObject *parent){}
// Constructor is currently empty and only calls the base class constructor

void ESC_PWM_Driver::onUpdate(bool isInitialised)
{
    qDebug() << "PWM Driver Working!"; // Log that the PWM driver is operational
    if(isInitialised){
        qWarning("SensorManager: PWM GPIO initialized."); // Warn that PWM GPIO is already initialized
    }
    else if (gpioInitialise() < 0) {
        qWarning("PWM: Failed to initialize pigpio library"); // Warn on pigpio library initialization failure
    }
    initialPWM(); // Call to initialize PWM settings
}

void ESC_PWM_Driver::initialPWM()
{
    // Set GPIO pins to output mode for PWM signals
    gpioSetMode(PWM0, PI_OUTPUT); 
    gpioSetMode(PWM1, PI_OUTPUT);
    gpioSetMode(PWM2, PI_OUTPUT);
    gpioSetMode(PWM3, PI_OUTPUT);

    // Set PWM frequency to 100 Hz for all GPIO pins
    gpioSetPWMfrequency(PWM0, 100);
    gpioSetPWMfrequency(PWM1, 100);
    gpioSetPWMfrequency(PWM2, 100);
    gpioSetPWMfrequency(PWM3, 100);
}

void ESC_PWM_Driver::setPWMSignal(int gpioPin, int dutyCycle)
{
    // Check the legitimacy of parameters, e.g. dutyCycle is usually in the range 0 to 255
    if((dutyCycle < 0) || (dutyCycle > 255)) { 
        qWarning("Invalid duty cycle"); // Warn about invalid duty cycle value
        return; // Exit if duty cycle is not in the valid range
    }
    qDebug() << "Gpio Pin: " << gpioPin << "," << "Duty cycle: " << dutyCycle; // Log the GPIO pin and duty cycle being set
    gpioPWM(gpioPin, dutyCycle); // Set the PWM duty cycle for the specified GPIO pin
}

