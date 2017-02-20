#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <CommandBase.h>

#include <Services/cMessage.h>

#include <Tests/Mocks/cMockTurret.h>
#include <Tests/Mocks/cMockMessenger.h>

#include <Commands/Turret/cRotateTurret.h>

using ::testing::Return;
using ::testing::AtLeast;

TEST(RotateTurretTests, RotateTurretClampTest){
    cMockTurret turret;
    cMockMessenger messenger;

<<<<<<< HEAD
    cBoilerData* data = new cBoilerData(10, 0, true);
=======

};
/*
TEST(RotateTurretTests, ExecuteCallsSetSpeed){
    MockTurret turret;
    EXPECT_CALL(turret, setSpeed(.5)) //magic number

    cBoilerData* data = new cBoilerData(1, 0, true);
>>>>>>> master

    EXPECT_CALL(messenger, receiveBoilerData())
    .WillOnce(Return(data));

<<<<<<< HEAD
    EXPECT_CALL(turret, setOrientation(BOILER_PI_CAMERA_FOV / 2))
=======
    EXPECT_CALL(turret, setOrientation(50/2))

>>>>>>> master
    .Times(AtLeast(1));

    CommandBase::s_turret = &turret;
    CommandBase::s_boilerMessenger = &messenger;

    cRotateTurret Command;
    Command.Execute();
}
*/
