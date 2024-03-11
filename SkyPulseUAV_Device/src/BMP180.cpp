#include <pigpio.h>
#include <iostream>
#include <cmath>
#include <thread>

#include "../include/BMP180.h"


BMP180::BMP180() : BMP180(MY_ALTITUDE){}

BMP180::BMP180(float loaclAltitude) : 
    iicBMP180(BMP180_ADDRESS),
    droneAltitude(0.0f) {

    myLocalAltitude = loaclAltitude;
	
    BMP180ReadTempAndPres();

    sealevelPresCorrect(myLocalAltitude);

    std::cout << "BMP 180 calibrating successfully!" << std::endl;
    
}

void BMP180::BMP180ReadEEPROM(char* eeprom) {

    char eepromAddr = 0xAA;
    iicBMP180.read(eeprom, 22, eepromAddr);

}

void BMP180::sealevelPresCorrect(float sealevelPressure) {
    
    sealevelPressure = p / std::pow((1.0 - (myLocalAltitude / 44330.0)), 5.255);

}

float BMP180::getData() {

    BMP180ReadTempAndPres();
    
    droneAltitude.store(44330.0 * (1.0 - std::pow((p / sealevelPressure), 1.0f / 5.255f)));

	return droneAltitude.load();

}

void BMP180::BMP180ReadTempAndPres() {

    char err;
	char regAddr = 0xF6;  // Multiplex reg for both temperature and pressure.
	char rawTemp[2]{}; // Raw temperature data.
	char rawPres[2]{}; // Raw preesure data.
	char EEPROMData[22]{}; // Calibration data.
	int dataSize = 2;
	
    char selectTempReg[2] = {0xF4, 0x2E};
    iicBMP180.write(selectTempReg, 2);

	// {
	// 	std::lock_guard<std::mutex> lock(i2cmtx);

	// 	// Wake temperature reg up.
	// 	if ((err = i2cWriteByteData(handle, 0xF4, 0x2E) != 0)) {
	// 		std::cout << "Can't write start data to temperature reg, error code：" << err << std::endl;
	// 		i2cClose(handle);
	// 		gpioTerminate();
	// 		*needToExit = true;
	// 		return;
	// 	}
	// }

	std::this_thread::sleep_for(std::chrono::microseconds(static_cast < long long>(5000)));

    iicBMP180.read(rawTemp, dataSize, regAddr);
	// {
	// 	std::lock_guard<std::mutex> lock(i2cmtx);

	// 	// Read raw temperature data.
	// 	if ((err = i2cWriteByte(handle, regAddr)) != 0) {
	// 		std::cout << "Can't write address to temperature reg, error code：" << err << std::endl;
	// 		i2cClose(handle);
	// 		gpioTerminate();
	// 		*needToExit = true;
	// 		return;
	// 	}

	// 	if ((err = i2cReadDevice(handle, &rawTemp[0], dataSize)) <= 0) {
	// 		std::cout << "Can't read temperature reg, error code：" << err << std::endl;
	// 		i2cClose(handle);
	// 		gpioTerminate();
	// 		*needToExit = true;
	// 		return;
	// 	}
	// }

	long ut = (rawTemp[0] << 8) | rawTemp[1];

    char selectPresReg[2] = {0xF4, 0x34};
    iicBMP180.write(selectPresReg, 2);

	// {
	// 	std::lock_guard<std::mutex> lock(i2cmtx);

	// 	// Switch to preesure data here.
	// 	if ((err = i2cWriteByteData(handle, 0xF4, 0x34) != 0)) {
	// 		std::cout << "Can't write start data to preesure reg, error code：" << err << std::endl;
	// 		i2cClose(handle);
	// 		gpioTerminate();
	// 		*needToExit = true;
	// 		return;
	// 	}
	// }

	std::this_thread::sleep_for(std::chrono::microseconds(static_cast < long long>(5000)));

    iicBMP180.read(rawPres, dataSize, regAddr);

	// {
	// 	std::lock_guard<std::mutex> lock(i2cmtx);

	// 	// Read raw pressure data.
	// 	if ((err = i2cWriteByte(handle, regAddr)) != 0) {
	// 		std::cout << "Can't write address to temperature reg, error code：" << err << std::endl;
	// 		i2cClose(handle);
	// 		gpioTerminate();
	// 		*needToExit = true;
	// 		return;
	// 	}

	// 	if ((err = i2cReadDevice(handle, &rawPres[0], dataSize)) <= 0) {
	// 		std::cout << "Can't read temperature reg, error code：" << err << std::endl;
	// 		i2cClose(handle);
	// 		gpioTerminate();
	// 		*needToExit = true;
	// 		return;
	// 	}
	// }

	long up = (rawPres[0] << 8) | rawPres[1];

	// Get calibration data.
	BMP180ReadEEPROM(EEPROMData);

	short ac1 = (EEPROMData[0] << 8) | EEPROMData[1];
	short ac2 = (EEPROMData[2] << 8) | EEPROMData[3];
	short ac3 = (EEPROMData[4] << 8) | EEPROMData[5];
	unsigned short ac4 = (EEPROMData[6] << 8) | EEPROMData[7];
	unsigned short ac5 = (EEPROMData[8] << 8) | EEPROMData[9];
	unsigned short ac6 = (EEPROMData[10] << 8) | EEPROMData[11];
	short b1 = (EEPROMData[12] << 8) | EEPROMData[13];
	short b2 = (EEPROMData[14] << 8) | EEPROMData[15];
	short mb = (EEPROMData[16] << 8) | EEPROMData[17];
	short mc = (EEPROMData[18] << 8) | EEPROMData[19];
	short md = (EEPROMData[20] << 8) | EEPROMData[21];

	// Calculate REAL pressure.
	long x1, x2, b5, x3, b3, b6, b7;
	unsigned long b4;

	x1 = (ut - ac6) * ac5 >> 15;
	x2 = (mc << 11) / (x1 + md);
	b5 = x1 + x2;
	t = ((b5 + 8) >> 4) / 10.0;

	b6 = b5 - 4000;
	x1 = (b2 * (b6 * b6) >> 12) >> 11;
	x2 = (ac2 * b6) >> 11;
	x3 = x1 + x2;
	b3 = ((ac1 * 4 + x3) + 2) / 4;
	x1 = (ac3 * b6) >> 13;
	x2 = (b1 * ((b6 * b6) >> 12)) >> 16;
	x3 = ((x1 + x2) + 2) >> 2;
	b4 = ac4 * (unsigned long)(x3 + 32768) >> 15;
	b7 = ((unsigned long)up - b3) * 50000;
	if (b7 < 0x80000000) {
		p = (b7 * 2) / b4;
	}
	else {
		p = (b7 / b4) * 2;
	}
	x1 = (p >> 8) * (p >> 8); 
	x1 = (x1 * 3038)  >> 16;
	x2 = (-7357 * p) >> 16;
	p = p + ((x1 + x2 + 3791) >> 4);

}

