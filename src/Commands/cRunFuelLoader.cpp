/*
 * cRunLoader.cpp
 *
 *  Created on: Feb 4, 2017
 *      Author: Nathan
 */

#include <CommandBase.h>
#include <RobotMap.h>
#include <Commands/cRunFuelLoader.h>

cRunFuelLoader::cRunFuelLoader(float speed, float timeout) :
        m_speed(speed)
{
    // TODO Auto-generated constructor stub
    SetTimeout(timeout);
}

void cRunFuelLoader::Initialize()
{
    LOG_INFO("starting cRunFuelLoader");
}

void cRunFuelLoader::Execute()
{
    CommandBase::s_fuelLoader->setSpeed(m_speed);
}

bool cRunFuelLoader::IsFinished()
{
    return false;
}

void cRunFuelLoader::End()
{
    LOG_INFO("ending cRunFuelLoader");
}

void cRunFuelLoader::Interrupted()
{
    LOG_INFO("interrupted cRunFuelLoader");
    End();
}

cRunFuelLoader::~cRunFuelLoader()
{
    // TODO Auto-generated destructor stub
}

