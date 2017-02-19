/*
 * cRunFuelCollector.cpp
 *
 *  Created on: Feb 4, 2017
 *      Author: Nathan
 */

#include "cRunFuelFlap.h"
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
    LOG_INFO("starting cRunFuelFlap");
}

void cRunFuelFlap::Execute()
{
    CommandBase::s_fuelCollector->setFlapAngle(m_position);
}

bool cRunFuelFlap::IsFinished()
{
    return false;
}

void cRunFuelFlap::End()
{
    LOG_INFO("ending cRunFuelFlap");
}

void cRunFuelFlap::Interrupted()
{
    LOG_INFO("interrupted cRunFuelFlap");
    End();
}

cRunFuelFlap::~cRunFuelFlap()
{
    // TODO Auto-generated destructor stub
}

