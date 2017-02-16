#include <gmock/gmock.h>
#include <Subsystems/iClimber.h>

class MockClimber : public iClimber
{
public:
    MOCK_METHOD1(setSpeed, void(float speed));
};
