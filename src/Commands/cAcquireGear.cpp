/*
 * acquireGear.cpp
 *
 *  Created on: Jan 25, 2017
 *      Author: s-4036956
 */

#include "cAcquireGear.h"
#include <RobotMap.h>
#include <CommandBase.h>

cAcquireGear::cAcquireGear(bool state, float timeout) : m_state(state)
{
    Requires(CommandBase::s_gearcollector);
    SetTimeout(timeout);
}

void cAcquireGear::Initialize()
{

}

void cAcquireGear::Execute()
{
    CommandBase::s_gearcollector->setState(m_state);
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

