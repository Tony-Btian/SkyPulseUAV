#include <iostream>
#include <mutex>

#include "../include/pigpio.h"
#include "../include/MPU6050.h"

MPU6050* MPU6050::globalInstance = nullptr;
// std::atomic<bool> mpu6050_newdata(false);

MPU6050 :: MPU6050() : MPU6050(200, CALIBRATION_COUNT) {};

MPU6050 :: MPU6050(int customSampleRate, int calibrationTimes) :
	ax(0.0f),
	ay(0.0f),
	az(0.0f),
	gx(0.0f),
	gy(0.0f),
	gz(0.0f),
	mx(0.0f),
	my(0.0f),
	mz(0.0f)
 {

	offset_count = 0;
	needToExit = false;
	handle = 0;
	calibrationCount = calibrationTimes;
	globalInstance = this;

	MPU6050RawData[14] = {};
	GY271RawData[6] = {};

	calibrate_ready.store(false);
	mpu6050_newdata.store(false);

	// 1000/sample_rate_int if DLPF is enabled.
    sampleRate = (1000 / customSampleRate) - 1; 
    std::cout << "Sample rate has been set to " << customSampleRate << std::endl;

    {
		std::lock_guard<std::mutex> lock(i2cmtx);
		handle = i2cOpen(IIC_BUS, MPU6050_ADDRESS, 0);  //sudo i2cdetect -y 1 to check addr
	}

		if (handle < 0) {
			std::cout << "I2C is not enabled!" << std::endl;
			gpioTerminate();
			needToExit = true;
			return;
	}

    // Wake MPU6050 up.
	char dataString[2] = {0x6B, 0};
	{
		std::lock_guard<std::mutex> lock(i2cmtx);
		if (i2cWriteDevice(handle, dataString, sizeof(dataString)) != 0) {
			std::cout << "Can't wake MPU6050 up!" << std::endl;
			i2cClose(handle);
			gpioTerminate();
			needToExit = true;
			return;
		}
	}
	
    // Real sample rate = 1000 / (1+ sampleRate ).
	char setSampleRate[2] = { 0x19, sampleRate };  
	{
		std::lock_guard<std::mutex> lock(i2cmtx);
		if (i2cWriteDevice(handle, setSampleRate, sizeof(setSampleRate)) != 0) {
			std::cout << "Can't set sample rate!" << std::endl;
			i2cClose(handle);
			gpioTerminate();
			needToExit = true;
			return;
		}
	}

	// Enable interrupt.
	char enableInt[2] = { 0x38, 0x01 };
	{
		std::lock_guard<std::mutex> lock(i2cmtx);
		if (i2cWriteDevice(handle, enableInt, sizeof(enableInt)) != 0) {
			std::cout << "Can't enable interrupt!!" << std::endl;
			i2cClose(handle);
			gpioTerminate();
			needToExit = true;
			return;
		}
	}
    
    // Set DLPF.
	char setDLPF[2] = {0x1A, 0x03};
	{
		std::lock_guard<std::mutex> lock(i2cmtx);
		if (i2cWriteDevice(handle, setDLPF, sizeof(setDLPF)) != 0) {
			std::cout << "Can't set LPF." << std::endl;
			i2cClose(handle);
			gpioTerminate();
			needToExit = true;
			return;
		}
	}

    // set full scale range of accelerometer to +-2g
	setRangeOfAcce(needToExit);
	if (needToExit) { return; }
	else { std::cout << "Scale range of accelerometer: +-2g." << std::endl; }

	// set full scale range of Gyroscope to +- 2000 °/s
	setRangeOfGyro(needToExit);
	if (needToExit) { return; }
	else { std::cout << "Scale range of gyroscope: +- 2000°/s." << std::endl; }
}

void MPU6050 :: checkNewData(bool newDataReady) {

	newDataReady = mpu6050_newdata.load();

}

