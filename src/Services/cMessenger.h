#ifndef MESSENGER_H
#define MESSENGER_H

#include <iostream>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <string.h>
#include <errno.h>

#include <Services/cMessage.h>

#define RPI_IP "10.19.83.217"
#define RPI_PORT "8888"

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

    void SendMessage(cMessage message);
    cMessage* ReceiveMessage();
};

#endif
