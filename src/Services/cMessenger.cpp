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
    // Initialize the last known variables
    m_lastBoilerData = new cBoilerData(0, 0, false);
    m_lastLiftData = new cLiftData(0, false);

    // bind to the udp socket
    if((m_sock = socket(AF_INET, SOCK_DGRAM, 0)) < 0)
    {
        std::cout << "failed to create socket, errno " << errno << "\n";
        return;
    }

    // create the configuration for our own host port
    memset((char *) &m_myaddr, 0, sizeof(m_myaddr));
    m_myaddr.sin_family = AF_INET;
    m_myaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    m_myaddr.sin_port = htons(std::stoi(port));

    // settings for remote address
    memset((char *) &m_remaddr, 0, sizeof(m_remaddr));
    m_remaddr.sin_family = AF_INET;
    inet_pton(AF_INET, server, &(m_remaddr.sin_addr));
    m_remaddr.sin_port = htons(std::stoi(port));

    // bind to the socket
    if(bind(m_sock, (struct sockaddr *) &m_myaddr, sizeof(m_myaddr)) < 0)
    {
        std::cout << "failed to bind to socket, errno " << errno << "\n";
        return;
    }
}

cMessenger::~cMessenger()
{
    delete m_lastBoilerData;
    delete m_lastLiftData;
}

// Sends a string through the socket
void cMessenger::sendMessage(std::string message)
{
    // Send a message to the socket using the connection settings obtained earlier
    if(sendto(m_sock, message.c_str(), message.length() + 1, 0, (struct sockaddr*) &m_remaddr, sizeof(m_remaddr)) == -1)
    {
        std::cout << "sendto failed, error: " << errno << "\n";
    }
}

// Remember to delete return value
std::string cMessenger::receiveMessage()
{
    char message_buffer[MSG_LEN];
    memset(message_buffer, 0, MSG_LEN);

    if(recv(m_sock, message_buffer, MSG_LEN, MSG_DONTWAIT) == -1)
    {
        if(errno != EAGAIN && errno != EWOULDBLOCK)
        {
            std::cout << "recvfrom failed, error: " << errno << "\n";
            return "message failed";
        }
    }

    std::string message_converted(message_buffer);
    return message_converted;
}

cBoilerData* cMessenger::receiveBoilerData()
{
    std::string message = receiveMessage();

    if(message[0] != 0)
    {
        if(message[0] == std::to_string(BOILER_PI_ID)[0])
        {
            float x, y;
            bool found;

            // erase the id portion of the message, to remove the first space delimiter
            message.erase(0, 2);

            // find whether or not we can see the target
            found = message[0] == '1';
            message.erase(0, 2);

            // cut the first portion of characters from the first space to the second space
            x = atof(message.substr(0, message.find(" ")).c_str());

            // erase the x portion of the message
            message.erase(0, message.find(" ") + 1);

            // get the y pos
            y = atof(message.substr(0, message.length() + 1).c_str());

            // check if the member lastboilerdata exists. if it does, then we delete
            // it as to not cause any leaks & set it to null
            if(m_lastBoilerData != NULL)
            {
                delete m_lastBoilerData;
                m_lastBoilerData = NULL;
            }

            // edit the new member variable
            m_lastBoilerData = new cBoilerData(x, y, found);
        }
    }

    return m_lastBoilerData;
}

cLiftData* cMessenger::receiveLiftData()
{
    std::string message = receiveMessage();

    if(message[0] != 0)
    {
        if(message[0] == std::to_string(GEAR_PI_ID)[0])
        {
            float x;
            bool found;

            // erase the id portion of the message, to remove the id and first space delimiter
            message.erase(0, 2);

            // find whether or not we can see the target
            found = message[0] == '1';
            message.erase(0, 2);

            // cut the first portion of characters from the first space to the second space
            x = atof(message.substr(0, message.find(" ")).c_str());

            // check if the member lastliftdata exists. if it does, then we delete
            // it as to not cause any leaks & set it to null
            if(m_lastLiftData != NULL)
            {
                delete m_lastLiftData;
                m_lastLiftData = NULL;
            }

            // edit the new member variable
            m_lastLiftData = new cLiftData(x, found);
        }
    }

    // return the last known position of the boiler if there is none on screen
    return m_lastLiftData;
}
