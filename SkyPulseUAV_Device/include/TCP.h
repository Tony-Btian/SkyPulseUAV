#ifndef __TCP_H__
#define __TCP_H__

#include <sstream>

// Head file of Sockpp library -> https://github.com/fpagliughi/sockpp.git
#include "sockpp/tcp_connector.h"
#include "sockpp/version.h"
#include "CppThread.hpp"
#include "MahonyFilter.h"
#include "BMP180.h"
#include "STM32.h"
#include "IRAndUS.h"

using namespace std;
using namespace std::chrono;

class TCP 
{

public:

    TCP(string host, in_port_t port);

    bool write(string message_sent);

    bool read();

    void readDataFromFilter(float roll, float pitch, float yaw, float rate[3]);

    void readDataFromBMP180(float altitude);

    void readDataFromMotor(float Motor[4]);

    void readDataFromIR(uint8_t IRObstacleDetected);

    void readDataFromUS(int USDistance);

    // Merge all the data and flags into a string.
    string mergeData();

protected:

    void connect(seconds timeout);

    void waitForConnection(seconds timeout);

private:

    // TCP basic variables.
    string s, sret;

    // Middle variables.
    stringstream ss;

    string host;
    in_port_t port;

    sockpp::tcp_connector conn;

    size_t receiveStringLength;

    // Flags.
    bool isMannedMode;
    bool isInTheAir;

    // Get from other classes.

    // Eular angles data.
    float roll;
    float pitch; 
    float yaw;

    // Throttle data.
    float thro;

    // Gyroscope rate date.
    float rate[3];

    // Altitude data.
    float alt;

    // Motor data
    float Motor[4];

    // IR distance.
    uint8_t IRObstacleDetected;

    // Ultrasound distance.
    int USDistance;

};

class TCPThread : public CppThread 
{

public:

    TCPThread(MahonyFilter& MahonyFilterIns_, TCP& TCPIns_, BMP180& BMP180Ins_, STM32& STM32Ins_, 
    IRSensor& IRSensorIns_, USSensor& USSensorIns_) : 

    MahonyFilterIns(MahonyFilterIns_),
    TCPIns(TCPIns_),
    BMP180Ins(BMP180Ins_),
    STM32Ins(STM32Ins_),
    IRSensorIns(IRSensorIns_),
    USSensorIns(USSensorIns_) {};

protected:

    void run() override;

private:

    MahonyFilter& MahonyFilterIns;
    TCP& TCPIns;
    BMP180& BMP180Ins;
    STM32& STM32Ins;
    IRSensor& IRSensorIns;
    USSensor& USSensorIns;

};


#endif