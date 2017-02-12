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
	double p = SHOOTER_P;
	double i = SHOOTER_I;
	double d = SHOOTER_D;
	double leftSpeed;
	double rightSpeed;
	float left_setpoint = 5;
	float right_setpoint = 5;
	float timeout;
	bool leftRamped;
	bool rightRamped;
public:
	cShootPID(double leftSpeed, double rightSpeed, float timeout = 0.0);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};



#endif /* SRC_COMMANDS_CSHOOTPID_H_ */
