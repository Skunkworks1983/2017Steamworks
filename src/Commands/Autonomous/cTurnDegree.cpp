/*
 * cTurnDegree.cpp
 *
 *  Created on: Jan 28, 2017
 *      Author: s-4036956
 */

#include <Commands/Autonomous/cTurnDegree.h>
#include <CommandBase.h>
#include <Subsystems/cDriveBase.h>

cTurnDegree::cTurnDegree(double degree)
{
	m_targetAngle = 135; //we gotta change this
	m_angleRemaining = 0; //this is ok
}

void cTurnDegree::Initialize()
{
    //AutoBase->setTargetAngle(targetAngle);
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

