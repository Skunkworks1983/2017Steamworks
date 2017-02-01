#ifndef MESSENGER_H
#define MESSENGER_H

#include <iostream>
#include <sys/types.h>
#include <netdb.h>
#include <string.h>

#include <Services/cMessage.h>

#define RPI_IP "10.19.83.24"
#define RPI_PORT "5555"

#define MSG_LEN 1024

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
    std::string* GetMessage();
};

#endif
