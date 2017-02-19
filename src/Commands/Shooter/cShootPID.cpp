/*
 * cShootPID.cpp
 *
 *  Created on: Feb 11, 2017
 *      Author: s-2505674
 */
#include "Subsystems/cShooter.h"
#include "cShootPID.h"
#include <cmath>
#include "RobotMap.h"


cShootPID::cShootPID(double speed, float timeout) :
		speed(speed), timeout(timeout)
{
	Requires(CommandBase::s_shooter);
}

void cShootPID::Initialize()
{
	s_shooter->EnablePID();

	s_shooter->setPID(p, i, d, f);

	s_shooter->setSetpoint(current_setpoint);

	if (timeout != 0)
	{
		SetTimeout(timeout);
	}
}
//

void cShootPID::Execute()
{
	if (!s_shooter->isPIDEnabled()) {
		s_shooter->EnablePID();
	}

	if (current_setpoint < speed) {
		current_setpoint += RAMPING_CONSTANT;
	} else {
		current_setpoint = speed;
		s_shooter->setSetpoint(current_setpoint);
	}

}

bool cShootPID::IsFinished()
{
	return IsTimedOut();
}

void cShootPID::End()
{
	s_shooter->DisablePID();
	s_shooter->ResetPID();
}

void cShootPID::Interrupted()
{
	End();
}
