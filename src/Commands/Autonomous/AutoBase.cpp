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


AutoBase::AutoBase() {

    m_placeGear = new CommandGroup;
    m_placeGear->AddSequential(new cTurnDegree(AutoBase::s_angleTapeRobotPivotPoint)); //assuming we're pointing directly at the tape. which i shouldn't do. fix later
    m_placeGear->AddSequential(new cSimpleDriveForward(AutoBase::s_distanceToPivotPoint));
    m_placeGear->AddSequential(new cTurnDegree(-(3.14 - AutoBase::s_angleRobotPivotPointGoal))); // it has to turn -(180 degrees - the angle)
    m_placeGear->AddSequential(new cSimpleDriveForward(DISTANCE_FROM_PIVOT_POINT_TO_GOAL));

    m_driveToLine = new CommandGroup;
    m_driveToLine->AddSequential(new cSimpleDriveForward(100, true));


}

AutoBase::~AutoBase() {

}
