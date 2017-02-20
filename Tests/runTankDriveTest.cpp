#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <Subsystems/Interfaces/iDriveBase.h>
#include <Subsystems/Utilities/cMotorGroup.h>
#include <Subsystems/Utilities/cReversingMotorGroup.h>
#include <Subsystems/Interfaces/iGyro.h>
#include <CommandBase.h>
#include <Commands/DriveBase/cRunTankDrive.h>
#include <Tests/MockOI.h>
using ::testing::AtLeast;
using ::testing::Return;

class MockDriveBase: public iDriveBase
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
    MOCK_METHOD0(getIsReversed, bool());
    MOCK_METHOD1(setIsReversed, void(bool isreversed));

};

TEST(RunTankDriveTests, InitializeCallsSetEnabled)
{
    MockDriveBase driveBase;
    EXPECT_CALL(driveBase, setEnabled(true)).Times(AtLeast(1));

    CommandBase::s_drivebase = &driveBase;
    cRunTankDrive Command;
    Command.Initialize();
}
//whoody who whatcha gonna doo
TEST(RunTankDriveTests, ExecuteCallsSetSpeed)
{
    //tests that cRunTankDrive sets speed correctly
    MockDriveBase drivebase;
    MockOI mOI;
    EXPECT_CALL(drivebase, getIsReversed()).WillOnce(Return(false));
    EXPECT_CALL(mOI, getLeftStickY()).WillOnce(Return(.5));
    EXPECT_CALL(drivebase, setLeftSpeed(.25)).Times(AtLeast(1));

    EXPECT_CALL(mOI, getRightStickY()).WillOnce(Return(.5));
    EXPECT_CALL(drivebase, setRightSpeed(.25)).Times(AtLeast(1));

    CommandBase::s_oi = &mOI;
    CommandBase::s_drivebase = &drivebase;
    cRunTankDrive Command;
    Command.Execute();
}
TEST(RunTankDriveTests, ExecuteHasDeadzone)
{
    //tests that cRunTankDrive has a working deadzone
    MockDriveBase drivebase;
    MockOI mOI;
    EXPECT_CALL(drivebase, getIsReversed()).WillOnce(Return(false));
    EXPECT_CALL(mOI, getLeftStickY()).WillOnce(Return(.04));
    EXPECT_CALL(drivebase, setLeftSpeed(0)).Times(AtLeast(1));

    EXPECT_CALL(mOI, getRightStickY()).WillOnce(Return(.04));
    EXPECT_CALL(drivebase, setRightSpeed(0)).Times(AtLeast(1));

    CommandBase::s_oi = &mOI;
    CommandBase::s_drivebase = &drivebase;
    cRunTankDrive Command;
    Command.Execute();
}

TEST(RunTankDriveTests, ExecuteCallsSetSpeedNegative)
{
    //tests that cRunTankDrive can set a negative value
    MockDriveBase drivebase;
    MockOI mOI;
    EXPECT_CALL(drivebase, getIsReversed()).WillOnce(Return(false));
    EXPECT_CALL(mOI, getLeftStickY()).WillOnce(Return(-.5));
    EXPECT_CALL(drivebase, setLeftSpeed(-.25)).Times(AtLeast(1));

    EXPECT_CALL(mOI, getRightStickY()).WillOnce(Return(-.5));
    EXPECT_CALL(drivebase, setRightSpeed(-.25)).Times(AtLeast(1));

    CommandBase::s_oi = &mOI;
    CommandBase::s_drivebase = &drivebase;
    cRunTankDrive Command;
    Command.Execute();
}

TEST(RunTankDriveTests, ExecuteReverses)
{
    //tests that cRunTankDrive handles reversing the robot
    MockDriveBase drivebase;
    MockOI mOI;
    EXPECT_CALL(drivebase, getIsReversed()).WillOnce(Return(true));


    EXPECT_CALL(mOI, getLeftStickY()).WillOnce(Return(1));
    EXPECT_CALL(mOI, getRightStickY()).WillOnce(Return(.5));
    EXPECT_CALL(drivebase, setRightSpeed(-1)).Times(AtLeast(1));
    EXPECT_CALL(drivebase, setLeftSpeed(-.25)).Times(AtLeast(1));

    CommandBase::s_oi = &mOI;
    CommandBase::s_drivebase = &drivebase;
    cRunTankDrive Command;
    Command.Execute();
}

