/*
 * cDriveBase.cpp
 *
 *  Created on: Jan 16, 2017
 *      Author: paella
 */

#include <RobotMap.h>
#include "cMotor.h"
#include <Subsystems/cDriveBase.h>
#include "Commands/cRunTankDrive.h"
cDriveBase::cDriveBase():Subsystem("cDriveBase") {
	// TODO Auto-generated constructor stub
	 {

		leftMotor1 = new cMotor(DRIVEBASE_LEFTMOTOR_1_PORT);
		leftMotor2 = new cMotor(DRIVEBASE_LEFTMOTOR_2_PORT);
		leftMotor3 = new cMotor(DRIVEBASE_LEFTMOTOR_3_PORT);

		rightMotor1 = new cMotor(DRIVEBASE_RIGHTMOTOR_1_PORT);
		rightMotor2 = new cMotor(DRIVEBASE_RIGHTMOTOR_2_PORT);
		rightMotor3 = new cMotor(DRIVEBASE_RIGHTMOTOR_3_PORT);
	}
}

cDriveBase::~cDriveBase() {
	// TODO Auto-generated destructor stub
	delete leftMotor1;
	delete leftMotor2;
	delete leftMotor3;
	delete rightMotor1;
	delete rightMotor2;
	delete rightMotor3;
}
void cDriveBase::setBrakeMode(bool brake) {
	leftMotor1->setBrakeMode(brake);
	leftMotor2->setBrakeMode(brake);
	leftMotor3->setBrakeMode(brake);
	rightMotor1->setBrakeMode(brake);
	rightMotor2->setBrakeMode(brake);
	rightMotor3->setBrakeMode(brake);
}
void cDriveBase::InitDefaultCommand() {
	SetDefaultCommand(new cRunTankDrive());
}
void cDriveBase::resetEncoder() {
}
void cDriveBase::setLeftSpeed(double speed) {
}
void cDriveBase::setRightSpeed(double speed) {
}




