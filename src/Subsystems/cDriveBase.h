/*
 * cDriveBase.h
 *
 *  Created on: Jan 16, 2017
 *      Author: paella
 */

#ifndef SRC_SUBSYSTEMS_CDRIVEBASE_H_
#define SRC_SUBSYSTEMS_CDRIVEBASE_H_
#include "WPILib.h"
#include <Commands/Subsystem.h>
#include "cMotor.h"
#include <OI.h>

class cDriveBase: public Subsystem {
private:
	cMotor* leftMotor1;
	cMotor* leftMotor2;
	cMotor* leftMotor3;

	cMotor* rightMotor1;
	cMotor* rightMotor2;
	cMotor* rightMotor3;

public:
	cDriveBase();
	~cDriveBase();

	void InitDefaultCommand();
	void resetEncoder();

	void setLeftSpeed(double speed);
	void setRightSpeed(double speed);

	void setBrakeMode(bool brake);
	void setEnabled(bool enabled);
};

#endif /* SRC_SUBSYSTEMS_CDRIVEBASE_H_ */
