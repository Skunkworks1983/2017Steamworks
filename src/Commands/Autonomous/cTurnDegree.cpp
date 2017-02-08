/*
 * cTurnDegree.cpp
 *
 *  Created on: Jan 28, 2017
 *      Author: s-4036956
 */

#include <Commands/Autonomous/cTurnDegree.h>
#include <CommandBase.h>
#include <Subsystems/cDriveBase.h>

cTurnDegree::cTurnDegree(double targetAngle)
{
    targetAngle = 135; //we gotta change this
    angleRemaining = 0; //this is ok
}

void cTurnDegree::Initialize()
{
    //driveBase->setTargetAngle(targetAngle);
    //TODO gotta make that setTargetAngle class

}

void cTurnDegree::Execute()
{

}

bool cTurnDegree::IsFinished()
{
    return false;
}

void cTurnDegree::End()
{

}

void cTurnDegree::Interrupted()
{

}

