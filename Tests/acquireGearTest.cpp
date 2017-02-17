#include <gmock/gmock.h>
#include <Subsystems/iGearCollector.h>

class MockGearCollector : public iGearCollector
{
public:
    MOCK_METHOD1(setFlapState, void(bool isOpen));
    MOCK_METHOD1(setServoAngle, void(float angle));
    MOCK_METHOD0(setServoAngle, float());
};
