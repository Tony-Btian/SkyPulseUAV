#include <iostream>
#include <thread>
#include <pigpio.h>
#include <chrono>

#include "BaroDataCollect.hpp"

std::atomic<float> altitude(0.0f);

void BaroDataCollectionThread::run() {

	int handle;
	
	bool needToExit = false;  // flag of error.

	// initializeBaro(&handle, &needToExit);
	// if (needToExit) { return; }
	// else { std::cout << "Initialization of BMP180 successfully." << std::endl; }

	//std::cout << "Successful!" << std::endl;

	//char EEPROMData[22]{};
	//baroReadEEPROM(handle, EEPROMData, &needToExit);

	//short ac1 = (EEPROMData[0] << 8) | EEPROMData[1];
	//short ac2 = (EEPROMData[2] << 8) | EEPROMData[3];
	//short ac3 = (EEPROMData[4] << 8) | EEPROMData[5];
	//unsigned short ac4 = (EEPROMData[6] << 8) | EEPROMData[7];
	//unsigned short ac5 = (EEPROMData[8] << 8) | EEPROMData[9];
	//unsigned short ac6 = (EEPROMData[10] << 8) | EEPROMData[11];
	//short b1 = (EEPROMData[12] << 8) | EEPROMData[13];
	//short b2 = (EEPROMData[14] << 8) | EEPROMData[15];
	//short mb = (EEPROMData[16] << 8) | EEPROMData[17];
	//short mc = (EEPROMData[18] << 8) | EEPROMData[19];
	//short md = (EEPROMData[20] << 8) | EEPROMData[21];


	long p;
	float t;
	//double realAlti;
	float sealevelPressure;

	// Calibration of sealevel pressure p0.
	baroReadTempAndPres(handle, &t, &p, &needToExit);

	sealevelPresCorrect(&sealevelPressure, p);

	for(;;) {

		baroReadTempAndPres(handle, &t, &p, &needToExit); // Approximately takes at least 6ms to finish.

		baroGetAbsAlti(handle, p, sealevelPressure, &needToExit);

		std::cout << "Altitude:" << altitude.load() << std::endl;
		
		std::this_thread::sleep_for(std::chrono::microseconds(static_cast < long long>(1000)));

	}



	return;
}