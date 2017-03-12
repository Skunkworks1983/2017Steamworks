#include "cTurnAngle.h"
#include <RobotMap.h>

cTurnAngle::cTurnAngle(float angle) {
	Requires(CommandBase::s_drivebase);

	m_startingAngle = 0;
	m_leftStart = 0;
	m_rightStart = 0;

	if(!CommandBase::s_drivebase->getGyro()->isDead() && USE_GYRO) {
		m_finalAngle = angle; //Angle to get to

		m_p = 0.01;
		m_i = 0;
		m_d = 0;

		m_gyroController = new PIDController(m_p, m_i, m_d, CommandBase::s_drivebase->getGyro(), this);
		m_gyroController->SetOutputRange(-1, 1);
	} else {
		m_finalAngle = angle*18.33;

		m_p = 1./250;
		m_i = 0;
		m_d = 0;

		m_leftController = new PIDController(m_p, m_i, m_d, CommandBase::s_drivebase->getMotorGroupLeft(), CommandBase::s_drivebase->getMotorGroupLeft());
		m_rightController = new PIDController(m_p, m_i, m_d, CommandBase::s_drivebase->getMotorGroupRight(), CommandBase::s_drivebase->getMotorGroupRight());
		m_leftController->SetOutputRange(-1, 1);
		m_rightController->SetOutputRange(-1, 1);
	}

	m_isDisabled = true;
}

void cTurnAngle::Initialize() {
	m_leftStart = CommandBase::s_drivebase->getMotorGroupLeft()->getPosition();
	m_rightStart = CommandBase::s_drivebase->getMotorGroupRight()->getPosition();

	m_startingAngle = CommandBase::s_drivebase->getGyro()->getAngle(); //Angle we start at

	if(!CommandBase::s_drivebase->getGyro()->isDead() && USE_GYRO) {
		m_gyroController->SetSetpoint(m_finalAngle + m_startingAngle);
		m_gyroController->SetAbsoluteTolerance(ANGLE_OK_ERROR);
		m_gyroController->Enable();
	} else {
		m_leftController->SetSetpoint(m_finalAngle + m_leftStart);
		m_leftController->SetAbsoluteTolerance(ENCODER_OK_ERROR);

		m_rightController->SetSetpoint(m_rightStart - m_finalAngle);
		m_rightController->SetAbsoluteTolerance(ENCODER_OK_ERROR);

		//m_leftController->Enable();
		m_rightController->Enable();
	}
	m_isDisabled = false;
}

void cTurnAngle::Execute() {
	//See PIDWrite
	std::cout << "RE: " << m_rightController->GetError() << std::endl;
}

bool cTurnAngle::IsFinished() {
	if(!CommandBase::s_drivebase->getGyro()->isDead() && USE_GYRO) {
		return m_gyroController->OnTarget();
	} else {
		return m_leftController->OnTarget() && m_rightController->OnTarget();
	}
}

void cTurnAngle::End() {
	m_isDisabled = true;
	CommandBase::s_drivebase->setLeftSpeed(0);
	CommandBase::s_drivebase->setRightSpeed(0);

	if(!CommandBase::s_drivebase->getGyro()->isDead() && USE_GYRO) {
		m_gyroController->Disable();
	} else {
		m_leftController->Disable();
		m_rightController->Disable();
	}
}

void cTurnAngle::Interrupted() {
	End();
}

void cTurnAngle::PIDWrite(double output) {
	if(!m_isDisabled) {
		std::cout << "Error: " << m_gyroController->GetError() << "\tOutput: " << output << std::endl;

		if(output > 0.5) {
			output = 0.5;
		} else if(output < -0.5) {
			output = -0.5;
		}

		CommandBase::s_drivebase->setLeftSpeed(output);
		CommandBase::s_drivebase->setRightSpeed(-1*output);
	}
}
