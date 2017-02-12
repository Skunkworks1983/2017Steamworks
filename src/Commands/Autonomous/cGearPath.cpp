/*
 * cGearPath.cpp
 *
 *  Created on: Feb 2, 2017
 *      Author: Mike
 */
#include "cGearPath.h"
#include "cSimpleDriveForward.h"
#include "Subsystems/cDriveBase.h"

cGearPath::cGearPath() {

}

cGearPath::~cGearPath() {

}

void cGearPath::FindGearPath() {
		double leftDistance = CommandBase::s_drivebase->GetLeftDistance();
		double rightDistance = CommandBase::s_drivebase->GetRightDistance();
		//my god this is ugly. All it does is find angleRobotTapeWall using distance sensors. Seriously. Ugh.

		double distanceFromCenterOfRotationToLeftDistanceSensed = sqrt(leftDistance * leftDistance + DISTANCE_FROM_DISTANCE_SENSORS_TO_CENTER_OF_ROTATION * DISTANCE_FROM_DISTANCE_SENSORS_TO_CENTER_OF_ROTATION - 2 * DISTANCE_FROM_DISTANCE_SENSORS_TO_CENTER_OF_ROTATION * leftDistance * cos(angleDistanceSensedDistanceSensorCenterOfRotation));
		double distanceFromCenterOfRotationToRightDistanceSensed = sqrt(rightDistance * rightDistance + DISTANCE_FROM_DISTANCE_SENSORS_TO_CENTER_OF_ROTATION * DISTANCE_FROM_DISTANCE_SENSORS_TO_CENTER_OF_ROTATION - 2 * DISTANCE_FROM_DISTANCE_SENSORS_TO_CENTER_OF_ROTATION * rightDistance * cos(angleDistanceSensedDistanceSensorCenterOfRotation));

		double angleLeftDistanceSensorCenterOfRotationLeftDistanceSensed = acos((-leftDistance * leftDistance + distanceFromCenterOfRotationToLeftDistanceSensed * distanceFromCenterOfRotationToLeftDistanceSensed + DISTANCE_FROM_DISTANCE_SENSORS_TO_CENTER_OF_ROTATION * DISTANCE_FROM_DISTANCE_SENSORS_TO_CENTER_OF_ROTATION)/ 2 * DISTANCE_FROM_DISTANCE_SENSORS_TO_CENTER_OF_ROTATION * distanceFromCenterOfRotationToLeftDistanceSensed);
		double angleRightDistanceSensorCenterOfRotationRightDistanceSensed = acos((-rightDistance * rightDistance + distanceFromCenterOfRotationToLeftDistanceSensed * distanceFromCenterOfRotationToRightDistanceSensed + DISTANCE_FROM_DISTANCE_SENSORS_TO_CENTER_OF_ROTATION * DISTANCE_FROM_DISTANCE_SENSORS_TO_CENTER_OF_ROTATION)/ 2 * DISTANCE_FROM_DISTANCE_SENSORS_TO_CENTER_OF_ROTATION * distanceFromCenterOfRotationToRightDistanceSensed);

		double angleLeftDistanceSensedCenterOfRotationRightDistanceSensed = angleLeftDistanceSensorCenterOfRotationRightDistanceSensor - angleRightDistanceSensorCenterOfRotationRightDistanceSensed - angleLeftDistanceSensorCenterOfRotationLeftDistanceSensed;
		double distanceBetweenLeftDistanceRightDistance = sqrt(distanceFromCenterOfRotationToLeftDistanceSensed * distanceFromCenterOfRotationToLeftDistanceSensed + distanceFromCenterOfRotationToRightDistanceSensed * distanceFromCenterOfRotationToRightDistanceSensed - 2 * distanceFromCenterOfRotationToRightDistanceSensed * distanceFromCenterOfRotationToLeftDistanceSensed);

		double angleRobotTapeWall;

		if (leftDistance > rightDistance) {
			angleRobotTapeWall = acos((-distanceFromCenterOfRotationToRightDistanceSensed * distanceFromCenterOfRotationToRightDistanceSensed + distanceFromCenterOfRotationToLeftDistanceSensed * distanceFromCenterOfRotationToLeftDistanceSensed + distanceBetweenLeftDistanceRightDistance * distanceBetweenLeftDistanceRightDistance)/2 * distanceBetweenLeftDistanceRightDistance * distanceFromCenterOfRotationToLeftDistanceSensed);
		} else {
			angleRobotTapeWall = acos((-distanceFromCenterOfRotationToLeftDistanceSensed * distanceFromCenterOfRotationToLeftDistanceSensed + distanceFromCenterOfRotationToRightDistanceSensed * distanceFromCenterOfRotationToRightDistanceSensed + distanceBetweenLeftDistanceRightDistance * distanceBetweenLeftDistanceRightDistance)/2 * distanceBetweenLeftDistanceRightDistance * distanceFromCenterOfRotationToRightDistanceSensed);
		}
		double distanceToTape = 1234; // get from camera (I hope). Marcador de posicion.
		//bool isBehindLeftArm; //not very necessary because it's not going to
		//bool isBehindRightArm; //same
		bool isInsideArms = true; //variable is useless for the moment.
/* THIS WHOLE SECTION IS PRETTY MUCH USELESS BC WE'RE NOT GOING TO BE RUNNING THIS CODE WHILE NOT INSIDE THE ARMS
		if (tapeXPos < 0) { //these are not effective ways to determine position. Fix later: use left and right distance sensors
			if (angleRobotTapeWall > ((3.14 / 2) + ARM_ANGLE)		// add comment
			&& leftDistanceSensor < rightDistanceSensor) {
				isBehindRightArm = true;
			} else {
				isInsideArms = true;
			}
		} else {
			if (tapeXPos > 0) {
				if (angleRobotTapeWall < ((3.14 / 2) - ARM_ANGLE)
						&& leftDistanceSensor > rightDistanceSensor) {
					isBehindLeftArm = true;
				} else {
						isInsideArms = true;
				}
			}

		}
	*/
/* this stuff is unnecessary as a primary goal. Might work on it later.
				if (currentPath.isBehindRightArm == true) {
						double angleRobotTapeRecoveryPoint = ((3.14) - angleRobotTapeWall - anglePerpindicularTapeRecoveryPoint); //180 degrees minus the two angles.
						double distanceToRecoveryPoint = sqrt(distanceToTape*distanceToTape + DISTANCE_TO_RECOVERY_POINT * DISTANCE_TO_RECOVERY_POINT
								- 2 * distanceToTape * DISTANCE_TO_RECOVERY_POINT * cos(angleRobotTapeRecoveryPoint)); // law of cosines. a^2 = b^2 + c^2 - 2*b*c*cos(A)
						double angleToRecoveryPoint = acos(-(distanceToRecoveryPoint * distanceToRecoveryPoint + DISTANCE_TO_RECOVERY_POINT * DISTANCE_TO_RECOVERY_POINT + distanceToTape * distanceToTape)
								/ 2 * DISTANCE_TO_RECOVERY_POINT * distanceToRecoveryPoint);
				}


				if (currentPath.isBehindLeftArm == true) {
						float angleRobotTapeWall; // get from camera, I hope.
						double distanceToTape; // get from camera (I hope)
						double angleRobotTapeRecoveryPoint = ((3.14/2) - angleRobotTapeWall - anglePerpindicularTapeRecoveryPoint); // 90 degrees minus the two angles.
						double distanceToRecoveryPoint = sqrt(distanceToTape*distanceToTape + DISTANCE_TO_RECOVERY_POINT * DISTANCE_TO_RECOVERY_POINT
								- 2 * distanceToTape * DISTANCE_TO_RECOVERY_POINT * cos(angleRobotTapeRecoveryPoint)); // law of cosines. a^2 = b^2 + c^2 - 2*b*c*cos(A)
						double angleTapeRobotRecoveryPoint = acos(-(distanceToRecoveryPoint * distanceToRecoveryPoint + DISTANCE_TO_RECOVERY_POINT * DISTANCE_TO_RECOVERY_POINT
								+ distanceToTape * distanceToTape) / 2 * DISTANCE_TO_RECOVERY_POINT * distanceToRecoveryPoint);
						double angleTapeRecoveryPointRobot = ((180 * 3.14)/180 - angleTapeRobotRecoveryPoint - angleRobotTapeRecoveryPoint);
						double angleRobotRecoveryPointPivotPoint = (angleTapeRecoveryPointRobot + anglePivotPointRecoveryPointTape);

					}
					*/
		if (isInsideArms == true) {
			//this part figures out the angle the robot must turn followed by the distance it must drive followed by the angle it must turn.
			double anglePivotPointTapeRobot = (3.14 - angleWallTapePivotPoint -	 angleRobotTapeWall);
			AutoBase::s_distanceToPivotPoint = sqrt(distanceToTape*distanceToTape + DISTANCE_FROM_TAPE_TO_PIVOT_POINT * DISTANCE_FROM_TAPE_TO_PIVOT_POINT
			- 2 * distanceToTape * DISTANCE_FROM_TAPE_TO_PIVOT_POINT * cos(anglePivotPointTapeRobot)); // law of cosines. a^2 = b^2 + c^2 - 2*b*c*cos(A) //this ends up being used
			AutoBase::s_angleTapeRobotPivotPoint = acos((-DISTANCE_FROM_TAPE_TO_PIVOT_POINT * DISTANCE_FROM_TAPE_TO_PIVOT_POINT
			+ AutoBase::s_distanceToPivotPoint * AutoBase::s_distanceToPivotPoint + distanceToTape * distanceToTape) / (2 * distanceToTape * DISTANCE_FROM_TAPE_TO_PIVOT_POINT)); //this ends up being used
			//cos(A) = ((- a * a + b * b + c * c) / 2 * b * c)
			double angleRobotPivotPointTape = (3.14 - anglePivotPointTapeRobot -  AutoBase::s_angleTapeRobotPivotPoint);
			AutoBase::s_angleRobotPivotPointGoal = (angleRobotPivotPointTape + angleGoalPivotPointTape); //this ends up being used

			AutoBase::s_distanceToPivotPoint = ((AutoBase::s_distanceToPivotPoint * 180)/3.14); //turns out turndegree turns degrees
			AutoBase::s_angleTapeRobotPivotPoint = ((AutoBase::s_angleTapeRobotPivotPoint * 180)/3.14);
			AutoBase::s_angleRobotPivotPointGoal = ((AutoBase::s_angleRobotPivotPointGoal * 180)/3.14);


		}
}
