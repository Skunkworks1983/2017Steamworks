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
#include <Commands/Turret/cSetTurretSetpoint.h>
#include <Commands/Shooter/cShootWhenReady.h>

#include <Commands/DriveBase/cDriveStraight.h>

#include <Commands/Autonomous/cWait.h>
#include <Commands/Turret/cAssignTargetBoiler.h>
#include <Commands/Shooter/cShootPID.h>
#include <Commands/Autonomous/cWait.h>
#include <Commands/FuelConveyor/cRunFuelConveyor.h>

double AutoBase::s_angleTapeRobotPivotPoint = 0;
double AutoBase::s_distanceToPivotPoint = 0;
double AutoBase::s_angleRobotPivotPointGoal = 0;

// i feel like this isn't very safe
DigitalInput* AutoBase::m_d1 = NULL;
DigitalInput* AutoBase::m_d2 = NULL;



AutoBase::AutoBase()
{

}

AutoBase* AutoBase::configureAutonomous()
{
    // initialize commands
    AutoBase* commands = new AutoBase();

    // commands for moving to the lifts
    switch(AutoBase::getStartingPosition())
    {
    case POS_BOILER:
    	commands->AddSequential(commands->goFarBoiler());
    	break;
    case POS_CENTER:
    	commands->AddSequential(commands->goLiftCenter());
        break;
    case POS_RETRIEVAL:
    	commands->AddSequential(commands->goFarBoiler());
        break;
    default:
        break;
    }

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

    if(m_d1->Get() && m_d2->Get()) {
    	startingPosition = POS_CENTER;
    } else if(m_d1->Get()) {
    	startingPosition = POS_BOILER;
    } else if(m_d2->Get()) {
    	startingPosition = POS_RETRIEVAL;
    }

    return startingPosition;
}

eAlliance AutoBase::getAlliance()
{
    frc::DriverStation::Alliance dsAlliance = DriverStation::GetInstance().GetAlliance();
    eAlliance alliance = (eAlliance) dsAlliance;

    return alliance;
}
