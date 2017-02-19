#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <Subsystems/iOI.h>
#include <CommandBase.h>
using ::testing::AtLeast;

class MockOI : public iOI
{
public:
    MOCK_METHOD0(getLeftStickY, float());
    MOCK_METHOD0(getRightStickY, float());
    MOCK_METHOD0(getShooterSlider, float());
    MOCK_METHOD0(getTurretSlider, float());
};
