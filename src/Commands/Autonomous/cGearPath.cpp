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

}
void cGearPath::Execute() {
	//a^2 = b^2 + c^2 - 2*b*c*cos(A)
	//cos(A) = ((- a * a + b * b + c * c) / 2 * b * c)
	double leftDistance = CommandBase::s_drivebase->GetLeftDistance();
	double rightDistance = CommandBase::s_drivebase->GetRightDistance();
	double angleRobotPegWall;
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

	angleRobotPegWall = acos((-distanceshortSensorLongDistance * distanceshortSensorLongDistance + distanceBetweenSensedDistances * distanceBetweenSensedDistances + shorterDistance * shorterDistance)/(2 * distanceBetweenSensedDistances * shorterDistance));
	double distanceToPeg = (leftDistance + rightDistance)/2;

	if (angleRobotPegWall < .5) { //if we're at a negligible angle from the wall
		AutoBase::s_angleRobotPivotPointPeg = 0;
		AutoBase::s_distanceToPivotPoint = distanceToPeg;
		AutoBase::s_angleRobotPivotPointPeg = 0;
	}

	//this part figures out the angle the robot must turn followed by the distance it must drive followed by the angle it must turn.

	double anglePivotPointPegRobot = (angleRobotPegWall - 3.14/2);

	AutoBase::s_distanceToPivotPoint = sqrt(distanceToPeg*distanceToPeg + DISTANCE_FROM_PEG_TO_PIVOT_POINT * DISTANCE_FROM_PEG_TO_PIVOT_POINT - 2 * distanceToPeg * DISTANCE_FROM_PEG_TO_PIVOT_POINT * cos(anglePivotPointPegRobot));

	AutoBase::s_angleRobotPivotPointPeg = acos((-DISTANCE_FROM_PEG_TO_PIVOT_POINT * DISTANCE_FROM_PEG_TO_PIVOT_POINT + AutoBase::s_distanceToPivotPoint * AutoBase::s_distanceToPivotPoint + distanceToPeg * distanceToPeg) / (2 * distanceToPeg * AutoBase::s_distanceToPivotPoint));

	AutoBase::s_angleRobotPivotPointPeg = (3.14 - AutoBase::s_angleRobotPivotPointPeg - anglePivotPointPegRobot);

	AutoBase::s_angleRobotPivotPointPeg = ((AutoBase::s_angleRobotPivotPointPeg * 180)/3.14);
	AutoBase::s_distanceToPivotPoint = ((AutoBase::s_distanceToPivotPoint * 180)/3.14); //turns out turndegree turns degrees, not radians
	AutoBase::s_angleRobotPivotPointPeg = ((AutoBase::s_angleRobotPivotPointPeg * 180)/3.14);

	if (leftDistance == longerDistance) { //does it need to turn left then right, or right then left? This figures this out.
		AutoBase::s_angleRobotPivotPointPeg = AutoBase::s_angleRobotPivotPointPeg * -1;
	} else {
		AutoBase::s_angleRobotPivotPointPeg = AutoBase::s_angleRobotPivotPointPeg * -1;
	}
}
bool cGearPath::IsFinished() {
	return true;
}
void cGearPath::End() {

}
void cGearPath::Interrupted() {

}
