#include <iostream>
#include <pigpio.h>
#include <thread>

#include "SonicDataCollect.hpp"

std::atomic<bool> srf05_ready(false);
std::atomic<float> distance(0.0f);

std::atomic<uint32_t> risingEdgeTime(0);
std::atomic<uint32_t> fallingEdgeTime(0);

void UltraSonicCollectionThread :: run() {

	bool needToExit = false;
	int duration;

	// Set GPIO and register GPIO callback.
	initializeSRF05(&needToExit);
	if (needToExit) { return; }
	else { std::cout << "Ultarsonic GPIO initialized successfully." << std::endl; }

	for(;;) {
		
		int holdtime = 1; // microsecond
    	std::chrono::seconds microsec(holdtime);
		emitUltraSonic();
		//std::cout << "Trigger!" << std::endl;
		std::this_thread::sleep_for(microsec);

		// if (srf05_ready.load()) {

		// 	srf05_ready.store(false);
		// 	duration = fallingEdgeTime.load() - risingEdgeTime.load();
		// 	if(duration > 0){
		// 		distance.store(duration / 58.0f);
		// 	}		
			//std::cout << distance.load() << std::endl;

		//}
	}
}
