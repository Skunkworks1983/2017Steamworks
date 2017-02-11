/*
 * cRunHopperIntake.cpp
 *
 *  Created on: Feb 4, 2017
 *      Author: Nathan
 */

#include ".\cRunHopperIntake.h"
#include <CommandBase.h>
#include <RobotMap.h>

cRunHopperIntake::cRunHopperIntake(float speed, float timeout) :
        m_speed(speed)
{
    // TODO Auto-generated constructor stub
    SetTimeout(timeout);
}

void cRunHopperIntake::Initialize()
{
    LOG_INFO("starting cRunHopperIntake");
}

void cRunHopperIntake::Execute()
{
    CommandBase::s_fuelCollector->setHopperDrumSpeed(m_speed);
}

bool cRunHopperIntake::IsFinished()
{
    return false;
}

void cRunHopperIntake::End()
{
    LOG_INFO("ending cRunHopperIntake");
}

void cRunHopperIntake::Interrupted()
{
    LOG_INFO("interrupted cRunHopperIntake");
    End();
}

cRunHopperIntake::~cRunHopperIntake()
{
    // TODO Auto-generated destructor stub
}

