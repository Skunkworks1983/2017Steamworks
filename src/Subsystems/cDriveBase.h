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
#include "Utilities/cMotor.h"
#include <OI.h>
#include "Subsystems/Utilities/cMotorGroup.h"
#include "Subsystems/Utilities//cReversingMotorGroup.h"
#include "Subsystems/Sensors/cGyro.h"
#include <PIDController.h>
#include "Subsystems/Interfaces/iDriveBase.h"

class cDriveBase: public iDriveBase
{
private:
    cMotorGroup* m_motorGroupLeft;
    cMotorGroup* m_motorGroupRight;
    cMotorGroup* m_motorGroupAll;
    cReversingMotorGroup* m_motorGroupGyro;
    iMotor* m_leftMotor1;
    iMotor* m_leftMotor2;
    iMotor* m_leftMotor3;
    iMotor* m_rightMotor1;
    iMotor* m_rightMotor2;
    iMotor* m_rightMotor3;

    iGyro* m_gyro;

	I2C* colorSensor;
    int BitShift(uint8_t *colorReadout);

    bool m_IsReversed;

public:
	cDriveBase();
	~cDriveBase();

	void InitDefaultCommand();
	void resetEncoder();

	void setLeftSpeed(double speed);
	void setRightSpeed(double speed);

	void setBrakeMode(bool brake);
	void setEnabled(bool enabled);
    cMotorGroup* getMotorGroupLeft();
    cMotorGroup* getMotorGroupRight();
    cMotorGroup* getMotorGroupAll();

    cReversingMotorGroup* getMotorGroupGyro();
    iGyro* getGyro();
    bool CanSeeTape();
    bool getIsReversed();
    void setIsReversed(bool isreversed);

};

#endif /* SRC_SUBSYSTEMS_CDRIVEBASE_H_ */
