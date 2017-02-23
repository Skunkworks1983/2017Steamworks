/*
 * spinUpShooter.cpp
 *
 *  Created on: Jan 25, 2017
 *      Author: s-4036956
 */

#include <Commands/Shooter/cSpinUpShooter.h>
#include "Subsystems/cShooter.h"
#include "RobotMap.h"
#include "CommandBase.h"

cSpinUpShooter::cSpinUpShooter()
{
    // TODO Auto-generated constructor stub
    
}
void cSpinUpShooter::Initialize()
{
	CommandBase::s_shooter->setManualEnabled(true);
}

void cSpinUpShooter::Execute()
{
	iShooter* shooter = CommandBase::s_shooter;
	double speed = shooter->getSpeed();
	if(speed > SHOOTER_TARGET_SPEED) //It's all negative...
	{
		shooter->setSpeed(1);
	}
	else
	{
		shooter->setSpeed(0);
	}
	std::cout << CommandBase::s_shooter->getSpeed() << std::endl;
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

