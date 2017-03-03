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
#include <Commands/FuelIndexer/cRunFuelIndexer.h>
#include <Commands/Shooter/cShootWhenReady.h>

double AutoBase::s_angleTapeRobotPivotPoint = 0;
double AutoBase::s_distanceToPivotPoint = 0;
double AutoBase::s_angleRobotPivotPointGoal = 0;

AutoBase::AutoBase()
{

}

AutoBase* AutoBase::configureAutonomous()
{
    AutoBase* commands = new AutoBase();

    // get the current alliance through driver station
    alliance = DriverStation::GetInstance().GetAlliance();

    // commands for moving to the lifts
    switch(startPosition)
    {
    case POS_1:
        //

        /*
        commands->AddSequential(commands->goLift1());
        commands->AddSequential(commands->placeGear());

        if(USE_SHOOTER && USE_TURRET)
        {
            commands->AddSequential(new cSpinUpShooter());
            commands->AddParallel(new cRotateTurret(30));
            commands->AddParallel(new cShootWhenReady(30));
        }
        */

        break;
    case POS_2:
        /*
        commands->AddSequential(commands->placeGear());

        if(USE_SHOOTER && USE_TURRET)
        {
            commands->AddSequential(new cSpinUpShooter());
            commands->AddParallel(new cRotateTurret(30));
            commands->AddParallel(new cShootWhenReady(30));
        }
        */

        break;
    case POS_3:
        /*
        commands->AddSequential(commands->goLift3());
        commands->AddSequential(commands->placeGear());
        */

        break;
    }

    // return the commands
    return commands;
}

AutoBase::~AutoBase()
{
    delete this;
}

eStartingPosition AutoBase::getStartingPosition()
{
    DigitalInput* port6 = new DigitalInput(6);
    DigitalInput* port7 = new DigitalInput(7);

    eStartingPosition startPos = (eStartingPosition) POS_2;

    if(port6->Get())
    {
        startPos = POS_1;
    }

    return startPos;

    /*
     // read from the dial
     std::vector<DigitalInput*> inputs;

     // get inputs from pins
     for(int i = 0; i < START_POS_SELECTION_DIGITS; i++)
     {
     inputs.push_back(new DigitalInput(i));
     }

     // assemble number for starting position
     eStartingPosition startPos = (eStartingPosition) 0;
     int digit = 1;

     // no idea why this needs to be unsigned
     for(unsigned int i = 0; i < inputs.size(); i++)
     {
     if(inputs[i]->Get())
     {
     startPos = (eStartingPosition) (startPos | digit);
     }

     digit = digit << 1;
     }

     // return a value
     return startPos;
     */
}

eAlliance AutoBase::getAlliance()
{
    // assemble number for starting position
    eAlliance alliance = (eAlliance) 0;

    // doesnt do anything yet

    // return a value
    return alliance;
}
