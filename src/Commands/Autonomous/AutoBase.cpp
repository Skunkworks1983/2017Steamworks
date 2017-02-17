/*
 * AutoBase.cpp
 *
 *  Created on: Jan 26, 2017
 *      Author: s-4036956
 */
#include "AutoBase.h"
#include "cTurnDegree.h"
#include "cSimpleDriveForward.h"
#include <RobotMap.h>

double AutoBase::s_angleTapeRobotPivotPoint = 0;
double AutoBase::s_distanceToPivotPoint = 0;
double AutoBase::s_angleRobotPivotPointGoal = 0;

AutoBase::AutoBase()
{

}

AutoBase* configureAutonomous()
{
    AutoBase* commands = new AutoBase();

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

    return commands;
}

AutoBase::~AutoBase()
{
    delete this;
}
