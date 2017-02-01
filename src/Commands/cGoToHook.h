/*
 * cGoToHook.h
 *
 *  Created on: Jan 27, 2017
 *      Author: Mike
 */

#ifndef SRC_COMMANDS_CGOTOHOOK_H_
#define SRC_COMMANDS_CGOTOHOOK_H_
#include "CommandBase.h"
#define ARM_ANGLE ((70*3.14)/180) // This is in radians. Placeholder atm since the game manual is v unclear. Also, this is the angle each arm is away from the perpindicular, not parallel.
#define DISTANCE_TO_RECOVERY_POINT 5 //placeholder! In meters
#define anglePerpindicularGoalRecoveryPoint ((70*3.14)/180) // placeholder!
#define GOAL_Y_POS_FROM_RIGHT_REC_POINT 10 //same!
#define GOAL_Y_POS_FROM_LEFT_REC_POINT -10 //same!
#define DISTANCE_FROM_REC_POINT_TO_PIVOT_POINT 10 //same!
/*
 * when angle variables are named, the naming structure is like this:
 *
 * angleABC
 *            A
 *           /
 *          /
 *         /
 *        /
 *       /
 *     B/____________C
 *
 */

class cGoToHook: public CommandBase
{
private:

	bool isBehindArms;
	double angleFromWall;
	double distanceFromPivotPoint;
	bool isBehindRightArm = false;
	bool isBehindLeftArm = false;
	bool isToRight = false;
	bool isToLeft = false;
	bool goalIsInView = true	;

public:
	cGoToHook();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();



};




#endif /* SRC_COMMANDS_CGOTOHOOK_H_ */
