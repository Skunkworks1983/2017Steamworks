/*
 * cGearPath.cpp
 *
 *  Created on: Feb 2, 2017
 *      Author: Mike
 */
#include "AutoBase.h"
#include "cGearPath.h"
#include "cSimpleDriveForward.h"
#include "Subsystems/cDriveBase.h"

cGearPath::cGearPath() {

}

cGearPath::~cGearPath() {

}

void cGearPath::Initialize() {
	//a^2 = b^2 + c^2 - 2*b*c*cos(A)
	//cos(A) = ((- a * a + b * b + c * c) / 2 * b * c)
	double leftDistance = CommandBase::s_drivebase->GetLeftDistance();
	double rightDistance = CommandBase::s_drivebase->GetRightDistance();
	double angleRobotTapeWall;
	double longerDistance;
	double shorterDistance;
	if (leftDistance > rightDistance) {
		longerDistance = leftDistance;
		shorterDistance = rightDistance;
	} else {
		longerDistance = rightDistance;
		shorterDistance = leftDistance;
	}
	double distanceshortSensorLongDistance = sqrt(longerDistance * longerDistance + DISTANCE_BETWEEN_SONAR * DISTANCE_BETWEEN_SONAR);
	double angleLongDistanceShortSensorLongSensor = asin(longerDistance/distanceshortSensorLongDistance);
	double angleShortDistanceShortSensorLongSensor = (3.14/2 - angleLongDistanceShortSensorLongSensor);
	double distanceBetweenSensedDistances = sqrt(shorterDistance * shorterDistance + distanceshortSensorLongDistance * distanceshortSensorLongDistance - 2 * shorterDistance * distanceshortSensorLongDistance * cos(angleShortDistanceShortSensorLongSensor));
	angleRobotTapeWall = acos((-distanceshortSensorLongDistance * distanceshortSensorLongDistance + distanceBetweenSensedDistances * distanceBetweenSensedDistances + shorterDistance * shorterDistance)/(2 * distanceBetweenSensedDistances * shorterDistance));

	double distanceToTape = (leftDistance + rightDistance)/2;

	//this part figures out the angle the robot must turn followed by the distance it must drive followed by the angle it must turn.

	double anglePivotPointTapeRobot = (3.14 - angleWallTapePivotPoint -	 angleRobotTapeWall);

	AutoBase::s_distanceToPivotPoint = sqrt(distanceToTape*distanceToTape + DISTANCE_FROM_TAPE_TO_PIVOT_POINT * DISTANCE_FROM_TAPE_TO_PIVOT_POINT - 2 * distanceToTape * DISTANCE_FROM_TAPE_TO_PIVOT_POINT * cos(anglePivotPointTapeRobot));
	// law of cosines. a^2 = b^2 + c^2 - 2*b*c*cos(A)

	AutoBase::s_angleTapeRobotPivotPoint = acos((-DISTANCE_FROM_TAPE_TO_PIVOT_POINT * DISTANCE_FROM_TAPE_TO_PIVOT_POINT + AutoBase::s_distanceToPivotPoint * AutoBase::s_distanceToPivotPoint + distanceToTape * distanceToTape) / (2 * distanceToTape * DISTANCE_FROM_TAPE_TO_PIVOT_POINT));
	//cos(A) = ((- a * a + b * b + c * c) / 2 * b * c)

	double angleRobotPivotPointTape = (3.14 - anglePivotPointTapeRobot -  AutoBase::s_angleTapeRobotPivotPoint);

	AutoBase::s_angleRobotPivotPointGoal = (angleRobotPivotPointTape + angleGoalPivotPointTape);

	AutoBase::s_angleTapeRobotPivotPoint = ((AutoBase::s_angleTapeRobotPivotPoint * 180)/3.14);
	AutoBase::s_distanceToPivotPoint = ((AutoBase::s_distanceToPivotPoint * 180)/3.14); //turns out turndegree turns degrees, not radians
	AutoBase::s_angleRobotPivotPointGoal = ((AutoBase::s_angleRobotPivotPointGoal * 180)/3.14);

	if (leftDistance == longerDistance) {
		AutoBase::s_angleTapeRobotPivotPoint = AutoBase::s_angleTapeRobotPivotPoint * -1; //does it need to turn left then right, or right then left?
	} else {
		AutoBase::s_angleRobotPivotPointGoal = AutoBase::s_angleRobotPivotPointGoal * -1;
	}
}
void cGearPath::Execute() {

}
bool cGearPath::IsFinished() {
	return true;
}
void cGearPath::End() {

}
void cGearPath::Interrupted() {

}
