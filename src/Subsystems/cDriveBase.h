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
#include "Subsystems/cMotorGroup.h"

class cDriveBase: public Subsystem
{
private:
    cMotorGroup* m_motorGroupLeft;
    cMotorGroup* m_motorGroupRight;
    cMotorGroup* m_motorGroupAll;
    cMotor* m_leftMotor1;
    cMotor* m_leftMotor2;
    cMotor* m_leftMotor3;
    cMotor* m_rightMotor1;
    cMotor* m_rightMotor2;
    cMotor* m_rightMotor3;
	I2C* colorSensor;
    int BitShift(uint8_t *colorReadout);

public:
    cDriveBase();
    ~cDriveBase();
    void InitDefaultCommand();
    void resetEncoder();
    void setLeftSpeed(double speed);
    void setRightSpeed(double speed);
    void setBrakeMode(bool brake); //stop dat boi
    void setEnabled(bool enabled);
    cMotorGroup* getMotorGroupLeft();
    cMotorGroup* getMotorGroupRight();
    cMotorGroup* getMotorGroupAll();
    bool CanSeeTape();

};

#endif /* SRC_SUBSYSTEMS_CDRIVEBASE_H_ */
