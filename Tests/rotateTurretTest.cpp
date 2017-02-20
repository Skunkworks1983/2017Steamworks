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

    cBoilerData* data = new cBoilerData(10, 0, true);

    EXPECT_CALL(messenger, receiveBoilerData())
    .WillOnce(Return(data));

    EXPECT_CALL(turret, setOrientation(BOILER_PI_CAMERA_FOV / 2))
    .Times(AtLeast(1));

    CommandBase::s_turret = &turret;
    CommandBase::s_boilerMessenger = &messenger;

    cRotateTurret Command;
    Command.Execute();
}
