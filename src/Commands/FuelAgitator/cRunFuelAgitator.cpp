/*
 * cRunFuelAgitator.cpp
 *
 *  Created on: Mar 11, 2017
 *      Author: s-2508366
 */

#include <Commands/FuelAgitator/cRunFuelAgitator.h>
#include <CommandBase.h>
#include <RobotMap.h>

cRunFuelAgitator::cRunFuelAgitator()
{
    Requires(CommandBase::s_fuelAgitator);
}

void cRunFuelAgitator::Initialize()
{
    LOG_INFO("starting cRunFuelAgitator");
}

void cRunFuelAgitator::Execute()
{
    CommandBase::s_fuelAgitator->setSpeed(FUELAGITATOR_MOTOR1_SPEED);
}

bool cRunFuelAgitator::IsFinished()
{
    return IsTimedOut();
}

void cRunFuelAgitator::End()
{
    CommandBase::s_fuelAgitator->setSpeed(0);
    LOG_INFO("ending cRunFuelAgitator");
}

void cRunFuelAgitator::Interrupted()
{
    LOG_INFO("interrupted cRunFuelAgitator");
    End();
}

cRunFuelAgitator::~cRunFuelAgitator()
{
    // TODO Auto-generated destructor stub
}

