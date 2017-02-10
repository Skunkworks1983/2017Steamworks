/*
 * AutoBase.cpp
 *
 *  Created on: Jan 26, 2017
 *      Author: s-4036956
 */
#include "AutoBase.h"
#include "cTurnDegree.h"
#include "cSimpleDriveForward.h"


double AutoBase::angleTapeRobotPivotPoint = 0;
double AutoBase::distanceToPivotPoint = 0;
double AutoBase::angleRobotPivotPointGoal = 0;

AutoBase::AutoBase() {
    placeGear = new CommandGroup;

    placeGear->AddSequential(new cTurnDegree(AutoBase::angleTapeRobotPivotPoint)); //assuming we're pointing directly at the tape. which i shouldn't do. fix later
    placeGear->AddSequential(new cSimpleDriveForward(AutoBase::distanceToPivotPoint));
    placeGear->AddSequential(new cTurnDegree(-(3.14 - AutoBase::angleRobotPivotPointGoal))); // it has to turn -(180 degrees - the angle)
    placeGear->AddSequential(new cSimpleDriveForward(DISTANCE_FROM_PIVOT_POINT_TO_GOAL));

}

AutoBase::~AutoBase() {

}
