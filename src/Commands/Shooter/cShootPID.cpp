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


cShootPID::cShootPID(double setpoint, float timeout)
{
	Requires(CommandBase::s_shooter);
	std::cout << "Hey its a me it the oi" << std::endl;
	m_speed = setpoint;//155 (FOR MIDDLE); SmartDashboard::GetNumber("TestShootSpeed", -80);

	m_currentSetpoint = -1.0;
	m_timeout = timeout;
}

void cShootPID::Initialize()
{
	double p = 0;//SmartDashboard::GetNumber("P", SHOOTER_P);
	double i = 0;//SmartDashboard::GetNumber("I", SHOOTER_I);
	double d = 0;//SmartDashboard::GetNumber("D", SHOOTER_D);
	double f = 0.25;//SmartDashboard::GetNumber("F", SHOOTER_F);

	std::cout <<"cShootPID initialize";

	m_currentSetpoint = 0;
	CommandBase::s_shooter->EnablePID();
	CommandBase::s_shooter->setPID(p, i, d, f);

	CommandBase::s_shooter->setSetpoint(m_currentSetpoint);

	if (m_timeout != 0)
	{
		SetTimeout(m_timeout);
	}
	std::cout << "Hey its a me its the button being pressed" << std::endl;

	CommandBase::s_shooter->getShooterMotor()->reverseOutput();

	CommandBase::s_shooter->getShooterMotor()->setVoltageRampRate(3);
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

	CommandBase::s_shooter->setSetpoint(m_speed);

	SmartDashboard::PutNumber("cShootPIDspeed", CommandBase::s_shooter->PIDGet());
	SmartDashboard::PutNumber("cShootPIDError", CommandBase::s_shooter->getError());
	SmartDashboard::PutNumber("cShootPIDSetpoint", CommandBase::s_shooter->getSetpoint());
	SmartDashboard::PutNumber("Shooter output", CommandBase::s_shooter->getOutput());

	SmartDashboard::PutNumber("Shooter speed: ", CommandBase::s_shooter->getSpeed());


	//std::cout << "Setpoint: " << m_currentSetpoint << std::endl;

}

bool cShootPID::IsFinished()
{
	//return IsTimedOut();
	return false;
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
