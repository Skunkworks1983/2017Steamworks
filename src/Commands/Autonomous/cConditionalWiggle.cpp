/*
 * cConditionalWiggle.cpp
 *
 *  Created on: Mar 31, 2017
 *      Author: S-2508366
 */

// this command does not include the cwait
// i can confirm we do not include the cwait
#include <Commands/Autonomous/cConditionalWiggle.h>
#include <CommandBase.h>

#include <Commands/DriveBase/cDriveStraight.h>
#include <Commands/Turret/cAssignTargetBoiler.h>
#include <Commands/Shooter/cShootPID.h>
#include <Commands/Autonomous/cWait.h>
#include <Commands/FuelConveyor/cRunFuelConveyor.h>
#include <Commands/DriveBase/cTurnAngle.h>
#include <Commands/Autonomous/AutoBase.h>

cConditionalWiggle::cConditionalWiggle()
{
    m_commands = new CommandGroup();
}

cConditionalWiggle::~cConditionalWiggle()
{

}

void cConditionalWiggle::Initialize()
{
    AutoBase::m_wiggle = CommandBase::s_gearCollector->isGearIn();
}

void cConditionalWiggle::Execute()
{

}

bool cConditionalWiggle::IsFinished()
{
    return true;
}

void cConditionalWiggle::End()
{

}

void cConditionalWiggle::Interrupted()
{
    End();
}
