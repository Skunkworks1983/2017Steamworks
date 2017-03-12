/*
 * cManualTurretControl.cpp
 *
 *  Created on: Feb 12, 2017
 *      Author: Nathan
 */

#include <Commands/Turret/cManualTurretControl.h>
#include <CommandBase.h>
#include <RobotMap.h>

cManualTurretControl::cManualTurretControl()
{

}

void cManualTurretControl::Initialize()
{
    CommandBase::s_turret->setManualEnabled(true);
}

void cManualTurretControl::Execute()
{
    CommandBase::s_turret->setSpeed(CommandBase::s_oi->getRotPos());

    //CommandBase::s_turret->setManualEnabled(true);
    //CommandBase::s_turret->getTurretMotor()->setPosition();

}

bool cManualTurretControl::IsFinished()
{
    return false;
}

void cManualTurretControl::End()
{
    CommandBase::s_turret->setManualEnabled(false);
}

void cManualTurretControl::Interrupted()
{
    End();
}

cManualTurretControl::~cManualTurretControl()
{
}

