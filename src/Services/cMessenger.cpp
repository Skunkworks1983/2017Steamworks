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
    socklen_t addrlen = sizeof(m_remaddr); /* length of addresses */
    int recvlen; /* # bytes received */
    unsigned char buf[MSG_LEN]; /* receive buffer */

    /* create a UDP socket */

    if((m_sock = socket(AF_INET, SOCK_DGRAM, 0)) < 0)
    {
        perror("cannot create socket\n");
        return;
    }

    /* bind the socket to any valid IP address and a specific port */

    memset((char *) &m_myaddr, 0, sizeof(m_myaddr));
    m_myaddr.sin_family = AF_INET;
    m_myaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    m_myaddr.sin_port = htons(8888);

    memset((char *) &m_remaddr, 0, sizeof(m_remaddr));
    m_remaddr.sin_family = AF_INET;
    inet_pton(AF_INET, "10.19.83.100", &(m_remaddr.sin_addr));
    m_remaddr.sin_port = htons(8888);

    if(bind(m_sock, (struct sockaddr *) &m_myaddr, sizeof(m_myaddr)) < 0)
    {
        perror("bind failed");
        return;
    }

    /*
     m_isPostMatch = false;

     struct addrinfo hints;
     struct sockaddr_in myaddr;
     int addrinfo_stat;

     // Create the out variable for the connection settings
     memset((char*) &hints, 0, sizeof(hints));
     hints.ai_socktype = SOCK_DGRAM;
     hints.ai_family = AF_INET;
     hints.ai_flags = AI_NUMERICSERV;
     hints.ai_protocol = 0;

     // Attempt to get the address information of the system we're connecting to
     // for later, and save the settings in hints & info
     if((addrinfo_stat = getaddrinfo(RPI_IP, RPI_PORT, &hints, &m_info)) != 0)
     {
     std::cout << "couldn't get address info, error: " << errno << "\n";
     return;
     }

     // Attempt to create the socket
     if((m_sock = socket(m_info->ai_family, m_info->ai_socktype, m_info->ai_protocol)) == -1)
     {
     std::cout << "couldn't create socket, error: " << errno << "\n";
     return;
     }
     */
}

cMessenger::~cMessenger()
{

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
