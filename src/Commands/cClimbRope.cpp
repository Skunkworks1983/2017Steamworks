/*
 * climbRope.cpp
 *
 *  Created on: Jan 25, 2017
 *      Author: s-4036956
 */

#include "cClimbRope.h"
#include <CommandBase.h>
#include <RobotMap.h>

cClimbRope::cClimbRope(float speed, float timeout) :
        m_speed(speed)
{
    Requires(CommandBase::s_climber);
    SetTimeout(timeout);
}

void cClimbRope::Initialize()
{

}

void cClimbRope::Execute()
{
    CommandBase::s_climber->setSpeed(m_speed);
}

bool cClimbRope::IsFinished()
{
    return false;
}

void cClimbRope::End()
{
    CommandBase::s_climber->setSpeed(0);
}

void cClimbRope::Interrupted()
{
    End();
}

cClimbRope::~cClimbRope()
{
    // TODO Auto-generated destructor stub
}

