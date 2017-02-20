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
    // TODO Auto-generated constructor stub

}

void cManualShooterControl::Initialize()
{
	CommandBase::s_shooter->setManualEnabled(true);
}

void cManualShooterControl::Execute()
{
    CommandBase::s_shooter->setSpeed(CommandBase::s_oi->getSliderPos() * MANUAL_SHOOTER_CONTROL_SCALAR);
}

bool cManualShooterControl::IsFinished()
{
    return false;
}

void cManualShooterControl::End()
{
    CommandBase::s_shooter->setManualEnabled(false);
}

void cManualShooterControl::Interrupted()
{
    End();
}

cManualShooterControl::~cManualShooterControl()
{
    // TODO Auto-generated destructor stub
}