void MPU6050 :: MPU6050ReadData(char* data) {

	char MPU6050StartAddr = 0x3B;
    {
		std::lock_guard<std::mutex> lock(i2cmtx);
		
		if (i2cWriteByte(handle, MPU6050StartAddr) != 0) {
			if(i2cWriteByte(handle, MPU6050StartAddr)!= 0) {
				std::cout << "Can't get data of accelerometer." << std::endl;
				i2cClose(handle);
				gpioTerminate();
			}
		}

		if (i2cReadDevice(handle, data, 14) <= 0) {
			std::cout << "Can't read data from accelerometer" << std::endl;
			i2cClose(handle);
			gpioTerminate();
			//return;
		}
	}
}

void MPU6050 :: GY271ReadData(char* data) {

	char GY271StartAddr = 0x00;

    {
		std::lock_guard<std::mutex> lock(i2cmtx);
		if (i2cWriteByte(handle, GY271StartAddr) != 0) {
			std::cout << "Can't write address to magnet sensor." << std::endl;
			i2cClose(handle);
			gpioTerminate();
			return;
		}

		if (i2cReadDevice(handle, data, 6) <= 0) {
			std::cout << "Can't read data from magnet sensor" << std::endl;
			i2cClose(handle);
			gpioTerminate();
			return;
		}
	}
}

void MPU6050 :: setRangeOfAcce(bool needToExit) {

    char  dataAcce[2] = {0x1C, 0 << 3 };

	{
		std::lock_guard<std::mutex> lock(i2cmtx);

		if (i2cWriteDevice(handle, dataAcce, sizeof(dataAcce)) != 0) {
			std::cout << "Can't set full scale range of accelerometer to +-2g" << std::endl;
			i2cClose(handle);
			gpioTerminate();
			needToExit = true;
			return;
		}
	}
}

void MPU6050 :: setRangeOfGyro(bool needToExit) {

    char  dataGyro[2] = {0x1B, 0x18};

	{
		std::lock_guard<std::mutex> lock(i2cmtx);

		if (i2cWriteDevice(handle, dataGyro, sizeof(dataGyro)) != 0) {
			std::cout << "Can't set full scale range of Gyroscope to +-2g" << std::endl;
			i2cClose(handle);
			gpioTerminate();
			needToExit = true;
			return;
		}
	}
}

void MPU6050 :: getData(float a[3], float g[3], float m[3]) {

	if(!calibrate_ready.load()) {

		calibrateData();

	}

	else {

		a[0] = ((ax.load() - a_offset[0]) / 16384.0f)*9.818f;
		a[1] = ((ay.load() - a_offset[1]) / 16384.0f)*9.818f;
		a[2] = ((az.load() - a_offset[2]) / 16384.0f)*9.818f;
		a[2] = a[2] + 9.818f;

		g[0] = (gx.load() - g_offset[0]) / (16.384f) * DEG_TO_RAD;
		g[1] = (gy.load() - g_offset[1]) / (16.384f) * DEG_TO_RAD;
		g[2] = (gz.load() - g_offset[2]) / (16.384f) * DEG_TO_RAD;

		m[0] = (mx.load() - m_offset[0]) * 0.000122f;
		m[1] = (my.load() - m_offset[1]) * 0.000122f;
		m[2] = (mz.load() - m_offset[2]) * 0.000122f;
	}
	
}

void MPU6050 :: calibrateData() {

	g_offset[0] += gx.load();
	g_offset[1] += gy.load();
	g_offset[2] += gz.load();

	a_offset[0] += ax.load();
	a_offset[1] += ay.load();
	a_offset[2] += az.load();

	m_offset[0] += mx.load();
	m_offset[1] += my.load();
	m_offset[2] += mz.load();

	offset_count++;

	if (offset_count > CALIBRATION_COUNT) {
		g_offset[0] = g_offset[0] / offset_count;
		g_offset[1] = g_offset[1] / offset_count;
		g_offset[2] = g_offset[2] / offset_count;

		a_offset[0] = a_offset[0] / offset_count;
		a_offset[1] = a_offset[1] / offset_count;
		a_offset[2] = a_offset[2] / offset_count;

		m_offset[0] = m_offset[0] / offset_count;
		m_offset[1] = m_offset[1] / offset_count;
		m_offset[2] = m_offset[2] / offset_count;
		// a_offset[2] -= 9.81f; // 去除重力加速度常量

		offset_count = 0;

		calibrate_ready.store(true);
	}
}

