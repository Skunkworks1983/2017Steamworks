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

double AutoBase::s_angleTapeRobotPivotPoint = 0;
double AutoBase::s_distanceToPivotPoint = 0;
double AutoBase::s_angleRobotPivotPointGoal = 0;

AutoBase::AutoBase() {


    m_driveToLine = new CommandGroup;
    m_driveToLine->AddSequential(new cSimpleDriveForward(100, true));


}
AutoBase::~AutoBase()
{

}
