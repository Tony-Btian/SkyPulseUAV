#include <pigpio.h>
#include <iostream>
#include <math.h> 
#include <cmath>
#include <chrono>

#include "SonicDataCollect.hpp"

void initializeOfGPIO(bool* needToExit) {

	if (gpioInitialise() < 0) {
		std::cerr << "GPIO initialization failed." << std::endl;
		*needToExit = true;
		return;
	}

	gpioSetMode(ULTRASONIC_EMIT_PIN, PI_OUTPUT);
	gpioSetMode(ULTRASONIC_RECIEVE_PIN, PI_INPUT);

	// Register GPIO callback to detect signal back from SRF05.
	gpioSetAlertFunc(ULTRASONIC_RECIEVE_PIN, receiveCallback);

	// Register timer callback to emit enable signal to SRF05.
	gpioSetTimerFunc(0, 50, emitUltraSonic);

}

void emitUltraSonic(void) {

	// Send a trigger signal to SRF05, width = 1ms.
	gpioTrigger(ULTRASONIC_EMIT_PIN, 1, 1);

}

void receiveCallback(int gpio, int level, uint32_t tick) {

	if (level == 1) {
		raisingEdgeTime.store(tick & 0x7FFF);
	}
	if (level == 0) {
		fallingEdgeTime.store(tick & 0x7FFF);
		srf05_ready.store(true);
	}
}