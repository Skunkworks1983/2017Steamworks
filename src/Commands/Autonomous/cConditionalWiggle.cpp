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

cConditionalWiggle::cConditionalWiggle()
{
    m_commands = new CommandGroup();
}

cConditionalWiggle::~cConditionalWiggle()
{

}

void cConditionalWiggle::Initialize()
{
    float DRIVE_DISTANCE = -7250;
    float DRIVE_STRAIGHT_SPEED = 0.25;
    float DRIVE_TIMEOUT = 5.5;
    float TURN_TIMEOUT = 1.5;

    /*for(int i = 0; i < 100; i++)
        std::cout << "wiggle" << std::endl;*/

    m_commands->AddSequential(new cDriveStraight(-DRIVE_DISTANCE / 4, -DRIVE_STRAIGHT_SPEED, DRIVE_TIMEOUT));
    m_commands->AddSequential(new cTurnAngle(-20, 1.5));
    m_commands->AddSequential(new cTurnAngle(40, 1.5));
    m_commands->AddSequential(new cTurnAngle(-20, 1.5));
    m_commands->AddSequential(new cDriveStraight(DRIVE_DISTANCE / 4, DRIVE_STRAIGHT_SPEED, DRIVE_TIMEOUT));

    //std::cout << "SWITCH" << std::endl;
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
