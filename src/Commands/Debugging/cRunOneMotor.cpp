#include "./cRunOneMotor.h"

cRunOneMotor::cRunOneMotor() {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	m_motor1 = new cMotor(11, BaneBots775);
	m_motor2 = new cMotor(10, BaneBots775);
}

// Called just before this Command runs the first time
void cRunOneMotor::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void cRunOneMotor::Execute() {
	m_motor1->setOutput(CommandBase::s_oi->getLeftStickY());
	m_motor2->setOutput(CommandBase::s_oi->getLeftStickY());
}

// Make this return true when this Command no longer needs to run execute()
bool cRunOneMotor::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void cRunOneMotor::End() {
	m_motor2->setOutput(0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void cRunOneMotor::Interrupted() {

}
