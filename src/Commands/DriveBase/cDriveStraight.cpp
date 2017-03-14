#include "cDriveStraight.h"

cDriveStraight::cDriveStraight(float distance, float speed) {
	Requires(s_drivebase);
	SetTimeout(5);
	std::cout << "Begin cDriveStraight construct" << std::endl;
	m_endTicks = distance;
	m_beginningYaw = 0;
	m_curTicks = 0;
	if(CommandBase::s_drivebase->getGyro()->isDead()) {
		m_controller = new PIDController(m_p, m_i, m_d, this, this);
	} else {
		m_p = 0.030;
		m_i = 0;
		m_d = 0.0006;
		m_f = 0.05;
		m_controller = new PIDController(m_p, m_i, m_d, CommandBase::s_drivebase->getGyro(), this);
	}

	if(CommandBase::s_drivebase->getGyro()->isDead()) {

	} else {

	}
	m_speed = speed;

	m_isDisabled = true;

	std::cout << "cDriveStraight constructed" << std::endl;
}

void cDriveStraight::Initialize() {
	m_isDisabled = false;
	m_beginningYaw = CommandBase::s_drivebase->getGyro()->getAngle();
	m_controller->SetSetpoint(m_beginningYaw);
	m_curTicks = CommandBase::s_drivebase->getMotorGroupLeft()->getPosition();
	CommandBase::s_drivebase->setBrakeMode(true);

	//m_controller->SetPID(Preferences::GetInstance()->GetDouble("P", 0), Preferences::GetInstance()->GetDouble("I", 0), Preferences::GetInstance()->GetDouble("D", 0));
	std::cout << Preferences::GetInstance()->GetDouble("P", 0) << std::endl;
	m_controller->SetPID(m_p, m_i, m_d);
	m_controller->Enable();


	std::cout << "cDriveStraight intialize" << std::endl;

}

void cDriveStraight::Execute() {
    //See PIDWrite
	//m_controller->SetPID(Preferences::GetInstance()->GetDouble("P", 0), Preferences::GetInstance()->GetDouble("I", 0), Preferences::GetInstance()->GetDouble("D", 0));
	m_controller->SetPID(m_p, m_i, m_d);
}

bool cDriveStraight::IsFinished() {
	return CommandBase::s_drivebase->getMotorGroupLeft()->getPosition() > (m_curTicks + m_endTicks) || IsTimedOut();
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

double cDriveStraight::PIDGet() {
	return CommandBase::s_drivebase->getMotorGroupLeft()->getPosition() - CommandBase::s_drivebase->getMotorGroupRight()->getPosition();
}

void cDriveStraight::PIDWrite(double output) {
	if(!m_isDisabled) {
		//float percentDone = (CommandBase::s_drivebase->getMotorGroupLeft()->getPosition() - m_curTicks)/((float)m_endTicks);
		float slowDown = 1;
		//std::cout << "Percent done: " << percentDone << std::endl;
		/*if(percentDone > 0.5) {
			slowDown = -2*percentDone + 2;
		}*/
		//std::cout << CommandBase::s_drivebase->getMotorGroupLeft()->getPosition() << std::endl;
		//std::cout << "P: " << m_controller->GetP();

		if(output > 0.95) {
			output = 0.95;
		} else if(output < -0.95) {
			output = -0.95;
		}

		std::cout << "Output: " << output << std::endl;

		float leftSpeed = slowDown*(m_speed - output);
		float rightSpeed = slowDown*(m_speed + output);

		CommandBase::s_drivebase->setLeftSpeed(leftSpeed);
		CommandBase::s_drivebase->setRightSpeed(rightSpeed);
	}
}
