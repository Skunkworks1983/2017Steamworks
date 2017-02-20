/*
 * this file is the header for the
 * mock turret. we use this for
 * unit testing & receiving values that
 * are fake
 */

#ifndef SRC_SUBSYSTEMS_MOCKTURRET_H
#define SRC_SUBSYSTEMS_MOCKTURRET_H

#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <Subsystems/Interfaces/iTurret.h>

class cMockTurret : public iTurret
{
public:
    MOCK_METHOD1(setSpeed, void(float speed));
    MOCK_METHOD1(setOrientation, void (float heading));
    MOCK_METHOD1(rotate, void(float degrees));
    MOCK_METHOD1(setManualEnabled, void(bool state));
    MOCK_METHOD0(isManualEnabled, bool());
    MOCK_METHOD0(getTurretMotor, cMotor*());
};

#endif
