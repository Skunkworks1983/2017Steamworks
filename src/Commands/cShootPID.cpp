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


cShootPID::cShootPID(double leftSpeed, double rightSpeed, float timeout) :
		leftSpeed(leftSpeed), rightSpeed(rightSpeed), timeout(timeout)
{

}

void cShootPID::Initialize()
{
	s_shooter->getLeft()->EnablePID();
	s_shooter->getRight()->EnablePID();

	left_setpoint = fmax(5.0, s_shooter->getLeft()->PIDGet());
	right_setpoint = fmax(5.0, s_shooter->getRight()->PIDGet());

	s_shooter->getRight()->setSetpoint(right_setpoint);
	s_shooter->getLeft()->setSetpoint(left_setpoint);

	if (timeout != 0)
	{
		SetTimeout(timeout);
	}
}

void cShootPID::Execute()
{
	if (!s_shooter->getLeft()->isPIDEnabled()) {
		s_shooter->getLeft()->EnablePID();
	}
	if (!s_shooter->getRight()->isPIDEnabled()) {
		s_shooter->getRight()->EnablePID();
	}

	if (left_setpoint < leftSpeed) {
		left_setpoint += 2;
	} else {
		left_setpoint = leftSpeed;
	}
	if (right_setpoint < rightSpeed) {
		right_setpoint += 2;
	} else {
		right_setpoint = rightSpeed;
	}

	s_shooter->getLeft()->setSetpoint(left_setpoint);
	s_shooter->getRight()->setSetpoint(right_setpoint);
}

bool cShootPID::IsFinished()
{
	return IsTimedOut();
}

void cShootPID::End()
{
	s_shooter->getLeft()->DisablePID();
	s_shooter->getRight()->DisablePID();
	s_shooter->getRight()->ResetPID();
	s_shooter->getLeft()->ResetPID();
}

void cShootPID::Interrupted()
{
	End();
}
