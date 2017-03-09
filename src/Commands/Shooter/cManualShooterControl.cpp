/*
 * cManualShooterControl.cpp
 *
 *  Created on: Feb 13, 2017
 *      Author: Nathan
 */

#include <Commands/Shooter/cManualShooterControl.h>
#include <CommandBase.h>
#include <RobotMap.h>

cManualShooterControl::cManualShooterControl()
{
	std::cout << "Holy shit init" << std::endl;
}

void cManualShooterControl::Initialize()
{
	CommandBase::s_shooter->setManualEnabled(true);
	CommandBase::s_turret->setManualEnabled(true);

	CommandBase::s_turret->setEnabled(true);
}

void cManualShooterControl::Execute()
{
    CommandBase::s_shooter->setSpeed(CommandBase::s_oi->getSliderPos() * MANUAL_SHOOTER_CONTROL_SCALAR);
    CommandBase::s_turret->setSetpoint(2500*CommandBase::s_oi->getRotPos());
}

bool cManualShooterControl::IsFinished()
{
    return false;
}

void cManualShooterControl::End()
{
    CommandBase::s_shooter->setManualEnabled(false);
    CommandBase::s_turret->setManualEnabled(false);
}

void cManualShooterControl::Interrupted()
{
    End();
}

cManualShooterControl::~cManualShooterControl()
{
}

