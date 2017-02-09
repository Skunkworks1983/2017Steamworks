/*
 * spinUpShooter.cpp
 *
 *  Created on: Jan 25, 2017
 *      Author: s-4036956
 */

#include <Commands/cSpinUpShooter.h>
#include "Subsystems/cShooter.h"
#include "RobotMap.h"
#include "CommandBase.h"

cSpinUpShooter::cSpinUpShooter()
{
    // TODO Auto-generated constructor stub
    
}
void cSpinUpShooter::Initialize()
{

}

void cSpinUpShooter::Execute()
{
	cShooter* shooter = CommandBase::s_shooter;
	double speed = shooter->getSpeed();
	if(speed < SHOOTER_TARGET_SPEED)
	{
		shooter->setSpeed(1);
	}
	else
	{
		shooter->setSpeed(0);
	}
}

bool cSpinUpShooter::IsFinished()
{
    return false;
}

void cSpinUpShooter::End()
{
	CommandBase::s_shooter->setSpeed(0);
}

void cSpinUpShooter::Interrupted()
{
	End();
}

cSpinUpShooter::~cSpinUpShooter()
{
    // TODO Auto-generated destructor stub
}

