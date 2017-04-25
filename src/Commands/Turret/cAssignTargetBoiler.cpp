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

    int red_middle = -1035;
    int red_close = -2750;
    int red_hopper = -2300;

    int blue_middle = -4165;
    int blue_close = -2120;
    int blue_hopper = -2800;

    // ugly as fuck, but ok, like a turtle
    int heading = CommandBase::s_turret->getTurretMotor()->getPosition();
    bool isRed = AutoBase::getAlliance() == RED;

    switch(m_position)
    {
    case LIFT_MIDDLE:
        heading = isRed ? red_middle : blue_middle;
        CommandBase::s_turret->m_heading = TurretShootPosition::CenterLift;
        break;
    case LIFT_CLOSE:
        heading = isRed ? red_close : blue_close;
        CommandBase::s_turret->m_heading = TurretShootPosition::CloseLift;
        break;
    case HOPPER_CLOSE:
        heading = isRed ? red_hopper : blue_hopper;
        CommandBase::s_turret->m_heading = TurretShootPosition::WhiteLine;
        break;
    }

    // TODO: update conversion functions so that we don't
    // have to deal with stupid ass ticks. whatever

    // set orientation
    std::cout << "heading: " << heading << std::endl;
    CommandBase::s_turret->setSetpoint(heading);
}

void cAssignTargetBoiler::Execute()
{
	std::cout << CommandBase::s_turret->m_heading << std::endl;
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
	for(int i = 0; i < 100; i++) {
		std::cout << "Interrupted" << std::endl;
	}
    LOG_INFO("interrupted cAssignTargetBoiler");
    End();
}

cAssignTargetBoiler::~cAssignTargetBoiler()
{
    // TODO Auto-generated destructor stub
}

