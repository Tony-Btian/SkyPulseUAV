#ifndef __TCP_H__
#define __TCP_H__

// Head file of Sockpp library -> https://github.com/fpagliughi/sockpp.git
#include "sockpp/tcp_connector.h"
#include "sockpp/version.h"
#include "CppThread.hpp"
#include "MahonyFilter.h"
#include "BMP180.h"

using namespace std;
using namespace std::chrono;

class TCP {

public:

    TCP(string host, in_port_t port);

    bool write(string message_sent);

    bool read();

    void readDataFromFilter(float roll, float pitch, float yaw, float rate[3]);

    void readDataFromBMP180(float altitude);

    void readDataFromMotor(float Motor[4]);

    // Merge all the data and flags into a string.
    string mergeData();

protected:

    void connect(seconds timeout);

    void waitForConnection(seconds timeout);

private:

    // TCP basic variables.
    string s, sret;

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
    float IRDistance[3];

    // Ultrasound distance.
    float USDistance;

    // Battery status.
    float vol;
    float cur;


};

class TCPThread : public CppThread {

public:

    TCPThread(MahonyFilter& MahonyFilterIns_, TCP& TCPIns_, BMP180& BMP180Ins_) : 
    MahonyFilterIns(MahonyFilterIns_),
    TCPIns(TCPIns_),
    BMP180Ins(BMP180Ins_) {};

protected:

    void run() override;

private:

    MahonyFilter& MahonyFilterIns;
    TCP& TCPIns;
    BMP180& BMP180Ins;

};


#endif