/*
 * cGoToHook.cpp
 *
 *  Created on: Jan 27, 2017
 *      Author: Mike
 */
#include "cGoToHook.h"
#include <Commands/cRunTankDrive.h>
#include <cDriveBase.h>
#include <OI.h>

cGoToHook::cGoToHook() {

}
void cGoToHook::Initialize() {
	bool goalIsInView; // this and everything that uses it should be replaced once I get a way to actually measure whether the goal is in view
	float goalXPos; // reflective tape's position in the image
	double leftDistanceSensor; // need to implement this from actual data.
	double rightDistanceSensor; //same tho
	float angleRobotGoalWall; // get from camera, I hope. Might be tricky af to get to coincide with distance, since both are based on apparent size, but that's why I'm not working on vision

	if (goalXPos < 0) { //these are not effective ways to determine position. Fix later: use left and right distance sensors
		if (angleRobotGoalWall > ((3.14/2) + ARM_ANGLE)				// add comment
				&& leftDistanceSensor < rightDistanceSensor) {
			isBehindRightArm = true;
		} else {
			isToRight = true;
		}
	} else {
		if (goalXPos > 0) {
				if (angleRobotGoalWall < ((3.14/2) - ARM_ANGLE)
						&& leftDistanceSensor > rightDistanceSensor) {
					isBehindLeftArm = true;
				} else {
					isToLeft = true;
				}
			}
		else {
			goalIsInView = false;
		}

}
}
void cGoToHook::Execute() {

	if (isBehindRightArm == true) {
		float angleRobotGoalWall; // get from camera, I hope. Might be tricky af to get to coincide with distance, since both are based on apparent size, but that's why I'm not working on vision
		double distanceToGoal; // get from camera (I hope)
		double angleRobotGoalRecoveryPoint = ((3.14) - angleRobotGoalWall - anglePerpindicularGoalRecoveryPoint); //180 degrees minus the two angles.
		double distanceToRecoveryPoint = sqrt(distanceToGoal*distanceToGoal + DISTANCE_TO_RECOVERY_POINT * DISTANCE_TO_RECOVERY_POINT
				- 2 * distanceToGoal * DISTANCE_TO_RECOVERY_POINT * cos(angleRobotGoalRecoveryPoint)); // law of cosines. a^2 = b^2 + c^2 - 2*b*c*cos(A)
		double angleToRecoveryPoint = acos(-(distanceToRecoveryPoint * distanceToRecoveryPoint + DISTANCE_TO_RECOVERY_POINT * DISTANCE_TO_RECOVERY_POINT + distanceToGoal * distanceToGoal)
				/ 2 * DISTANCE_TO_RECOVERY_POINT * distanceToRecoveryPoint);

		//TurnDegree(angleRobotGoalRecoveryPoint); can I implement these? Is that a thing?
		//DriveDistance(distanceToReccoveryPoint);
		//TurnDegree()
		//DriveDistance(DISTANCE_FROM_REC_POINT_TO_PIVOT_POINT)


	}

	if (isBehindLeftArm == true) {
		float angleRobotGoalWall; // get from camera, I hope. Might be tricky af to get to coincide with distance, since both are based on apparent size, but that's why I'm not working on vision
		double distanceToGoal; // get from camera (I hope)
		double angleRobotGoalRecoveryPoint = ((3.14/2) - angleRobotGoalWall - anglePerpindicularGoalRecoveryPoint); // 90 degrees minus the two angles.
		double distanceToRecoveryPoint = sqrt(distanceToGoal*distanceToGoal + DISTANCE_TO_RECOVERY_POINT * DISTANCE_TO_RECOVERY_POINT
				- 2 * distanceToGoal * DISTANCE_TO_RECOVERY_POINT * cos(angleRobotGoalRecoveryPoint)); // law of cosines. a^2 = b^2 + c^2 - 2*b*c*cos(A)
		double angleToRecoveryPoint = acos(-(distanceToRecoveryPoint * distanceToRecoveryPoint + DISTANCE_TO_RECOVERY_POINT * DISTANCE_TO_RECOVERY_POINT + distanceToGoal * distanceToGoal)
				/ 2 * DISTANCE_TO_RECOVERY_POINT * distanceToRecoveryPoint);

				//TurnDegree(angleRobotGoalRecoveryPoint); can I implement these? Is that a thing?
				//DriveDistance(distanceToReccoveryPoint);
				//TurnDegree()
				//DriveDistance(DISTANCE_FROM_REC_POINT_TO_PIVOT_POINT)
		}

}

	bool cGoToHook::IsFinished() {
		return false;
	}

	void cGoToHook::End() {

		}

	void cGoToHook::Interrupted() {

	}

