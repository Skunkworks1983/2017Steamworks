/*
 * spinUpShooter.cpp
 *
 *  Created on: Jan 25, 2017
 *      Author: s-4036956
 */

#include <Commands/Shooter/cSpinUpShooter.h>
#include "Subsystems/cShooter.h"
#include "RobotMap.h"
#include "CommandBase.h"
#include <sstream>

cSpinUpShooter::cSpinUpShooter()
{
    // TODO Auto-generated constructor stub

}
void cSpinUpShooter::Initialize()
{
    LOG_INFO("starting cSpinUpShooter");
}

void cSpinUpShooter::Execute()
{
    cShooter* shooter = CommandBase::s_shooter;
    double speed = shooter->getSpeed();

    std::stringstream message;

    if(speed < SHOOTER_TARGET_SPEED)
    {
        message << "shooter speed below target at " << speed;
        shooter->setSpeed(1);
    }
    else
    {
        message << "shooter speed above target at " << speed;
        shooter->setSpeed(0);
    }

    LOG_INFO(message.str().c_str());
}

bool cSpinUpShooter::IsFinished()
{
    return false;
}

void cSpinUpShooter::End()
{
    LOG_INFO("ending cSpinUpShooter");
    CommandBase::s_shooter->setSpeed(0);
}

void cSpinUpShooter::Interrupted()
{
    LOG_INFO("interrupted cSpinUpShooter");
    End();
}

cSpinUpShooter::~cSpinUpShooter()
{
    // TODO Auto-generated destructor stub
}
