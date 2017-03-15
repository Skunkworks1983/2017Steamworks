/*
 * cRunLoader.cpp
 *
 *  Created on: Feb 4, 2017
 *      Author: Nathan
 */

#include <CommandBase.h>
#include <Commands/FuelIndexer/cRunFuelIndexer.h>
#include <RobotMap.h>

cRunFuelIndexer::cRunFuelIndexer(float mult) : m_multiplier(mult)
{
    Requires(CommandBase::s_fuelIndexer);
}

void cRunFuelIndexer::Initialize()
{
    LOG_INFO("starting cRunFuelIndexer");
}

void cRunFuelIndexer::Execute()
{
    CommandBase::s_fuelIndexer->setSpeed(-1*FUELINDEXER_MOTOR1_SPEED * m_multiplier);
}

bool cRunFuelIndexer::IsFinished()
{
    return false;
}

void cRunFuelIndexer::End()
{
	CommandBase::s_fuelIndexer->setSpeed(0);
    LOG_INFO("ending cRunFuelIndexer");
}

void cRunFuelIndexer::Interrupted()
{
    LOG_INFO("interrupted cRunFuelIndexer");
    End();
}

cRunFuelIndexer::~cRunFuelIndexer()
{
    // TODO Auto-generated destructor stub
}

