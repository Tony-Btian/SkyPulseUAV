#include <pigpio.h>
#include <iostream>
#include <string>

#include "TCP.h"

TCP::TCP(string host, in_port_t port) : 
    host(host),
    port(port), 
    s{0},
    sret{0}
{

    sockpp::initialize();

    connect(10s);

    waitForConnection(10s);

    cout << "Created a connection from " << conn.address() << endl;

}

void TCP::connect(seconds timeout) 
{

    if (auto res = conn.connect(host, port, timeout); !res) {
        cerr << "Error connecting to server at: '" << host << "':\n\t" << res.error_message()
            << endl;
    }
}

void TCP::waitForConnection(seconds timeout) 
{

    if (auto res = conn.read_timeout(timeout); !res) {
        cerr << "Error setting timeout on TCP stream: " << res.error_message() << endl;
    }
}

bool TCP::write(string message_sent) 
{

    auto sendStringLenght = message_sent.length();

    auto res = conn.write(message_sent);

    if (res != sendStringLenght) {
        
        cerr << "Error writing to the TCP stream: " << res.error_message() << endl;

        return false;
    }

    return true;
}

bool TCP::read() 
{

    if (sret.size() != receiveStringLength) {

        sret.resize(receiveStringLength);

    }

    auto res = conn.read_n(&sret[0], receiveStringLength); 

    if (res != receiveStringLength) {

        cerr << "Error reading from TCP stream: " << res.error_message() << endl;

        return false;
    }

    return true;
}

void TCP::readDataFromFilter(float roll, float pitch, float yaw, float rate[3]) 
{

    this -> roll = roll;
    this -> pitch = pitch;
    this -> yaw = yaw;

    for (short i = 0; i < 3; i++) {

        this -> rate[i] = rate[i];

    }
    
}

void TCP::readDataFromBMP180(float altitude) 
{

    this -> alt = altitude;

}

void TCP::readDataFromMotor(float Motor[4]) 
{



}

void TCP::readDataFromIR(uint8_t IRObstacleDetected) 
{

    this->IRObstacleDetected = IRObstacleDetected;

}

void TCP::readDataFromUS(int USDistance) 
{

    this->USDistance = USDistance;

}

// Set callback function to control thread.
void TCP::setCallback(CallbackFunction callback)
{

    callback_ = callback;

}

string TCP::mergeData()
{
     // Flags
    ss << "isMannedMode: " << isMannedMode << ", isInTheAir: " << isInTheAir << "\n";

    // Eular angles data
    ss << "roll: " << roll << ", pitch: " << pitch << ", yaw: " << yaw << "\n";

    // Throttle data
    ss << "throttle: " << thro << "\n";

    // Gyroscope rate data
    ss << "gyroscope rate: " << rate[0] << ", " << rate[1] << ", " << rate[2] << "\n";

    // Altitude data
    ss << "altitude: " << alt << "\n";

    // Motor data
    ss << "motor: " << Motor[0] << ", " << Motor[1] << ", " << Motor[2] << ", " << Motor[3] << "\n";

    // IR distance
    ss << "IR detected: " << IRObstacleDetected << "\n";

    // Ultrasound distance
    ss << "Ultrasound distance: " << USDistance << "\n";

    return ss.str();
    
}

