/*
 * cRunLoader.cpp
 *
 *  Created on: Feb 4, 2017
 *      Author: Nathan
 */

#include <CommandBase.h>
#include <Commands/FuelIndexer/cRunFuelIndexer.h>
#include <RobotMap.h>

cRunFuelIndexer::cRunFuelIndexer()
{
    Requires(CommandBase::s_fuelIndexer);
}

void cRunFuelIndexer::Initialize()
{
    LOG_INFO("starting cRunFuelIndexer");
}

void cRunFuelIndexer::Execute()
{
    CommandBase::s_fuelIndexer->setSpeed(FUELINDEXER_MOTOR1_SPEED);
}

bool cRunFuelIndexer::IsFinished()
{
    return false;
}

void cRunFuelIndexer::End()
{
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

