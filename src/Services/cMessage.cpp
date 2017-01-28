/*
 * This function controls the Message class.
 * To communicate with the raspberry pi, we send
 * Messages that contain the position of a vision target
 * in a string.
 */

#include <Services/cMessage.h>

cMessage::cMessage(std::string message_)
{
    message = message_;
}

cMessage::~cMessage()
{
    delete &message;
}

std::string cMessage::Pack()
{
    return message;
}
