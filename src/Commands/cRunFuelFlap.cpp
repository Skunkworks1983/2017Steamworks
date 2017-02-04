/*
 * cRunFuelCollector.cpp
 *
 *  Created on: Feb 4, 2017
 *      Author: Nathan
 */

#include <Commands/cRunFuelFlap.h>
#include <CommandBase.h>

cRunFuelFlap::cRunFuelFlap(float speed, float timeout) :
        m_speed(speed)
{
    // TODO Auto-generated constructor stub
    SetTimeout(timeout);
}

void cRunFuelFlap::Initialize()
{

}

void cRunFuelFlap::Execute()
{
    CommandBase::s_fuelCollector->setCollectorFlapSpeed(m_speed);
}

bool cRunFuelFlap::IsFinished()
{
    return false;
}

void cRunFuelFlap::End()
{

}

void cRunFuelFlap::Interrupted()
{
    End();
}

cRunFuelFlap::~cRunFuelFlap()
{
    // TODO Auto-generated destructor stub
}

