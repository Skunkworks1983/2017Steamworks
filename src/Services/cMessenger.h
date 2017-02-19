#ifndef MESSENGER_H
#define MESSENGER_H

#include <iostream>
#include <sys/types.h>
#include <netdb.h>
#include <string>

#include <Services/cMessage.h>
#include <Services/Interfaces/iMessenger.h>

class cMessenger : public iMessenger
{
private:
    int m_sock;

    sockaddr_in m_myaddr;
    sockaddr_in m_remaddr;

    cBoilerData* m_lastBoilerData;
    cLiftData* m_lastLiftData;

    std::string receiveMessage();
public:
    bool m_isPostMatch;

    cMessenger(const char* server, const char* port);
    ~cMessenger();

    void sendMessage(std::string message);

    cBoilerData* receiveBoilerData();
    cLiftData* receiveLiftData();
};

#endif
