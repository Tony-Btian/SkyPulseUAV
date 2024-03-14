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

    const size_t sendStringLenght = s.length();

    if (auto res = conn.write(message_sent); res != sendStringLenght) {
        
        cerr << "Error writing to the TCP stream: " << res.error_message() << endl;

        return 1;
    }

    return 0;
}

bool TCP::read() {

    sret.resize(receiveStringLength);

    if (auto res = conn.read_n(&sret[0], receiveStringLength); res != receiveStringLength) {

        cerr << "Error reading from TCP stream: " << res.error_message() << endl;

        return 1;
    }

    return 0;

}


