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
#include <Subsystems/cTurret.h>


cShootPID::cShootPID(double setpoint, float timeout)
{
	Requires(CommandBase::s_shooter);
	std::cout << "Hey its a me it the oi" << std::endl;
	m_speed = setpoint;//155 (FOR MIDDLE); SmartDashboard::GetNumber("TestShootSpeed", -80);

	m_currentSetpoint = -1.0;
	m_timeout = timeout;

	m_p = 0.125/16;
	m_i = 0;
	m_d = 0;
	m_f = 0.25/2;

	SmartDashboard::PutNumber("P", m_p);
	SmartDashboard::PutNumber("F", m_f);
}

void cShootPID::Initialize()
{
	/*double p = 0.125/16;//SmartDashboard::GetNumber("P", SHOOTER_P);
	double i = 0;//SmartDashboard::GetNumber("I", SHOOTER_I);
	double d = 0;//SmartDashboard::GetNumber("D", SHOOTER_D);
	double f = 0.25/2;//SmartDashboard::GetNumber("F", SHOOTER_F);*/

	std::cout <<"cShootPID initialize";

	m_currentSetpoint = 0;
	CommandBase::s_shooter->EnablePID();
	CommandBase::s_shooter->setPID(m_p, m_i, m_d, m_f);

	CommandBase::s_shooter->setSetpoint(m_currentSetpoint);

	if (m_timeout != 0)
	{
		SetTimeout(m_timeout);
	}
	std::cout << "Hey its a me its the button being pressed" << std::endl;

	//CommandBase::s_shooter->getShooterMotor()->reverseOutput();
	CommandBase::s_shooter->getShooterMotor()->reverseSensorDirection();

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

    // ugly as fuck, get rid of this shit asap

    switch(CommandBase::s_turret->m_heading) {
    case TurretShootPosition::CenterLift:
        CommandBase::s_shooter->setSetpoint(shooter_rpm_to_ticks((3500)));
        break;
    case TurretShootPosition::CloseLift:
        CommandBase::s_shooter->setSetpoint(shooter_rpm_to_ticks((6000)));
        break;
    case TurretShootPosition::WhiteLine:
        CommandBase::s_shooter->setSetpoint(shooter_rpm_to_ticks((6500)));
        break;
    }

	SmartDashboard::PutNumber("cShootPIDspeed", CommandBase::s_shooter->PIDGet());
	SmartDashboard::PutNumber("cShootPIDError", CommandBase::s_shooter->getError());
	SmartDashboard::PutNumber("cShootPIDSetpoint", CommandBase::s_shooter->getSetpoint());
	SmartDashboard::PutNumber("Shooter output", CommandBase::s_shooter->getOutput());

	CommandBase::s_shooter->setPID(SmartDashboard::GetNumber("P", 0), 0, 0, SmartDashboard::GetNumber("F", 0));

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
	CommandBase::s_shooter->setSetpoint(0);
	CommandBase::s_shooter->DisablePID();
	CommandBase::s_shooter->ResetPID();
}

void cShootPID::Interrupted()
{
	End();
}

//Sleep is good, death is better; but of course, the best thing would to have never been born at all.
//	-Heinrich Heine
