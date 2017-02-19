#ifndef SRC_SUBSYSTEMS_MOCKGEARCOLLECTOR_H
#define SRC_SUBSYSTEMS_MOCKGEARCOLLECTOR_H

#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <Subsystems/Interfaces/iGearCollector.h>

class cMockGearCollector : public iGearCollector {
public:
    MOCK_METHOD1(setFlapState, void(bool open));
    MOCK_METHOD1(setServoAngle, void(float angle));
};

#endif
