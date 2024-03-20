#ifndef __TCP_H__
#define __TCP_H__

// Head file of Sockpp library -> https://github.com/fpagliughi/sockpp.git
#include "sockpp/tcp_connector.h"
#include "sockpp/version.h"
#include "CppThread.hpp"
#include "MahonyFilter.h"

using namespace std;
using namespace std::chrono;

class TCP {

public:

    TCP(string host, in_port_t port);

    bool write(string message_sent);

    bool read();

protected:

    void connect(seconds timeout);

    void waitForConnection(seconds timeout);

private:

    string s, sret;

    string host;

    in_port_t port;

    sockpp::tcp_connector conn;

    size_t receiveStringLength;

};

class TCPThread : public CppThread {

public:

    TCPThread(MahonyFilter& MahonyFilterIns_, TCP& TCPIns_) : 
    MahonyFilterIns(MahonyFilterIns_),
    TCPIns(TCPIns_) {};

protected:

    void run() override;

private:

    MahonyFilter& MahonyFilterIns;
    TCP& TCPIns;

};


#endif