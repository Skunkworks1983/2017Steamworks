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

class cShooter;

class cShootPID: public CommandBase {
private:
	double leftSpeed;
	double rightSpeed;
	float left_setpoint = 5;
	float right_setpoint = 5;
	float timeout;
public:
	cShootPID(double leftSpeed, double rightSpeed, float timeout = 0.0);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};



#endif /* SRC_COMMANDS_CSHOOTPID_H_ */
