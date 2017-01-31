#ifndef MESSENGER_H
#define MESSENGER_H

#include <iostream>
#include <sys/types.h>
#include <netdb.h>
#include <string.h>

#include <Services/cMessage.h>

class cMessenger
{
private:
    int m_sock;
    addrinfo* m_info;

public:
    bool m_isPostMatch;

    cMessenger(char* server, char* port);
    ~cMessenger();

    void SendMessage(cMessage* message);
    cMessage* ReceiveMessage();
};

#endif
