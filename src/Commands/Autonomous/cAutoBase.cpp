/*
 * cAutoBase.cpp
 *
 *  Created on: Jan 26, 2017
 *      Author: s-4036956
 */

#include "WPILib.h"
#include "cAutoBase.h"
#include "cTurnDegree.h"
#include "cSimpleDriveForward.h"
#include "cGearPath.h"
#include <RobotMap.h>
#include <Commands/Shooter/cSpinUpShooter.h>
#include <Commands/Turret/cRotateTurret.h>
#include <Commands/FuelIndexer/cRunFuelIndexer.h>
#include <Commands/Shooter/cShootWhenReady.h>

double cAutoBase::s_angleTapeRobotPivotPoint = 0;
double cAutoBase::s_distanceToPivotPoint = 0;
double cAutoBase::s_angleRobotPivotPointGoal = 0;

cAutoBase::cAutoBase()
{

}

cAutoBase* cAutoBase::configureAutonomous()
{
    // initialize commands
    cAutoBase* commands = new cAutoBase();

    // config autonomous commands
    switch(cAutoBase::getStartingPosition())
    {
    case POS_1:

        break;
    case POS_2:

        break;
    case POS_3:

        break;
    default:

        break;
    }

    // return the commands
    return commands;
}

cAutoBase::~cAutoBase()
{
    delete this;
}

eStartingPosition cAutoBase::getStartingPosition()
{
    eStartingPosition startingPosition = (eStartingPosition) POS_2;

    // we only need to check one pin, but just for future purposes
    // we'll go through the entire motion of checking all the pins

    // quick note: when assembling the binary number, recall that
    // numbers read right to left, in terms of digit order. d1 would
    // be far right, while higher digits would follow to the right.

    // d2 d1

    return startingPosition;
}

eAlliance cAutoBase::getAlliance()
{
    frc::DriverStation::Alliance dsAlliance = DriverStation::GetInstance().GetAlliance();
    eAlliance alliance = (eAlliance) dsAlliance;

    return alliance;
}
