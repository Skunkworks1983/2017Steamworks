/*
 * cSetSetpointManually.h
 *
 *  Created on: Feb 22, 2017
 *      Author: S-2505674
 */

#ifndef SRC_SUBSYSTEMS_CSETSETPOINTMANUALLY_H_
#define SRC_SUBSYSTEMS_CSETSETPOINTMANUALLY_H_

#include <Commands/Command.h>
#include "RobotMap.h"

//Allows driver to manually set shooter setpoints using the slider on the OI

class cSetSetpointManually : public frc::Command
{
public:
	cSetSetpointManually(float timeout = 0);

	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();

private:
	double p = SHOOTER_P;
	double i = SHOOTER_I;
	double d = SHOOTER_D;
	double f = SHOOTER_F;

	float timeout;
};



#endif /* SRC_SUBSYSTEMS_CSETSETPOINTMANUALLY_H_ */
