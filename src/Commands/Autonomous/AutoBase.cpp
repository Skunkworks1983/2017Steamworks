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
double AutoBase::s_angleRobotPivotPointGoal = 0;

AutoBase::AutoBase()
{

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
    case POS_1:
        commands->AddSequential(commands->goLift1());
        commands->AddSequential(commands->placeGear());
        break;
    case POS_2:
        //commands->AddSequential(commands->placeGear()); once we know what we're doing
    	std::cout << "POS 2" << std::endl;
    	commands->AddSequential(commands->deadLift2());
        break;
    case POS_3:
        commands->AddSequential(commands->goLift3());
        commands->AddSequential(commands->placeGear());
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

eStartingPosition AutoBase::getStartingPosition()
{
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
}

eAlliance getAlliance()
{
    // assemble number for starting position
    eAlliance alliance = (eAlliance) 0;

    // doesnt do anything yet

    // return a value
    return alliance;
}
