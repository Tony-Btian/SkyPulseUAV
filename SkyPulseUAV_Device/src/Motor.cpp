#include <pigpio.h>
#include <iostream>

#include "Motor.h"

Motor::Motor() {

    gpioSetPWMfrequency(MOTOR1_PIN, MOTOR_FREQ);
    gpioSetPWMfrequency(MOTOR2_PIN, MOTOR_FREQ);
    gpioSetPWMfrequency(MOTOR3_PIN, MOTOR_FREQ);
    gpioSetPWMfrequency(MOTOR4_PIN, MOTOR_FREQ);

    gpioSetPWMrange(MOTOR1_PIN, 10000);
    gpioSetPWMrange(MOTOR2_PIN, 10000);
    gpioSetPWMrange(MOTOR3_PIN, 10000);
    gpioSetPWMrange(MOTOR4_PIN, 10000);

    gpioPWM(MOTOR1_PIN, 5000);
    gpioPWM(MOTOR2_PIN, 5000);
    gpioPWM(MOTOR3_PIN, 5000);
    gpioPWM(MOTOR4_PIN, 5000);

}

void Motor::setMotorRate() {

    gpioPWM(MOTOR1_PIN, motorDutyCycle[0]);
    gpioPWM(MOTOR2_PIN, motorDutyCycle[1]);
    gpioPWM(MOTOR3_PIN, motorDutyCycle[2]);
    gpioPWM(MOTOR4_PIN, motorDutyCycle[3]);

} 

void Motor::readDutyCycle(int rateRequired[4]) {

    for(int i = 0; i < 4; i ++) {

        motorDutyCycle[i] = rateRequired[i];

    }

}