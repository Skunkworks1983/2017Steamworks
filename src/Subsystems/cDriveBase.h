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
	cMotor* m_leftMotor1;
	cMotor* m_leftMotor2;
	cMotor* m_leftMotor3;
	cMotor* m_rightMotor1;
	cMotor* m_rightMotor2;
	cMotor* m_rightMotor3;

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
