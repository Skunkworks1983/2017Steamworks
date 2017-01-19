/*
 * runTankDrive.cpp
 *
 *  Created on: Jan 16, 2017
 *      Author: s-4036956
 */
//^^^ fix auto generated comments
#include <Commands/cRunTankDrive.h>
#include <Subsystems/cDriveBase.h>

cRunTankDrive::cRunTankDrive() { //don't ignore your warnings

	Requires(drivebase);
}

void cRunTankDrive::Initialize(){
	CommandBase::drivebase->setLeftSpeed(speed); //variable speed is never given a value
	CommandBase::drivebase->setRightSpeed(speed);
}

void cRunTankDrive::Execute(){

}

bool cRunTankDrive::IsFinished(){
	return false;
}

void cRunTankDrive::End(){

}

void cRunTankDrive::Interrupted(){
	End();
}

