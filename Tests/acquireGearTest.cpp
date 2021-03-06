#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <Subsystems/Interfaces/iGearCollector.h>
#include <Commands/GearMechanism/cAcquireGear.h>
#include <CommandBase.h>
#include <Tests/Mocks/cMockGearCollector.h>
using ::testing::AtLeast;

//whoody who whatcha gonna doo
TEST(AcquireGearTests, InitializeCallsSetFlapState){
    cMockGearCollector gearCollector;

    EXPECT_CALL(gearCollector, setFlapState(true))//magic value
    .Times(AtLeast(1));

    CommandBase::s_gearCollector = &gearCollector;
    cAcquireGear Command(true);
    Command.Initialize();
}
