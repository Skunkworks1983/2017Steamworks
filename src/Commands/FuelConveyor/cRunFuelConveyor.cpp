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
	Requires(CommandBase::s_fuelIndexer);
    Requires(CommandBase::s_fuelConveyor);

    //m_window = new cMotor(9, NeveRest40);
}

void cRunFuelConveyor::Initialize()
{
    LOG_INFO("starting cRunFuelConveyor");
}

void cRunFuelConveyor::Execute()
{
    CommandBase::s_fuelConveyor->setSpeed(FUELCONVEYOR_MOTOR1_SPEED);
    CommandBase::s_fuelIndexer->setSpeed(-1*FUELINDEXER_MOTOR1_SPEED);
    //m_window->setOutput(1);
}

bool cRunFuelConveyor::IsFinished()
{
	return false;
}

void cRunFuelConveyor::End()
{
	CommandBase::s_fuelIndexer->setSpeed(0);
	CommandBase::s_fuelConveyor->setSpeed(0);
	//m_window->setOutput(0);
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

