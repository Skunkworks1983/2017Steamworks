/*
 * cCenterTape.cpp
 *
 *  Created on: Feb 14, 2017
 *      Author: Mike
 */

#include <Commands/Autonomous/cCenterTape.h>

cCenterTape::cCenterTape() {
	m_motorGroupGyro = CommandBase::s_drivebase->getMotorGroupGyro();
	this->m_pidController = new PIDController(TURNDEGREE_PID_P, TURNDEGREE_PID_I, TURNDEGREE_PID_D , this, m_motorGroupGyro);
    m_pidController->SetSetpoint(0);

}

cCenterTape::~cCenterTape() {
	// TODO Auto-generated destructor stub
}

	void cCenterTape::Initialize() {
    m_pidController->Enable();
    m_pidController->SetAbsoluteTolerance(TURNANGLE_ABSTOLERANCE_ANGLE);

	}
	void cCenterTape::Execute() {

	}
	bool cCenterTape::IsFinished() {

	}
	void cCenterTape::End() {

	}
	void cCenterTape::Interrupted() {

	}
	double cCenterTape::PIDGet() {
		cLiftData* data = CommandBase::s_liftMessenger->receiveLiftData();
		return data->getX();
	}
