/*
 * AutoBase.cpp
 *
 *  Created on: Jan 26, 2017
 *      Author: s-4036956
 */

#include "AutoBase.h"
#include "cTurnDegree.h"
#include "cSimpleDriveForward.h"
#include "cGearPath.h"
#include <RobotMap.h>
#include <Commands/Shooter/cSpinUpShooter.h>
#include <Commands/Turret/cRotateTurret.h>
#include <Commands/FuelIndexer/cRunFuelIndexer.h>

double AutoBase::s_angleTapeRobotPivotPoint = 0;
double AutoBase::s_distanceToPivotPoint = 0;
double AutoBase::s_angleRobotPivotPointPeg = 0;

AutoBase::AutoBase()
{
    m_driveToLine = new CommandGroup;
    m_driveToLine->AddSequential(new cSimpleDriveForward(100, true));
}
AutoBase* AutoBase::configureAutonomous()
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
    case POS_BOILER:
        commands->AddSequential(commands->goLiftBoiler());
        break;
    case POS_CENTER:
        commands->AddSequential(commands->goLiftCenter());
        break;
    case POS_RETRIEVAL:
        commands->AddSequential(commands->goLiftRetrieval());
        break;
    }

    // load balls into the shooter
    commands->AddSequential(new cRunFuelIndexer());

    // return the commands
    return commands;
}

AutoBase::~AutoBase()
{
    delete this;
}
