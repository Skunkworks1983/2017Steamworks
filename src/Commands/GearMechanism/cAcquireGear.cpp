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
    Requires(CommandBase::s_gearCollector);
    SetTimeout(timeout);
}

void cAcquireGear::Initialize()
{
    CommandBase::s_gearCollector->setFlapState(true);
}

void cAcquireGear::Execute()
{

}

bool cAcquireGear::IsFinished()
{
    return IsTimedOut();
}

void cAcquireGear::End()
{
    std::cout << "awidawdoin\n";

    CommandBase::s_gearCollector->setFlapState(false);
}

void cAcquireGear::Interrupted()
{
    End();
}

cAcquireGear::~cAcquireGear()
{

}

