#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <CommandBase.h>

#include <Tests/Mocks/cMockGearCollector.h>

#include <Commands/GearMechanism/cAcquireGear.h>

using ::testing::AtLeast;

//whoody who whatcha gonna doo
TEST(AcquireGearTests, ExecuteCallsSetFlapState){
    MockGearCollector gearCollector;

    EXPECT_CALL(gearCollector, setFlapState(true))//magic value
    .Times(AtLeast(1));

    CommandBase::s_gearCollector = &gearCollector;
    cAcquireGear Command(true);
    Command.Execute();
}
