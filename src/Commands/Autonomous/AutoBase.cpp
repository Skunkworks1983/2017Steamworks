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

AutoBase::AutoBase() {
    m_placeGear = new CommandGroup;
    m_placeGear->AddSequential(new cCenterTape());
    m_placeGear->AddSequential(new cGearPath());
    m_placeGear->AddSequential(new cTurnDegree(AutoBase::s_angleTapeRobotPivotPoint));
    m_placeGear->AddSequential(new cSimpleDriveForward(AutoBase::s_distanceToPivotPoint));
    m_placeGear->AddSequential(new cTurnDegree(AutoBase::s_angleRobotPivotPointGoal));
    m_placeGear->AddSequential(new cSimpleDriveForward(DISTANCE_FROM_PIVOT_POINT_TO_GOAL));

    m_driveToLine = new CommandGroup;
    m_driveToLine->AddSequential(new cSimpleDriveForward(100, true));


}

AutoBase::~AutoBase() {

}
