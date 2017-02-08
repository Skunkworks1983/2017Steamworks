/*
 * cRotateTurret.cpp
 *
 *  Created on: Feb 5, 2017
 *      Author: s-4036956
 */

#include <Commands/cRotateTurret.h>
#include <RobotMap.h>
#include <CommandBase.h>


cRotateTurret::cRotateTurret(float speed, float timeout)
{
    m_speed = speed;
    if(timeout != 0)
    {
        SetTimeout(timeout);
    }
}

void cRotateTurret::Initialize()
{
    Requires(CommandBase::s_turret);
}

void cRotateTurret::Execute()
{
    CommandBase::s_turret->setSpeed(m_speed);
}

bool cRotateTurret::IsFinished()
{
    return false;
}

void cRotateTurret::End()
{
    CommandBase::s_turret->setSpeed(0);
}

void cRotateTurret::Interrupted()
{
    End();
}

cRotateTurret::~cRotateTurret()
{
    // TODO Auto-generated destructor stub
}

