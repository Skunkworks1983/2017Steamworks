#ifndef MESSAGE_H
#define MESSAGE_H

#include <string>

class cMessage
{
private:
    std::string message;
public:
    cMessage(std::string message);
    ~cMessage();

    std::string PackToSend();
    std::string GetMessage();
};

#endif
