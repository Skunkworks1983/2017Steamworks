/*
 * cRunHopperIntake.cpp
 *
 *  Created on: Feb 4, 2017
 *      Author: Nathan
 */

#include <Commands/cRunHopperIntake.h>
#include <CommandBase.h>

cRunHopperIntake::cRunHopperIntake(float speed, float timeout) :
        m_speed(speed)
{
    // TODO Auto-generated constructor stub
    SetTimeout(timeout);
}

void cRunHopperIntake::Initialize()
{

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

}

void cRunHopperIntake::Interrupted()
{
    End();
}

cRunHopperIntake::~cRunHopperIntake()
{
    // TODO Auto-generated destructor stub
}

