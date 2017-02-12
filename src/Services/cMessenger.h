#ifndef MESSENGER_H
#define MESSENGER_H

#include <iostream>
#include <sys/types.h>
#include <netdb.h>
#include <string>

#include <Services/cMessage.h>

class cMessenger
{
private:
    int m_sock;

    sockaddr_in m_myaddr;
    sockaddr_in m_remaddr;

    cBoilerData* lastBoiler;
    cLiftData* lastLift;

    void sendMessage(std::string message);
    std::string receiveMessage();
public:
    bool m_isPostMatch;

    cMessenger(const char* server, const char* port);
    ~cMessenger();

    cBoilerData* receiveBoilerData();
    cLiftData* receiveLiftData();
};

#endif
