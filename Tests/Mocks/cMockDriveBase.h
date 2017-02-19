#ifndef SRC_SUBSYSTEMS_MOCKDRIVEBASE_H
#define SRC_SUBSYSTEMS_MOCKDRIVEBASE_H

#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <Subsystems/Interfaces/iDriveBase.h>

class cMockDriveBase : public iDriveBase
{
public:
    MOCK_METHOD0(resetEncoder, void());
    MOCK_METHOD1(setLeftSpeed, void(double speed));
    MOCK_METHOD1(setRightSpeed, void(double speed));
    MOCK_METHOD1(setBrakeMode, void(bool brake));
    MOCK_METHOD1(setEnabled, void (bool enabled));
    MOCK_METHOD0(getMotorGroupLeft, cMotorGroup*());
    MOCK_METHOD0(getMotorGroupRight, cMotorGroup*());
    MOCK_METHOD0(getMotorGroupAll, cMotorGroup*());
    MOCK_METHOD0(getMotorGroupGyro, cReversingMotorGroup*());
    MOCK_METHOD0(getGyro, iGyro*());
    MOCK_METHOD0(CanSeeTape, bool());
};

#endif
