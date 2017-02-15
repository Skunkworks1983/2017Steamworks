#include "cDriveStraight.h"

cDriveStraight::cDriveStraight(float distance, float speed) {
	m_rotations = distance/WHEEL_CIRCUMFERENCE;
	m_beginningYaw = 0;
	m_curRevolutions = 0;
	m_p = 1;
	m_i = 0;
	m_d = 0;

	m_controller = new PIDController(m_p, m_i, m_d, CommandBase::s_drivebase->getGyro(), this);

	m_controller->SetOutputRange(-1, 1);

	m_speed = speed;
	m_revolutionOffset = distance/WHEEL_CIRCUMFERENCE;
}

void cDriveStraight::Initialize() {
	m_beginningYaw = CommandBase::s_drivebase->getGyro()->getAngle();
	m_curRevolutions = CommandBase::s_drivebase->getMotorGroupLeft()->getPosition();
}

void cDriveStraight::Execute() {
    //See PIDWrite
}

bool cDriveStraight::IsFinished() {
	return CommandBase::s_drivebase->getMotorGroupLeft()->getPosition() > (m_curRevolutions + m_revolutionOffset);
}

void cDriveStraight::End() {

}

void cDriveStraight::Interrupted() {

}

void cDriveStraight::PIDWrite(double output) {
    float leftSpeed = m_speed + output;
	float rightSpeed = m_speed - output;

	CommandBase::s_drivebase->setLeftSpeed(leftSpeed);
	CommandBase::s_drivebase->setRightSpeed(rightSpeed);
}
