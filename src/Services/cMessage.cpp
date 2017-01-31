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

}

// these two functions will eventually be different.
// for now, all we do is send a string over the socket
// but eventually we will pack integers for the positions
// of the goal into the PackToSend function
std::string cMessage::PackToSend()
{
    return message;
}

std::string cMessage::GetMessage() {
    return message;
}
