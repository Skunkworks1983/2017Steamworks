#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <Subsystems/iGearCollector.h>
#include <Commands/GearMechanism/cAcquireGear.h>
#include <CommandBase.h>
using ::testing::AtLeast;

class MockGearCollector : public iGearCollector
{
public:
    MOCK_METHOD1(setFlapState, void(bool isOpen));
    MOCK_METHOD1(setServoAngle, void(float angle));
    MOCK_METHOD0(getServoAngle, float());
};
//whoody who whatcha gonna doo
TEST(AcquireGearTests, ExecuteCallsSetFlapState){
    MockGearCollector gearCollector;
    EXPECT_CALL(gearCollector, setFlapState(true))//magic value
    .Times(AtLeast(1));

    CommandBase::s_gearCollector = &gearCollector;
    cAcquireGear Command(true);
    Command.Execute();
}
