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
#include <Commands/Autonomous/AutoBase.h>

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
    bool isRed = AutoBase::getAlliance() == RED;

    std::cout << "cBoiler init" << std::endl;

    switch(m_position)
    {
    case LIFT_MIDDLE:
        heading = TURRET_SETPOINT_LIFT_MIDDLE;
        CommandBase::s_turret->m_heading = TurretShootPosition::CenterLift;
        break;
    case LIFT_CLOSE:
        heading = TURRET_SETPOINT_LIFT_CLOSE;
        CommandBase::s_turret->m_heading = TurretShootPosition::CloseLift;
        break;
    case HOPPER_CLOSE:
        heading = TURRET_SETPOINT_HOPPER_CLOSE;
        CommandBase::s_turret->m_heading = TurretShootPosition::WhiteLine;
        break;
    }

    // TODO: update conversion functions so that we don't
    // have to deal with stupid ass ticks. whatever

    // mirror
    heading = isRed ? heading : TURRET_SWEEP_RANGE - heading;

    // set orientation
    std::cout << "heading: " << heading << std::endl;
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
    std::cout << "end cBoiler" << std::endl;
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

