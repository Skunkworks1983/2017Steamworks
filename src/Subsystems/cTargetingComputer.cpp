/*
 * cTargetingComputer.cpp
 *
 *  Created on: Jan 28, 2017
 *      Author: Mike
 */

#include "cTargetingComputer.h"

	cTargetingComputer::cTargetingComputer():
		Subsystem("cTargetingComputer")
	{
	}

	bool cTargetingComputer::CheckIfInGoal(double distance, double horizontalVelocity, double v0) {
		double vy = v0 * sin(SHOOTER_VERTICAL_ANGLE);
		double vx = v0 * cos(SHOOTER_VERTICAL_ANGLE);
//		double vz = v0 * cos(shooterAzimuth); to be implemented later!
		double x = 0;
		double y = shooterHeight;
		double previousy;
		bool inGoal = false;
		double timeIncrement = .01;
		double t;
		int i = 1;
		for (t = 0; t < 100; t += timeIncrement) { // will do the following 100 times, incrementing by timeIncrement seconds, for a total of 100 seconds into the future
			double vTotal = sqrt(vx * vx + vy * vy);
			double dragForce = BALL_DRAG_COEFFICIENT * vTotal;
			double fx = (-dragForce * vx / vTotal);
			double fy = (-dragForce * vx / vTotal);
			vx += (fx * timeIncrement / BALL_MASS);
			vy += fy * timeIncrement / BALL_MASS + GEE * timeIncrement;
			previousy = y;
			x += vx * timeIncrement;
			y += vy * timeIncrement;

			/*
			std::cout << "x" << i << " is " << x << ", " "y" << i << " is " << y << std::endl;
			std::cout << "vx" << i << " is " << vx << ", " "vy" << i << " is " << vy << std::endl;
			std::cout << i << " increments have happened" << std::endl;
			i++;
			for if you want to check what is happening
			*/
			if ((y < previousy) && (2.4 < y) && (y < 2.5) && (distance-RIM_RADIUS < x) && (x < distance + RIM_RADIUS)) { // if the ball descended into the radius of the goal
				inGoal = true;
				break;
			}
			//failure cases
			if (x > (distance + RIM_RADIUS)) { // if the ball passes the far rim
				failureReason = "went too far";
				break;
			}
			if (x > ( distance - RIM_RADIUS) && y < 2.46) { //if the ball is below the rim
				failureReason = "didn't go high enough";
				break;
			}
			if (x < distance - RIM_RADIUS && y < .5) {
				failureReason = "didn't go far enough";
				break;
			}

			if (distance -.1 < x && x < distance + .1) {
				heightAtCenter = y;
			}
		}
		return inGoal;


	}


