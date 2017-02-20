#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <CommandBase.h>

#include <Services/cMessage.h>

#include <Tests/Mocks/cMockTurret.h>
#include <Tests/Mocks/cMockMessenger.h>

#include <Commands/Turret/cRotateTurret.h>

using ::testing::Return;
using ::testing::AtLeast;

TEST(RotateTurretTests, ExecuteCallsSetSpeed){
    cMockTurret turret;
    cMockMessenger messenger;


};
/*
TEST(RotateTurretTests, ExecuteCallsSetSpeed){
    MockTurret turret;
    EXPECT_CALL(turret, setSpeed(.5)) //magic number

    cBoilerData* data = new cBoilerData(1, 0, true);

    EXPECT_CALL(messenger, receiveBoilerData())
    .WillOnce(Return(data));

    EXPECT_CALL(turret, setOrientation(50/2))

    .Times(AtLeast(1));

    CommandBase::s_turret = &turret;
    CommandBase::s_boilerMessenger = &messenger;

    cRotateTurret Command;
    Command.Execute();
}
*/
