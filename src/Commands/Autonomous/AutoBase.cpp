/*
 * AutoBase.cpp
 *
 *  Created on: Jan 26, 2017
 *      Author: s-4036956
 */
#include <Commands/FuelIndexer/cRunFuelIndexer.h>
#include "AutoBase.h"
#include "cTurnDegree.h"
#include "cSimpleDriveForward.h"
#include "cGearPath.h"
#include <RobotMap.h>
#include <Commands/Shooter/cSpinUpShooter.h>
#include <Commands/Turret/cRotateTurret.h>

double AutoBase::s_angleTapeRobotPivotPoint = 0;
double AutoBase::s_distanceToPivotPoint = 0;
double AutoBase::s_angleRobotPivotPointGoal = 0;

AutoBase::AutoBase()
{
    m_driveToLine = new CommandGroup;
    m_driveToLine->AddSequential(new cSimpleDriveForward(100, true));
}
AutoBase* configureAutonomous()
{
    AutoBase* commands = new AutoBase();

    // shooter & turret control code
    if(USE_SHOOTER && USE_TURRET)
    {
        // spin up the shooter to prepare to shoot balls
        commands->AddParallel(new cSpinUpShooter());

        // start vision code to find the boiler
        commands->AddParallel(new cRotateTurret(30));
    }

    // commands for moving to the lifts
    switch(startPosition)
    {
    case POS_1:
        commands->AddSequential(commands->goLift1());
        commands->AddSequential(commands->placeGear());
        break;
    case POS_2:
        commands->AddSequential(commands->placeGear());
        break;
    case POS_3:
        commands->AddSequential(commands->goLift3());
        commands->AddSequential(commands->placeGear());
        break;
    }

    // load balls into the shooter
    commands->AddSequential(new cRunFuelIndexer(1, 30));

    // return the commands
    return commands;
}

AutoBase::~AutoBase()
{
    delete this;
}
