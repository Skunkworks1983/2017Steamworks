/*
 * this file is the header for the
 * mock climber. we use this for
 * unit testing & receiving values that
 * are fake
 */

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
