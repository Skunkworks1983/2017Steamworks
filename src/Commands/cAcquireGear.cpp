/*
 * acquireGear.cpp
 *
 *  Created on: Jan 25, 2017
 *      Author: s-4036956
 */

#include <Commands/cAcquireGear.h>
#include <RobotMap.h>
#include <CommandBase.h>

cAcquireGear::cAcquireGear(float position, float timeout) : m_desiredAngle(position)
{
    Requires(CommandBase::s_gearcollector);
    SetTimeout(timeout);
}

void cAcquireGear::Initialize()
{

}

void cAcquireGear::Execute()
{
    CommandBase::s_gearcollector->setServoAngle(m_desiredAngle);
}

bool cAcquireGear::IsFinished()
{
    return false;
}

void cAcquireGear::End()
{

}

void cAcquireGear::Interrupted()
{
    End();
}

cAcquireGear::~cAcquireGear()
{

}

