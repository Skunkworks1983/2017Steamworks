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
	std::cout <<"cShootPID initialize";
	current_setpoint = 0;
	CommandBase::s_shooter->EnablePID();

	CommandBase::s_shooter->setPID(p, i, d, f);

	CommandBase::s_shooter->setSetpoint(current_setpoint);

	if (timeout != 0)
	{
		SetTimeout(timeout);
	}
	std::cout << "Hey its a me its the button being pressed" << std::endl;
}
//

void cShootPID::Execute()
{
	if (!CommandBase::s_shooter->isPIDEnabled()) {
		CommandBase::s_shooter->EnablePID();
	}


	if (current_setpoint > speed) { //Its a flipped
		current_setpoint -= RAMPING_CONSTANT;
	} else {
		current_setpoint = speed;
		CommandBase::s_shooter->setSetpoint(current_setpoint);
	}

	SmartDashboard::PutNumber("cShootPIDspeed", CommandBase::s_shooter->PIDGet());
	SmartDashboard::PutNumber("cShootPIDError", CommandBase::s_shooter->getError());
	SmartDashboard::PutNumber("cShootPIDSetpoint", CommandBase::s_shooter->getSetpoint());
  
	std::cout << "Setpoint: " << current_setpoint << std::endl;

}

bool cShootPID::IsFinished()
{
	return IsTimedOut();
}

void cShootPID::End()
{
	std::cout << "cShootPID End";
	CommandBase::s_shooter->setSpeed(0);
	CommandBase::s_shooter->DisablePID();
	CommandBase::s_shooter->ResetPID();
}

void cShootPID::Interrupted()
{
	End();
}

//Sleep is good, death is better; but of course, the best thing would to have never been born at all.
//	-Heinrich Heine