void interruptHandler(int GPIO, int level, unsigned int tick) {

	MPU6050::globalInstance -> MPU6050ReadData(&MPU6050::globalInstance -> MPU6050RawData[0]);
	MPU6050::globalInstance -> GY271ReadData(&MPU6050::globalInstance -> GY271RawData[0]);

	// ax = (float)((MPU6050RawData[0] << 8) | MPU6050RawData[1]);
	// ay = (float)((MPU6050RawData[2] << 8) | MPU6050RawData[3]);
	// az = (float)((MPU6050RawData[4] << 8) | MPU6050RawData[5]);
	// gx = (float)((MPU6050RawData[8] << 8) | MPU6050RawData[9]);
	// gy = (float)((MPU6050RawData[10] << 8) | MPU6050RawData[11]);
	// gz = (float)((MPU6050RawData[12] << 8) | MPU6050RawData[13]);
	// mx = (float)((GY271RawData[0] << 8) | GY271RawData[1]);
	// my = (float)((GY271RawData[2] << 8) | GY271RawData[3]);
	// mz = (float)((GY271RawData[4] << 8) | GY271RawData[5]);

	short tempax, tempay, tempaz, tempgx, tempgy, tempgz, tempmx, tempmy, tempmz;

	tempax = ((MPU6050::globalInstance -> MPU6050RawData[0] << 8) | MPU6050::globalInstance -> MPU6050RawData[1]);
	tempay = ((MPU6050::globalInstance -> MPU6050RawData[2] << 8) | MPU6050::globalInstance -> MPU6050RawData[3]);
	tempaz = ((MPU6050::globalInstance -> MPU6050RawData[4] << 8) | MPU6050::globalInstance -> MPU6050RawData[5]);
	tempgx = ((MPU6050::globalInstance -> MPU6050RawData[8] << 8) | MPU6050::globalInstance -> MPU6050RawData[9]);
	tempgy = ((MPU6050::globalInstance -> MPU6050RawData[10] << 8) | MPU6050::globalInstance -> MPU6050RawData[11]);
	tempgz = ((MPU6050::globalInstance -> MPU6050RawData[12] << 8) | MPU6050::globalInstance -> MPU6050RawData[13]);
	tempmx = ((MPU6050::globalInstance -> GY271RawData[0] << 8) | MPU6050::globalInstance -> GY271RawData[1]);
	tempmy = ((MPU6050::globalInstance -> GY271RawData[2] << 8) | MPU6050::globalInstance -> GY271RawData[3]);
	tempmz = ((MPU6050::globalInstance -> GY271RawData[4] << 8) | MPU6050::globalInstance -> GY271RawData[5]);
	MPU6050::globalInstance -> ax.store(tempax);
	MPU6050::globalInstance -> ay.store(tempay);
	MPU6050::globalInstance -> az.store(tempaz);
	MPU6050::globalInstance -> gx.store(tempgx);
	MPU6050::globalInstance -> gy.store(tempgy);
    MPU6050::globalInstance -> gz.store(tempgz);
    MPU6050::globalInstance -> mx.store(tempmx);
    MPU6050::globalInstance -> my.store(tempmy);
    MPU6050::globalInstance -> mz.store(tempmz);

	MPU6050::globalInstance -> mpu6050_newdata.store(true);
}

// Trigger interrupt to read data from MPu6050.
void initializeMPUISR(bool* needToExit) {
    
    gpioSetMode(INT_PIN, PI_INPUT);

	if (gpioSetISRFunc(INT_PIN, RISING_EDGE, 0, interruptHandler) != 0) {
		std::cout << "mpu6050 int failed." << std::endl;
		*needToExit = true;
		return;
	}
}