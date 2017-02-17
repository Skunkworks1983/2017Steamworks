#include <gmock/gmock.h>
#include <Subsystems/iTurret.h>

class MockTurret : public iTurret
{
public:
    MOCK_METHOD1(setSpeed, void(float speed));
    MOCK_METHOD1(setOrientation, void (float heading));
    MOCK_METHOD1(rotate, void(float degrees));
};
