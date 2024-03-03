#ifndef __ULTRASONICTHREAD__
#define __ULTRASONICTHREAD__

#include "CppThread.hpp"
#include "sensor_data.hpp"

// Define pins of ultrasonic sensor.
#define ULTRASONIC_EMIT_PIN 25 
#define ULTRASONIC_RECIEVE_PIN 26

class UltraSonicCollectionThread : public CppThread {
public:

private:
	void run();

protected:
};

void initializeOfGPIO(bool* needToExit);

void emitUltraSonic(void);

void receiveCallback(int gpio, int level, uint32_t tick);

#endif