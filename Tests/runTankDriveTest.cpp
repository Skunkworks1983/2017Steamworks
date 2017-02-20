#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <Subsystems/Interfaces/iDriveBase.h>
#include <Subsystems/Utilities/cMotorGroup.h>
#include <Subsystems/Utilities/cReversingMotorGroup.h>
#include <Subsystems/Interfaces/iGyro.h>
#include <CommandBase.h>
#include <Commands/DriveBase/cRunTankDrive.h>

#include <Tests/Mocks/MockOI.h>
#include <Tests/Mocks/cMockDriveBase.h>


using ::testing::AtLeast;
using ::testing::Return;

using ::testing::AtLeast;

TEST(RunTankDriveTests, InitializeCallsSetEnabled){
    /*
     * cMockDriveBase iDriveBase;
    EXPECT_CALL(iDriveBase, setEnabled(true))
    .Times(AtLeast(1));

    CommandBase::s_drivebase = &iDriveBase;
    cRunTankDrive Command;
    Command.Initialize();
    */
}

//whoody who whatcha gonna doo
TEST(RunTankDriveTests, ExecuteCallsSetSpeed){
    cMockDriveBase drivebase;
    MockOI mOI;
    EXPECT_CALL(mOI, getLeftStickY()).WillOnce(Return(.5));
    EXPECT_CALL(drivebase, setLeftSpeed(.25))
    .Times(AtLeast(1));

    EXPECT_CALL(mOI, getRightStickY()).WillOnce(Return(.5));
    EXPECT_CALL(drivebase, setRightSpeed(.25))
    .Times(AtLeast(1));

    CommandBase::s_drivebase = &drivebase;
    cRunTankDrive Command;
    Command.Execute();
}
