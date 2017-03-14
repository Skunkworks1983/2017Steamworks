/*
 * AutoBase.cpp
 *
 *  Created on: Jan 26, 2017
 *      Author: s-4036956
 */

#include <Commands/Autonomous/AutoBase.h>
#include "WPILib.h"
#include "cTurnDegree.h"
#include "cSimpleDriveForward.h"
#include "cGearPath.h"
#include <RobotMap.h>
#include <Commands/Shooter/cSpinUpShooter.h>
#include <Commands/Turret/cRotateTurret.h>
#include <Commands/Turret/cAssignTargetBoiler.h>
#include <Commands/FuelConveyor/cRunFuelConveyor.h>
#include <Commands/Shooter/cShootWhenReady.h>
#include <Commands/Shooter/cShootPID.h>

#include <Commands/Autonomous/cWait.h>

double AutoBase::s_angleTapeRobotPivotPoint = 0;
double AutoBase::s_distanceToPivotPoint = 0;
double AutoBase::s_angleRobotPivotPointGoal = 0;

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
    case POS_CLOSE:

        break;
    case POS_MIDDLE:

        break;
    case POS_FAR:

        break;
    }

    waitThenIndex->AddSequential(new cWait(2));
    waitThenIndex->AddSequential(new cRunFuelConveyor());

    commands->AddSequential(new cAssignTargetBoiler(LIFT_MIDDLE));
    commands->AddParallel(new cShootPID());
    commands->AddParallel(waitThenIndex);

    // return the commands
    return commands;
}

AutoBase::~AutoBase()
{
    delete this;
}

eStartingPosition AutoBase::getStartingPosition()
{
    eStartingPosition startingPosition = (eStartingPosition) POS_MIDDLE;

    // temporary. auto selection for practice bot, using two switches
    // instead of one three state switch

    // for two switches (bad explanation):
    // one switch will represent whether or not the second switch
    // will be used. depending on whether or not the second switch
    // is on, we select the outer positions but if the first switch
    // is off then we default to position two

    DigitalInput* d1 = new DigitalInput(AUTO_SELECTION_PORT1);
    DigitalInput* d2 = new DigitalInput(AUTO_SELECTION_PORT2);

    if(d1->Get())
    {
        startingPosition = d2->Get() ? POS_CLOSE : POS_MIDDLE;
    }

    return startingPosition;
}

eAlliance AutoBase::getAlliance()
{
    frc::DriverStation::Alliance dsAlliance = DriverStation::GetInstance().GetAlliance();
    eAlliance alliance = (eAlliance) dsAlliance;

    return alliance;
}
