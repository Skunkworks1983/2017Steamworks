#include <gmock/gmock.h>
#include <Subsystems/Interfaces/iFuelLoader.h>

class MockFuelLoader : public iFuelLoader
{
public:
    MOCK_METHOD1(setSpeed, void(float speed));
};
