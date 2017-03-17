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

class cShootPID: public frc::Command {
private:
	double m_speed;
	double m_currentSetpoint;
	float m_timeout;

	/*double p = SHOOTER_P;
	double i = SHOOTER_I;
	double d = SHOOTER_D;
	double f = SHOOTER_F;*/

public:
	cShootPID(double setpoint, float timeout = 0);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};



#endif /* SRC_COMMANDS_CSHOOTPID_H_ */
