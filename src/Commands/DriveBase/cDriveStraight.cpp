#include "cDriveStraight.h"

cDriveStraight::cDriveStraight(float distance, float speed, float timeout, bool wiggly) {
	Requires(s_drivebase);
	std::cout << "Begin cDriveStraight construct" << std::endl;
	m_endTicks = distance;
	m_beginningYaw = 0;
	m_curTicks = 0;

    if(timeout != 0) {
        SetTimeout(timeout);
    }

	m_timeout = timeout;

	m_gyroMode = true; //default gyro mode

	m_speed = speed;

	double wiggleFactor = 1;
	if (wiggly) {
	wiggleFactor = 2;
	}
	m_p = 0.030 * wiggleFactor;
	m_i = 0;
	m_d = 0.0006;
	m_f = 0.05;

	m_isDisabled = true;

	m_controller = NULL;

	std::cout << "cDriveStraight constructed" << std::endl;
}

void cDriveStraight::Initialize() {
	if(CommandBase::s_drivebase->getGyro()->isDead() || !USE_GYRO) {
		m_gyroMode = false;
	} else {
		m_gyroMode = true;
	}

	m_controller = new PIDController(m_p, m_i, m_d, this, this);


	m_beginningYaw = PIDGet(); //Returns cur gyro angle or current encoder offset
	m_controller->SetSetpoint(m_beginningYaw);
	m_curTicks = CommandBase::s_drivebase->getMotorGroupLeft()->getPosition();
	CommandBase::s_drivebase->setBrakeMode(true);

	m_controller->Enable();
	m_isDisabled = false;

	std::cout << "cDriveStraight intialize" << std::endl;
}

void cDriveStraight::Execute() {
	//All logic in PIDWrite();
}

bool cDriveStraight::IsFinished() {
	if(m_endTicks < 0) {
		return CommandBase::s_drivebase->getMotorGroupLeft()->getPosition() < (m_curTicks + m_endTicks) || IsTimedOut(); //FLIPPED FOR COMP BOT TODO TODO TODO
	} else {
		return CommandBase::s_drivebase->getMotorGroupLeft()->getPosition() > (m_curTicks + m_endTicks) || IsTimedOut();
	}
}

void cDriveStraight::End() {
	m_isDisabled = true;
	m_controller->Disable();
	CommandBase::s_drivebase->setLeftSpeed(0);
	CommandBase::s_drivebase->setRightSpeed(0);
	std::cout << "cDriveStraight end" << std::endl;
}

void cDriveStraight::Interrupted() {
	m_isDisabled = true;
	m_controller->Disable();
	CommandBase::s_drivebase->setLeftSpeed(0);
	CommandBase::s_drivebase->setRightSpeed(0);
	std::cout << "cDriveStraight interrupt" << std::endl;
}

double cDriveStraight::PIDGet() {
	if(m_gyroMode) {
		return CommandBase::s_drivebase->getGyro()->getAngle();
	} else {
		return m_speed;
		//return (CommandBase::s_drivebase->getMotorGroupRight()->getPosition() - CommandBase::s_drivebase->getMotorGroupLeft()->getPosition())/51.433;
	}
}

void cDriveStraight::PIDWrite(double output) {
	if(!m_isDisabled) {

		if(output > 0.95) {
			output = 0.95;
		} else if(output < -0.95) {
			output = -0.95;
		}

		float leftSpeed = (m_speed - output);
		float rightSpeed = (m_speed + output);

		CommandBase::s_drivebase->setLeftSpeed(leftSpeed);
		CommandBase::s_drivebase->setRightSpeed(rightSpeed);
	}
}
