/*
 * cGearPath.h
 *
 *  Created on: Feb 2, 2017
 *      Author: Mike
 */

#ifndef SRC_COMMANDS_AUTONOMOUS_CGEARPATH_H_
#define SRC_COMMANDS_AUTONOMOUS_CGEARPATH_H_
#include <RobotMap.h>
#include "cAutoBase.h"
#include "CommandBase.h"
/*
 * This class uses the sonar sensors to determine the path the robot must take,
 * assuming the robot begins oriented at the camera (which it should be, since cCenterTape
 * is a thing). The path involves turning toward and driving to an arbitrary point directly
 * in front of the peg, then turns toward and drives onto the peg.
 * Note that this only gets the path; it does not execute it. That is covered in the
 * cPlaceGear command group.
 *
 * TL;DR: finds the path the robot has to drive to place the gear. Doesn't actually carry it out.
 */
class cGearPath : public frc::Command
{
private:

public:
	cGearPath();
	~cGearPath();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};


#endif /* SRC_COMMANDS_AUTONOMOUS_CGEARPATH_H_ */
/*
 * when angle variables are named, the naming structure is like this:
 *
 * angleAlphaBetaGamma
 *  	          Alpha
 *      	     /
 *          	/
 *       	   /
 *       	  /
 *       	 /
 *      Beta/____________Gamma
 *
 */
