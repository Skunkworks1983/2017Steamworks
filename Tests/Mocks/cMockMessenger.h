/*
 * this file is the header for the
 * mock messenger. we use this for
 * unit testing & receiving values that
 * are fake
 */

#ifndef SRC_SUBSYSTEMS_MOCKMESSENGER_H
#define SRC_SUBSYSTEMS_MOCKMESSENGER_H

#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <Services/cMessage.h>
#include <Services/Interfaces/iMessenger.h>

class cMockMessenger : public iMessenger
{
public:
    MOCK_METHOD1(sendMessage, void(std::string));
    MOCK_METHOD0(receiveBoilerData, cBoilerData*());
    MOCK_METHOD0(receiveLiftData, cLiftData*());
};

#endif
