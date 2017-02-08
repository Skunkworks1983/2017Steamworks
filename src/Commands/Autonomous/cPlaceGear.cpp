/*
 * cPlaceGear.cpp
 *
 *  Created on: Feb 4, 2017
 *      Author: Mike
 */

#include <Commands/Autonomous/cPlaceGear.h>
#include "cTurnDegree.h"
#include "cSimpleDriveForward.h"
#include "AutoBase.h"



cPlaceGear::cPlaceGear() { //ONLY CREATE THIS WHEN IN POSITION PLS
	//these commands don't actually do anything atm. Implement the arguments above when they do.
	AddSequential(new cTurnDegree(AutoBase::angleTapeRobotPivotPoint)); //assuming we're pointing directly at the tape. which i shouldnt do. fix later
	AddSequential(new cSimpleDriveForward()); //BELLA HAS GOT TO FIX THIS OR SO HELP ME GOSH;put this as the argument: AutoBase::distanceToPivotPoint
	AddSequential(new cTurnDegree(-(3.14 - AutoBase::angleRobotPivotPointGoal))); // it has to turn -(180 degrees - the angle)
	AddSequential(new cSimpleDriveForward()); //see above; put this as argument: DISTANCE_FROM_PIVOT_POINT_TO_GOAL

}

cPlaceGear::~cPlaceGear() {
	// TODO Auto-generated destructor stub
}

