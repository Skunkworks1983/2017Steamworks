/*
 * cRunFuelCollector.cpp
 *
 *  Created on: Feb 4, 2017
 *      Author: Nathan
 */

#include <Commands/cRunFuelFlap.h>
#include <CommandBase.h>
#include <RobotMap.h>

cRunFuelFlap::cRunFuelFlap(FuelCollectorPosition position, float timeout) :
        m_position(position)
{
    // TODO Auto-generated constructor stub
    SetTimeout(timeout);
}

void cRunFuelFlap::Initialize()
{

}

void cRunFuelFlap::Execute()
{
    CommandBase::s_fuelCollector->setCollectorFlapAngle(m_position);
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

