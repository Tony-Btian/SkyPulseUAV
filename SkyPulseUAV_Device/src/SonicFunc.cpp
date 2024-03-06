#include <iostream>
#include <math.h> 
#include <cmath>
#include <chrono>
// #include <pigpio.h>

// #include "SonicDataCollect.hpp"
#include "../include/SonicDataCollect.hpp"
#include "../include/pigpio.h"

void initializeSRF05(bool* needToExit) {

	gpioSetMode(ULTRASONIC_EMIT_PIN, PI_OUTPUT);
	gpioSetMode(ULTRASONIC_RECIEVE_PIN, PI_INPUT);

	// Register GPIO callback to detect signal back from SRF05.
	gpioSetAlertFunc(ULTRASONIC_RECIEVE_PIN, receiveCallback);
	//std::cout << "Alert set." << std::endl;

	// Register timer callback to emit enable signal to SRF05.
	// gpioSetTimerFunc(0, 5000, emitUltraSonic);
	// std::cout << "Timer set." << std::endl;

}

void emitUltraSonic(void) {
	srf05_ready.store(false);
	int microseconds = 15;
    std::chrono::microseconds microsec(microseconds);
	// Send a trigger signal to SRF05, width = 12us.
	//gpioTrigger(ULTRASONIC_EMIT_PIN, 15, 1);
	gpioWrite(ULTRASONIC_EMIT_PIN, 1);
	std::this_thread::sleep_for(microsec);
	gpioWrite(ULTRASONIC_EMIT_PIN, 0);
}

void receiveCallback(int gpio, int level, uint32_t tick) {

	uint32_t duration;

	if (level == 1) {
		risingEdgeTime.store(tick & 0xFFFF);
	}

	if (level == 0) {
		fallingEdgeTime.store(tick & 0xFFFF);
		duration = fallingEdgeTime.load() - risingEdgeTime.load(); 
		srf05_ready.store(true);
		//std::cout << "distance" << duration << std::endl;
	}
}