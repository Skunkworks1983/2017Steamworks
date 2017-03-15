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


cShootPID::cShootPID(double setpoint)
{
	Requires(CommandBase::s_shooter);
	std::cout << "Hey its a me it the oi" << std::endl;
	m_setpoint = setpoint;
}

void cShootPID::Initialize()
{
	double p = 250;//SmartDashboard::GetNumber("P", SHOOTER_P);
	double i = 0;//SmartDashboard::GetNumber("I", SHOOTER_I);
	double d = 0;//SmartDashboard::GetNumber("D", SHOOTER_D);
	double f = 3.5;//SmartDashboard::GetNumber("F", SHOOTER_F);
	speed = m_setpoint;//155 (FOR MIDDLE); SmartDashboard::GetNumber("TestShootSpeed", -80);

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

	CommandBase::s_shooter->getShooterMotor()->reverseOutput();
}
//

void cShootPID::Execute()
{

/*	if (!CommandBase::s_shooter->isPIDEnabled()) {
		CommandBase::s_shooter->EnablePID();
	}

	if (current_setpoint > speed) { //Its a flipped
		current_setpoint -= RAMPING_CONSTANT;
	} else {
		current_setpoint = speed;
	}*/

	CommandBase::s_shooter->setSetpoint(speed);

	SmartDashboard::PutNumber("cShootPIDspeed", CommandBase::s_shooter->PIDGet());
	SmartDashboard::PutNumber("cShootPIDError", CommandBase::s_shooter->getError());
	SmartDashboard::PutNumber("cShootPIDSetpoint", CommandBase::s_shooter->getSetpoint());
	SmartDashboard::PutNumber("Shooter output", CommandBase::s_shooter->getOutput());
	//SmartDashboard::PutNumber("Shooter throttle", CommandBase::s_shooter->get)

  
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
