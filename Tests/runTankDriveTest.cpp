#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <Subsystems/Interfaces/iDriveBase.h>
#include <Subsystems/Utilities/cMotorGroup.h>
#include <Subsystems/Utilities/cReversingMotorGroup.h>
#include <Subsystems/Sensors/iGyro.h>
#include <CommandBase.h>
#include <Commands/DriveBase/cRunTankDrive.h>
#include <Tests/MockOI.h>
using ::testing::AtLeast;
using ::testing::Return;

class MockDriveBase : public iDriveBase
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

TEST(RunTankDriveTests, InitializeCallsSetEnabled){
    MockDriveBase iDriveBase;
    EXPECT_CALL(iDriveBase, setEnabled(true))
    .Times(AtLeast(1));

    CommandBase::s_drivebase = &iDriveBase;
    cRunTankDrive Command;
    Command.Initialize();
}
//whoody who whatcha gonna doo
TEST(RunTankDriveTests, ExecuteCallsSetSpeed){
    MockDriveBase iDriveBase;
    MockOI mOI;
    EXPECT_CALL(mOI, getLeftStickY()).WillOnce(Return(.5));
    EXPECT_CALL(iDriveBase, setLeftSpeed(.25))
    .Times(AtLeast(1));

    EXPECT_CALL(mOI, getRightStickY()).WillOnce(Return(.5));
    EXPECT_CALL(iDriveBase, setRightSpeed(.25))
    .Times(AtLeast(1));

    CommandBase::s_drivebase = &iDriveBase;
    cRunTankDrive Command;
    Command.Execute();
}
