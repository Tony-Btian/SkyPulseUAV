#include <pigpio.h>
#include <iostream>

#include "Motor.h"

Motor::Motor() {

    gpioSetPWMfrequency(MOTOR1_PIN, MOTOR_FREQ);
    gpioSetPWMfrequency(MOTOR2_PIN, MOTOR_FREQ);
    gpioSetPWMfrequency(MOTOR3_PIN, MOTOR_FREQ);
    gpioSetPWMfrequency(MOTOR4_PIN, MOTOR_FREQ);

    gpioSetPWMrange(MOTOR1_PIN, MOTOR_RANGE);
    gpioSetPWMrange(MOTOR2_PIN, MOTOR_RANGE);
    gpioSetPWMrange(MOTOR3_PIN, MOTOR_RANGE);
    gpioSetPWMrange(MOTOR4_PIN, MOTOR_RANGE);

    gpioPWM(MOTOR1_PIN, MOTOR_HALF_RANGE);
    gpioPWM(MOTOR2_PIN, MOTOR_HALF_RANGE);
    gpioPWM(MOTOR3_PIN, MOTOR_HALF_RANGE);
    gpioPWM(MOTOR4_PIN, MOTOR_HALF_RANGE);

}

void Motor::updateMotor(int rateRequired[4]) {

    for(int i = 0; i < 4; i ++) {

        if (motorDutyCycle[i] < MOTOR_RANGE) {

            motorDutyCycle[i] = rateRequired[i];
            beyondRange[i] = 0;
        }

        else {

            motorDutyCycle[i] = MOTOR_RANGE;
            beyondRange[i] = 1;

        }

    }

    gpioPWM(MOTOR1_PIN, motorDutyCycle[0]);
    gpioPWM(MOTOR2_PIN, motorDutyCycle[1]);
    gpioPWM(MOTOR3_PIN, motorDutyCycle[2]);
    gpioPWM(MOTOR4_PIN, motorDutyCycle[3]);  

}