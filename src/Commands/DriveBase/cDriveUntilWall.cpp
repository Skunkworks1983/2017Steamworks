#include "./cDriveUntilWall.h"
#include <Subsystems/Utilities/cPidSonars.h>

cDriveUntilWall::cDriveUntilWall(double speed) {
	m_p = 1/0.12;
	m_i = 0;
	m_d = 0;

	m_controller = new PIDController(m_p, m_i, m_d, new cPidSonars(), this);
	m_controller->SetSetpoint(0);
	m_speed = speed;
	m_isDisabled = true;

	m_controller->SetOutputRange(-1, 1);
}

void cDriveUntilWall::Initialize() {
	m_controller->SetPID(Preferences::GetInstance()->GetDouble("P", m_p), Preferences::GetInstance()->GetDouble("I", m_i), Preferences::GetInstance()->GetDouble("D", m_d));
	m_controller->Enable();
	m_isDisabled = false;

	m_leftStart = CommandBase::s_drivebase->getMotorGroupLeft()->getPosition();
	m_rightStart = CommandBase::s_drivebase->getMotorGroupRight()->getPosition();

	CommandBase::s_drivebase->setBrakeMode(true);
}

void cDriveUntilWall::Execute() {

}

bool cDriveUntilWall::IsFinished() {
	return fabs(CommandBase::s_drivebase->getMotorGroupLeft()->getPosition() - m_leftStart) > 7000 && fabs(CommandBase::s_drivebase->getMotorGroupRight()->getPosition() - m_rightStart) > 7000;
}

void cDriveUntilWall::End() {
	m_isDisabled = true;
	m_controller->Disable();
	CommandBase::s_drivebase->setLeftSpeed(0);
	CommandBase::s_drivebase->setRightSpeed(0);
}

void cDriveUntilWall::Interrupted() {
	End();
}

double cDriveUntilWall::PIDGet() { //unused
	return CommandBase::s_drivebase->GetLeftDistance() - CommandBase::s_drivebase->GetRightDistance();
}

void cDriveUntilWall::PIDWrite(double output) {
	if(!m_isDisabled) {
		/*float percentDone = (CommandBase::s_drivebase->GetLeftDistance() + CommandBase::s_drivebase->GetRightDistance())/2;
		float slowDown = 1;
		if(percentDone < 0.52) {
			slowDown = (percentDone-0.6)*2.5;
		}
		float leftSpeed = slowDown*(m_speed - 0.1*output);
		float rightSpeed = slowDown*(m_speed + 0.1*output);

		std::cout << "Left: " << leftSpeed << "\t\tRight: " << rightSpeed << std::endl;*/

		//std::cout << "Output: " << output << std::endl;

		//CommandBase::s_drivebase->setLeftSpeed(std::max(std::min(m_speed + output, 2*m_speed), -2*m_speed));
		//CommandBase::s_drivebase->setRightSpeed(std::min(std::max(m_speed - output, -2*m_speed), 2*m_speed));
	}
}
