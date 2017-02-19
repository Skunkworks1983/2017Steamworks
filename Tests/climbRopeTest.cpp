#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <Subsystems/Interfaces/iClimber.h>
#include <CommandBase.h>
#include <Commands/Climber/cClimbRope.h>
using ::testing::AtLeast;


class MockClimber : public iClimber
{
public:
    MOCK_METHOD1(setSpeed, void(float speed));
};
/*
TEST(ClimbRopeTests, ExecuteCallsSetSpeed){
    MockClimber iClimber;
    EXPECT_CALL(iClimber, setSpeed(speed)) //maybe make mockoi?
    .Times(AtLeast(1))

    CommandBase::s_climber = &iClimber;
    cClimbRope Command;
    Command.Execute();
}
*/
