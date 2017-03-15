/*
 * AutoBase.cpp
 *
 *  Created on: Jan 26, 2017
 *      Author: s-4036956
 */

#include "WPILib.h"
#include "AutoBase.h"
#include "cTurnDegree.h"
#include "cSimpleDriveForward.h"
#include "cGearPath.h"
#include <RobotMap.h>
#include <Commands/Shooter/cSpinUpShooter.h>
#include <Commands/Turret/cRotateTurret.h>
#include <Commands/Turret/cAssignTargetBoiler.h>
#include <Commands/Turret/cSetTurretSetpoint.h>
#include <Commands/FuelConveyor/cRunFuelConveyor.h>
#include <Commands/Shooter/cShootWhenReady.h>
#include <Commands/Shooter/cShootPID.h>

#include <Commands/DriveBase/cDriveStraight.h>

#include <Commands/Autonomous/cWait.h>

double AutoBase::s_angleTapeRobotPivotPoint = 0;
double AutoBase::s_distanceToPivotPoint = 0;
double AutoBase::s_angleRobotPivotPointPeg = 0;

AutoBase::AutoBase()
{

}
AutoBase* AutoBase::configureAutonomous()


{
    // initialize commands
    AutoBase* commands = new AutoBase();

    CommandGroup* waitThenIndex = new CommandGroup();

    // config autonomous commands
    switch(AutoBase::getStartingPosition())
    {
    case POS_BOILER:
    	break;

    case POS_CENTER:
    	break;

    case POS_RETRIEVAL:
    	break;

        // spin up the shooter to prepare to shoot balls
        //commands->AddParallel(new cSpinUpShooter());

        // start vision code to find the boiler

        //commands->AddParallel(new cRotateTurret(30));
    }

    // commands for moving to the lifts
    switch(startPosition)
    {
    case POS_BOILER:
        commands->AddSequential(commands->goLiftBoiler());
        //commands->AddSequential(commands->cPlaceGear());
        break;
    case POS_CENTER:
        commands->AddSequential(commands->goLiftCenter());
        //commands->AddSequential(commands->cPlaceGear());
        break;
    case POS_RETRIEVAL:
        commands->AddSequential(commands->goLiftRetrieval());
        //commands->AddSequential(commands->cPlaceGear());

        break;
    }
    //waitThenIndex->AddSequential(new cWait(6));
    //waitThenIndex->AddSequential(new cRunFuelConveyor());

    //commands->AddSequential(new cAssignTargetBoiler(LIFT_MIDDLE));
    //commands->AddParallel(new cShootPID());
    //commands->AddParallel(waitThenIndex);

    /*commands->AddParallel(new cDriveStraight(7250*1.75, 0.4));
    commands->AddParallel(new cSetTurretSetpoint(2050));
    commands->AddParallel(new cShootPID(150));
    commands->AddParallel(waitThenIndex);*/

    // return the commands
    return commands;
}

AutoBase::~AutoBase()
{
    delete this;
}

eStartingPosition AutoBase::getStartingPosition()
{
    eStartingPosition startingPosition = (eStartingPosition) POS_CENTER;

    // we only need to check one pin, but just for future purposes
    // we'll go through the entire motion of checking all the pins

    // quick note: when assembling the binary number, recall that
    // numbers read right to left, in terms of digit order. d1 would
    // be far right, while higher digits would follow to the right.

    // d2 d1

    return startingPosition;
}

eAlliance AutoBase::getAlliance()
{
    frc::DriverStation::Alliance dsAlliance = DriverStation::GetInstance().GetAlliance();
    eAlliance alliance = (eAlliance) dsAlliance;

    return alliance;
}
