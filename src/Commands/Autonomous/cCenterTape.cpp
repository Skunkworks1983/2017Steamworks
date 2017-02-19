/*
 * cCenterTape.cpp
 *
 *  Created on: Feb 14, 2017
 *      Author: Mike
 */

#include <Commands/Autonomous/cCenterTape.h>
#include <math.h>

cCenterTape::cCenterTape() {
	m_motorGroupGyro = CommandBase::s_drivebase->getMotorGroupGyro();
	this->m_pidController = new PIDController(TURNDEGREE_PID_P, TURNDEGREE_PID_I, TURNDEGREE_PID_D , this, this);
    m_pidController->SetSetpoint(0);
    m_data = CommandBase::s_liftMessenger->receiveLiftData();
}

cCenterTape::~cCenterTape() {
	delete m_pidController;
}

void cCenterTape::Initialize() {
    m_pidController->Enable();
}
void cCenterTape::Execute() {

}
bool cCenterTape::IsFinished() {

	return abs(m_data->getX() < .05);
}
void cCenterTape::End() {
	m_pidController->Disable();
}
void cCenterTape::Interrupted() {
	m_pidController->Disable();
}
double cCenterTape::PIDGet() {
	return m_data->getX();
}
void cCenterTape::PIDWrite(double output) {
	if (m_data->getX() < 1) {
		CommandBase::s_drivebase->setLeftSpeed(-1*output);    //May need to switch the positive and negative
		CommandBase::s_drivebase->setRightSpeed(output);//Totally not copied and pasted from Eli's code
	} else {
		CommandBase::s_drivebase->setLeftSpeed(output);    //May need to switch the positive and negative
		CommandBase::s_drivebase->setRightSpeed(-1*output);//Totally not copied and pasted from Eli's code
	}
}
