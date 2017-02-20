/*
 * shootPIDTest.cpp
 *
 *  Created on: Feb 19, 2017
 *      Author: S-2505674
 */
#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <Subsystems/Interfaces/iShooter.h>
#include <CommandBase.h>
#include <Commands/Shooter/cShootPID.h>
#include <Tests/Mocks/cMockShooter.h>

using ::testing::AtLeast;

class MockShooter : public iShooter
{
    MOCK_METHOD1(setSpeed, void(float speed));
    MOCK_METHOD0(getSpeed, double());

    MOCK_METHOD1(setManualEnabled, void(bool state));
    MOCK_METHOD0(isManualEnabled, bool());

    MOCK_METHOD0(ResetPID, void());
    MOCK_METHOD0(EnablePID, void());
    MOCK_METHOD0(isPIDEnabled, bool());
    MOCK_METHOD4(setPID, void(double p, double i, double d, double f));
    MOCK_METHOD0(PIDGet, double());
    MOCK_METHOD0(getError, double());
    MOCK_METHOD1(setSetpoint, void(float setpoint));
    MOCK_METHOD0(getSetpoint, double());
    MOCK_METHOD0(DisablePID, void());
};

TEST(ShootPIDTests, ExecuteCallssetSetpoint)
{
	MockShooter shooter;

	EXPECT_CALL(shooter, setSetpoint(1.0))
	.Times(AtLeast(1));

	CommandBase::s_shooter = &shooter;
	cShootPID Command;
	Command.Execute();
}


