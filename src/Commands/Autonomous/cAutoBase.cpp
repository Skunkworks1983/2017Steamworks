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
    case POS_CLOSE:

        break;
    case POS_MIDDLE:

        break;
    case POS_FAR:

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

eAlliance cAutoBase::getAlliance()
{
    frc::DriverStation::Alliance dsAlliance = DriverStation::GetInstance().GetAlliance();
    eAlliance alliance = (eAlliance) dsAlliance;

    return alliance;
}
