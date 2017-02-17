/*
 * cShootPID.h
 *
 *  Created on: Feb 11, 2017
 *      Author: s-2505674
 */

#ifndef SRC_COMMANDS_CSHOOTPID_H_
#define SRC_COMMANDS_CSHOOTPID_H_

#include <CommandBase.h>
#include <cstdbool>
#include "RobotMap.h"

class cShooter;

class cShootPID: public CommandBase {
private:
	double speed;
	float current_setpoint = 1.0;
	float timeout;
public:
	cShootPID(double speed, float timeout = 0.0);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};



#endif /* SRC_COMMANDS_CSHOOTPID_H_ */
