#include <gmock/gmock.h>
#include <Subsystems/iFuelCollector.h>

class MockFuelCollector : public iFuelCollector
{
public:
    MOCK_METHOD1(setCollectorFlapAngle, void(float angle));
    MOCK_METHOD1(setHopperDrumSpeed, void(float speed));
};
