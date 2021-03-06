#include <gmock/gmock.h>
#include <Subsystems/Interfaces/iShooter.h>

class MockShooter : public iShooter
{
public:
    MOCK_METHOD1(setSpeed, void(float speed));
    MOCK_METHOD0(getSpeed, double());
};
