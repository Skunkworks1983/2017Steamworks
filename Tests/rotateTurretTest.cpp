#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <Subsystems/iTurret.h>
#include <CommandBase.h>
#include <Commands/Turret/cRotateTurret.h>
using ::testing::AtLeast;

class MockTurret : public iTurret
{
public:
    MOCK_METHOD1(setSpeed, void(float speed));
    MOCK_METHOD1(setOrientation, void (float heading));
    MOCK_METHOD1(rotate, void(float degrees));
    MOCK_METHOD1(setManualEnabled, void(bool state));
    MOCK_METHOD0(isManualEnabled, bool());

};

TEST(RotateTurretTests, ExecuteCallsSetSpeed){
    MockTurret turret;
    EXPECT_CALL(turret, setSpeed(.5)) //magic number
    .Times(AtLeast(1));

    CommandBase::s_turret = &turret;
    cRotateTurret Command;
    Command.Execute();
}
