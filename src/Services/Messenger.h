#ifndef MESSENGER_H
#define MESSENGER_H

#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <string.h>

#define RPI_IP "10.76.5.17"
#define RPI_PORT "8888"

class c_Messenger
{
private:
    int m_sock;
    addrinfo* m_info;

public:
    c_Messenger(char* server, char* port);
    ~c_Messenger();

    void SendMessage(std::string message);
};

#endif
