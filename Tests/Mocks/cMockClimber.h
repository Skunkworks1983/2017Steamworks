#ifndef SRC_SUBSYSTEMS_MOCKCLIMBER_H
#define SRC_SUBSYSTEMS_MOCKCLIMBER_H

#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <Subsystems/Interfaces/iClimber.h>

class MockClimber : public iClimber
{
public:
    MOCK_METHOD1(setSpeed, void(float speed));
};


#endif
