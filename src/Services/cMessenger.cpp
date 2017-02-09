/*
 *  This file handles the Messenger system.
 *  We create a socket to talk to the raspberry pi to
 *  from the roborio. ez $$
 *  Written by Nathan Tresham
 */

#include <Services/cMessenger.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <errno.h>
#include <iostream>
#include <RobotMap.h>

// Creates a new messenger instance
cMessenger::cMessenger(const char *server, const char *port)
{
    // create a new socket
    if((m_sock = socket(AF_INET, SOCK_DGRAM, 0)) < 0)
    {
        std::cout << "failed to create socket, errno " << errno << "\n";
        return;
    }

    // configure the settings for our own address configuration (us)
    memset((char *) &m_myaddr, 0, sizeof(m_myaddr));
    m_myaddr.sin_family = AF_INET;
    m_myaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    m_myaddr.sin_port = htons((int) port);

    // configure the settings for the target we're sending to (raspberry pies)
    memset((char *) &m_remaddr, 0, sizeof(m_remaddr));
    m_remaddr.sin_family = AF_INET;
    inet_pton(AF_INET, server, &(m_remaddr.sin_addr));
    m_remaddr.sin_port = htons((int) port);

    // bind to the socket using the configuration of our own host, as defined above
    if(bind(m_sock, (struct sockaddr*) &m_myaddr, sizeof(m_myaddr)) < 0)
    {
        std::cout << "failed to bind to socket, errno " << errno << "\n";
        return;
    }
}

cMessenger::~cMessenger()
{
    free(&m_myaddr);
    free(&m_remaddr);
}

// Sends a string through the socket
void cMessenger::SendMessage(cMessage* message)
{
    std::string toSend = message->PackToSend();

    // Send a message to the socket using the connection settings obtained earlier
    if(sendto(m_sock, toSend.c_str(), toSend.size() + 1, 0, (struct sockaddr*) &m_remaddr, sizeof(m_remaddr)) == -1)
    {
        std::cout << "sendto failed, error: " << errno << "\n";
    }
}

// Remember to delete return value
// ^^make comment more descriptive
cMessage* cMessenger::ReceiveMessage()
{
    char message_buffer[MSG_LEN];
    memset(message_buffer, 0, MSG_LEN);

    if(recv(m_sock, message_buffer, MSG_LEN, MSG_DONTWAIT) == -1)
    {
        if(errno != EAGAIN && errno != EWOULDBLOCK)
        {
            std::cout << "recvfrom failed, error: " << errno << "\n";
            return new cMessage("message failed");
        }
    }

    std::string message_converted(message_buffer);
    return new cMessage(message_converted);
}
