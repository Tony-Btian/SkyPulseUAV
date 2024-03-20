#include <pigpio.h>
#include <iostream>
#include <string>

#include "TCP.h"

TCP::TCP(string host, in_port_t port) : 
    host(host),
    port(port) {

    sockpp::initialize();

    connect(10s);

    waitForConnection(10s);

    cout << "Created a connection from " << conn.address() << endl;

}

void TCP::connect(seconds timeout) {

    if (auto res = conn.connect(host, port, timeout); !res) {
        cerr << "Error connecting to server at: '" << host << "':\n\t" << res.error_message()
            << endl;
    }
}

void TCP::waitForConnection(seconds timeout) {

    if (auto res = conn.read_timeout(timeout); !res) {
        cerr << "Error setting timeout on TCP stream: " << res.error_message() << endl;
    }
}

bool TCP::write(string message_sent) {

    auto sendStringLenght = message_sent.length();

    auto res = conn.write(message_sent);

    if (res != sendStringLenght) {
        
        cerr << "Error writing to the TCP stream: " << res.error_message() << endl;

        return false;
    }

    return true;
}

bool TCP::read() {

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

void TCP::readDataFromFilter(float roll, float pitch, float yaw) {

    this -> roll = roll;
    this -> pitch = pitch;
    this -> yaw = yaw;
}

void TCP::readDataFromBMP180(float altitude) {

    this -> altitude = altitude;

}



