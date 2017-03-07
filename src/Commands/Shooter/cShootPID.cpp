/*

`1* cShootPID.cpp
 *
 *  Created on: Feb 11, 2017
 *      Author: s-2505674
 */
#include "Subsystems/cShooter.h"
#include "cShootPID.h"
#include <cmath>
#include "RobotMap.h"
#include <SmartDashboard/SmartDashboard.h>


cShootPID::cShootPID(double speed, float timeout) :
		speed(speed), timeout(timeout)
{
	Requires(CommandBase::s_shooter);
	std::cout << "Hey its a me it the oi" << std::endl;
}

void cShootPID::Initialize()
{
	current_setpoint = 0;
	s_shooter->EnablePID();

	s_shooter->setPID(p, i, d, f);

	s_shooter->setSetpoint(current_setpoint);

	if (timeout != 0)
	{
		SetTimeout(timeout);
	}
	std::cout << "Hey its a me its the button being pressed" << std::endl;
}
//

void cShootPID::Execute()
{
	if (!s_shooter->isPIDEnabled()) {
		s_shooter->EnablePID();
	}


	if (current_setpoint > speed) { //Its a flipped
		current_setpoint -= RAMPING_CONSTANT;
	} else {
		current_setpoint = speed;
		s_shooter->setSetpoint(current_setpoint);
	}

	SmartDashboard::PutNumber("cShootPIDspeed", s_shooter->PIDGet());
	SmartDashboard::PutNumber("cShootPIDError", s_shooter->getError());
	SmartDashboard::PutNumber("cShootPIDSetpoint", s_shooter->getSetpoint());
  
	std::cout << "Setpoint: " << current_setpoint << std::endl;

}

bool cShootPID::IsFinished()
{
	return IsTimedOut();
}

void cShootPID::End()
{
	s_shooter->setSpeed(0);
	s_shooter->DisablePID();
	s_shooter->ResetPID();
}

void cShootPID::Interrupted()
{
	End();
}

//Sleep is good, death is better; but of course, the best thing would to have never been born at all.
//	-Heinrich Heine
