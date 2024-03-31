#include "esc_pwm_driver.h"
#include <pigpio.h>
#include <QDebug>

ESC_PWM_Driver::ESC_PWM_Driver(QObject *parent){}

void ESC_PWM_Driver::onUpdate(bool isInitialised)
{
    qDebug() << "PWM Driver Working!";
    if(isInitialised){
        qWarning("SensorManager: PWM GPIO initialized.");
    }
    else if (gpioInitialise() < 0) {
        qWarning("PWM: Failed to initialize pigpio library");
    }
    initialPWM();
}

void ESC_PWM_Driver::initialPWM()
{
    gpioSetMode(PWM0, PI_OUTPUT);
    gpioSetMode(PWM1, PI_OUTPUT);
    gpioSetMode(PWM2, PI_OUTPUT);
    gpioSetMode(PWM3, PI_OUTPUT);
    gpioSetPWMfrequency(PWM0, 100);
    gpioSetPWMfrequency(PWM1, 100);
    gpioSetPWMfrequency(PWM2, 100);
    gpioSetPWMfrequency(PWM3, 100);
}

void ESC_PWM_Driver::setPWM0Signal(const int &dutyCycle)
{
    // Check the legitimacy of parameters, e.g. dutyCycle is usually in the range 0 to 255
    if((dutyCycle < 0) || (dutyCycle > 255)) return;
    gpioPWM(PWM0, dutyCycle);
}

void ESC_PWM_Driver::setPWM1Signal(const int &dutyCycle)
{
    // Check the legitimacy of parameters, e.g. dutyCycle is usually in the range 0 to 255
    if((dutyCycle < 0) || (dutyCycle > 255)) return;
    gpioPWM(PWM1, dutyCycle);
}

void ESC_PWM_Driver::setPWM2Signal(const int &dutyCycle)
{
    // Check the legitimacy of parameters, e.g. dutyCycle is usually in the range 0 to 255
    if((dutyCycle < 0) || (dutyCycle > 255)) return;
    gpioPWM(PWM2, dutyCycle);
}

void ESC_PWM_Driver::setPWM3Signal(const int &dutyCycle)
{
    // Check the legitimacy of parameters, e.g. dutyCycle is usually in the range 0 to 255
    if((dutyCycle < 0) || (dutyCycle > 255)) return;
    gpioPWM(PWM3, dutyCycle);
}
