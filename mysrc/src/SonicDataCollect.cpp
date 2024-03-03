#include <iostream>
#include <pigpio.h>
#include <thread>

#include "SonicDataCollect.hpp"

std::atomic<bool> srf05_ready(false);
std::atomic<float> distance(0.0f);

std::atomic<int> raisingEdgeTime(0);
std::atomic<int> fallingEdgeTime(0);

void UltraSonicCollectionThread :: run() {

	bool needToExit = false;
	int duration;

	// Set GPIO and register GPIO callback.
	initializeOfGPIO(&needToExit);
	if (needToExit) { return; }
	else { std::cout << "GPIO initialized successfully." << std::endl; }

	while (1) {

		if (srf05_ready.load()) {

			duration = fallingEdgeTime.load() - raisingEdgeTime.load();
			distance.store(duration / 58.0f);
			srf05_ready.store(false);

		}
	}
}
