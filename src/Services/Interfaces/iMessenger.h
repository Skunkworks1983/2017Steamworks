/*
 * this class is the interface
 * for the messenger. it's an
 * abstract class because it doesn't
 * do anything and serves as a placeholder
 * for the real deal during unit testing.
 */

#ifndef SRC_SERVICES_IMESSENGER_H
#define SRC_SERVICES_IMESSENGER_H

#include <string>
#include <Services/cMessage.h>

class iMessenger {
public:
    virtual void sendMessage(std::string message) = 0;
    virtual cBoilerData* receiveBoilerData() = 0;
    virtual cLiftData* receiveLiftData() = 0;
};

#endif
