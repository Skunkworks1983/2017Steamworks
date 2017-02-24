/*
 * cRunFuelConveyor.cpp
 *
 *  Created on: Feb 19, 2017
 *      Author: Nathan
 */

#include <Commands/FuelConveyor/cRunFuelConveyor.h>
#include <CommandBase.h>
#include <RobotMap.h>

cRunFuelConveyor::cRunFuelConveyor()
{
    Requires(CommandBase::s_fuelConveyor);
}

void cRunFuelConveyor::Initialize()
{
    LOG_INFO("starting cRunFuelConveyor");
}

void cRunFuelConveyor::Execute()
{
    CommandBase::s_fuelConveyor->setSpeed(FUELCONVEYOR_MOTOR1_SPEED);
}

bool cRunFuelConveyor::IsFinished()
{

}

void cRunFuelConveyor::End()
{
	CommandBase::s_fuelConveyor->setSpeed(0);
    LOG_INFO("ending cRunFuelConveyor");
}

void cRunFuelConveyor::Interrupted()
{
    LOG_INFO("interrupted cRunFuelIndexer");
    End();
}

cRunFuelConveyor::~cRunFuelConveyor()
{
    // TODO Auto-generated destructor stub
}

