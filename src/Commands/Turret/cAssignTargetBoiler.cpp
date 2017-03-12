/*
 * assignTargetBoiler.cpp
 *
 *  Created on: Jan 26, 2017
 *      Author: s-4036956
 */

#include <Commands/Turret/cAssignTargetBoiler.h>
#include <RobotMap.h>
#include <CommandBase.h>
#include "cAssignTargetBoiler.h"
#include <Commands/Autonomous/cAutoBase.h>

cAssignTargetBoiler::cAssignTargetBoiler(eShootingPosition position) :
        m_position(position)
{
    Requires(CommandBase::s_turret);
}

void cAssignTargetBoiler::Initialize()
{
    LOG_INFO("starting cAssignTargetBoiler");

    // ugly as fuck, but ok
    int heading = CommandBase::s_turret->getTurretMotor()->getPosition();
    bool isRed = cAutoBase::getAlliance() == RED;
    isRed = true;

    switch(m_position)
    {
    case LIFT_MIDDLE:
        heading = TURRET_SETPOINT_LIFT_MIDDLE;
        break;
    case LIFT_CLOSE:
        heading = TURRET_SETPOINT_LIFT_CLOSE;
        break;
    case HOPPER_CLOSE:
        heading = TURRET_SETPOINT_HOPPER_CLOSE;
        break;
    }

    // TODO: update conversion functions so that we don't
    // have to deal with stupid ass ticks. whatever

    // mirror
    heading = isRed ? heading : TURRET_SWEEP_RANGE - heading;

    // set orientation
    CommandBase::s_turret->setSetpoint(heading);
}

void cAssignTargetBoiler::Execute()
{

}

bool cAssignTargetBoiler::IsFinished()
{
    return true;
}

void cAssignTargetBoiler::End()
{
    LOG_INFO("ending cAssignTargetBoiler");
}

void cAssignTargetBoiler::Interrupted()
{
    LOG_INFO("interrupted cAssignTargetBoiler");
    End();
}

cAssignTargetBoiler::~cAssignTargetBoiler()
{
    // TODO Auto-generated destructor stub
}

