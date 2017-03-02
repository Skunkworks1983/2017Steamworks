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
    CommandBase::s_turret->setManualEnabled(true);
}

void cManualTurretControl::Initialize()
{

}

void cManualTurretControl::Execute()
{
    CommandBase::s_turret->setSpeed(CommandBase::s_oi->getRotPos() * -0.05);
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

