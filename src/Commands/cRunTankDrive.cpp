/*
 * runTankDrive.cpp
 *
 *  Created on: Jan 16, 2017
 *      Author: s-4036956
 */
//^^^ fix auto generated comments
#include <Commands/cRunTankDrive.h>
#include <Subsystems/cDriveBase.h>
#include <OI.h>
#include <CommandBase.h>
cRunTankDrive::cRunTankDrive() { //don't ignore your warnings

	Requires(s_drivebase);
}

void cRunTankDrive::Initialize(){
	CommandBase::s_drivebase->setLeftSpeed(CommandBase::s_oi->getLeftStickY());
	CommandBase::s_drivebase->setRightSpeed(CommandBase::s_oi->getRightStickY());
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

