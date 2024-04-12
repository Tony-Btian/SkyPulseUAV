#ifndef ESC_PWM_DRIVER_H
#define ESC_PWM_DRIVER_H

#include "observer.h" // Include the Observer pattern interface
#include <QObject> // Base class for Qt objects

// Define GPIO pins for PWM signals
#define PWM0 12 
#define PWM1 13 
#define PWM2 19 
#define PWM3 18 

/**
 * @file esc_pwm_driver.h
 * @brief ESC PWM driver class definition.
 */

class ESC_PWM_Driver : public QObject, public Observer
{
    Q_OBJECT // Required for using Qt's signal and slot mechanism

public:
    
    ESC_PWM_Driver(QObject *parent = nullptr); // Constructor with optional parent QObject
    void onUpdate(bool isInitialised) override; // Observer pattern update method

public slots:
    void setPWMSignal(int gpioPin, int dutyCycle); // Slot to set PWM duty cycle on a GPIO pin

private:
    void initialPWM(); // Initializes PWM settings for ESC control

};

#endif // ESC_PWM_DRIVER_H

