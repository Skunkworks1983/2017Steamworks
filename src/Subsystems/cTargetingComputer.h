/*
 * cTargetingComputer.h
 *
 *  Created on: Jan 28, 2017
 *      Author: Mike
 */

#ifndef SRC_SUBSYSTEMS_CTARGETINGCOMPUTER_H_
#define SRC_SUBSYSTEMS_CTARGETINGCOMPUTER_H_
#include "Commands/Subsystem.h"
#include <math.h>
#include <iostream>
#define GEE (-9.8)
#define SHOOTER_VERTICAL_ANGLE ((70*3.14)/180) //degrees, but converted to radians
#define RIM_RADIUS .23605 //high goal radius
#define	SHOOTER_HEIGHT 1.6 //assumed shooter height. Subject to change. inb4 did you just assume my robot's height
#define BALL_DRAG_COEFFICIENT 0.0719 // retrieved from previously mentioned link. Not 100% sure how it was calculated.
#define BALL_MASS 0.074
//https://www.desmos.com/calculator/uo20oacldq is a very useful resource


//The point of this file is to find a working trajectory to launch a ball into the high goal, accounting for air resistance, horizontal motion, and distance from the goal.
//At the moment, it does not take into account horizontal velocity in any direction but towards the goal. It also does not take into account the azimuth of the turret.


class cTargetingComputer : public Subsystem
{
private:

	double shooterHeight = .6;
public:
	double heightAtCenter = 0;
	std::string failureReason = "this is a placeholder";
	cTargetingComputer();
	bool CheckIfInGoal(double distance, double horizontalVelocity, double v0);
	double CheckDistanceFromCenter(double distance, double horizontalVelocity);



};



#endif /* SRC_SUBSYSTEMS_TRAJECTORY_H_ */




#endif /* SRC_SUBSYSTEMS_CTARGETINGCOMPUTER_H_ */
