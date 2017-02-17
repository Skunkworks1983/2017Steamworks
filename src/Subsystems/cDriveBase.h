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
<<<<<<< HEAD
#include <RobotMap.h>
=======
#include "Subsystems/iDriveBase.h"
>>>>>>> refs/remotes/origin/master

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

<<<<<<< HEAD
	I2C* m_colorSensor;
	AnalogInput* m_rSonar;
	AnalogInput* m_lSonar;
    int BitShift(uint8_t *colorReadout);

    cGyro* m_gyro;
=======
    iGyro* m_gyro;
>>>>>>> refs/remotes/origin/master


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
    cReversingMotorGroup* getMotorGroupGyro();
<<<<<<< HEAD
    cGyro* getGyro();

=======
    iGyro* getGyro();
    bool CanSeeTape();
>>>>>>> refs/remotes/origin/master


};

#endif /* SRC_SUBSYSTEMS_CDRIVEBASE_H_ */
