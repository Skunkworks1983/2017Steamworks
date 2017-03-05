#include "cTurnAngle.h"
#include <RobotMap.h>

cTurnAngle::cTurnAngle(float angle) {
	Requires(CommandBase::s_drivebase);
	m_finalAngle = angle; //Angle to get to
	m_startingAngle = 0; //Set in Initialize

	m_p = 0.3;
	m_i = 0;
	m_d = 0;

	m_controller = new PIDController(m_p, m_i, m_d, CommandBase::s_drivebase->getGyro(), this);

	m_controller->SetOutputRange(-0.5, 0.5);

	m_isDisabled = true;
}

void cTurnAngle::Initialize() {
	m_startingAngle = CommandBase::s_drivebase->getGyro()->getAngle(); //Angle we start at
	m_controller->SetSetpoint(m_finalAngle - m_startingAngle);

	m_controller->Enable();

	m_isDisabled = false;
}

void cTurnAngle::Execute() {
	//See PIDWrite
}

bool cTurnAngle::IsFinished() {
	return abs(CommandBase::s_drivebase->getGyro()->getAngle() - (m_finalAngle - m_startingAngle)) < ANGLE_OK_ERROR;
}

void cTurnAngle::End() {
	m_isDisabled = true;
	CommandBase::s_drivebase->setLeftSpeed(0);
	CommandBase::s_drivebase->setRightSpeed(0);

	m_controller->Disable();
}

void cTurnAngle::Interrupted() {
	End();
}

void cTurnAngle::PIDWrite(double output) {
	if(!m_isDisabled) {
		//Called as quick as the PID can run
		CommandBase::s_drivebase->setLeftSpeed(output);    //May need to switch the positive and negative
		CommandBase::s_drivebase->setRightSpeed(output);
	}
}
