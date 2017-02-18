#include "cDriveStraight.h"

cDriveStraight::cDriveStraight(float distance, float speed) {
	Requires(s_drivebase);
	std::cout << "Begin cDriveStraight construct" << std::endl;
	m_endTicks = (distance/WHEEL_CIRCUMFERENCE) * TICKS_PER_REVOLUTION;
	m_beginningYaw = 0;
	m_curTicks = 0;
	m_p = 0.05;
	m_i = 0;
	m_d = 0;

	m_controller = new PIDController(m_p, m_i, m_d, CommandBase::s_drivebase->getGyro(), this);
	m_speed = speed;

	m_isDisabled = true;
}

void cDriveStraight::Initialize() {
	m_isDisabled = false;
	m_beginningYaw = CommandBase::s_drivebase->getGyro()->getAngle();
	m_controller->SetSetpoint(m_beginningYaw);
	m_curTicks = CommandBase::s_drivebase->getMotorGroupLeft()->getPosition();
	m_controller->Enable();
}

void cDriveStraight::Execute() {
    //See PIDWrite
}

bool cDriveStraight::IsFinished() {
	return CommandBase::s_drivebase->getMotorGroupLeft()->getPosition() > (m_curTicks + m_endTicks);
}

void cDriveStraight::End() {
	m_isDisabled = true;
	m_controller->Disable();
	CommandBase::s_drivebase->setLeftSpeed(0);
	CommandBase::s_drivebase->setRightSpeed(0);
}

void cDriveStraight::Interrupted() {
	m_isDisabled = true;
	m_controller->Disable();
	CommandBase::s_drivebase->setLeftSpeed(0);
	CommandBase::s_drivebase->setRightSpeed(0);
}

void cDriveStraight::PIDWrite(double output) {
	if(!m_isDisabled) {
		float leftSpeed = m_speed - output;
		float rightSpeed = m_speed + output;

		CommandBase::s_drivebase->setLeftSpeed(leftSpeed);
		CommandBase::s_drivebase->setRightSpeed(rightSpeed);
	}
}
