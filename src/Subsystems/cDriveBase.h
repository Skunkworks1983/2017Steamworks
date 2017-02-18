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
#include <AnalogInput.h>
#include "Subsystems/cReversingMotorGroup.h"
#include "Subsystems/cGyro.h"
#include <PIDController.h>
#include <RobotMap.h>
#include "Subsystems/iDriveBase.h"

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


	I2C* m_colorSensor;
	AnalogInput* m_rSonar;
	AnalogInput* m_lSonar;
    int BitShift(uint8_t *colorReadout);
    iGyro* m_gyro;

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
    double GetLeftDistance();
    double GetRightDistance();
    double GetSonarDistance(bool left);
    cReversingMotorGroup* getMotorGroupGyro();
    iGyro* getGyro();



};

#endif /* SRC_SUBSYSTEMS_CDRIVEBASE_H_ */
