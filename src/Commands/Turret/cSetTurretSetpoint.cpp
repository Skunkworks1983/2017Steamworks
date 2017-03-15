#include "cSetTurretSetpoint.h"

cSetTurretSetpoint::cSetTurretSetpoint(double setpoint) {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	m_setpoint = setpoint;
}

// Called just before this Command runs the first time
void cSetTurretSetpoint::Initialize() {
	std::cout << "Init cSetTurret" << std::endl;
}

// Called repeatedly when this Command is scheduled to run
void cSetTurretSetpoint::Execute() {
	CommandBase::s_turret->setSetpoint(m_setpoint);
}

// Make this return true when this Command no longer needs to run execute()
bool cSetTurretSetpoint::IsFinished() {
	return true;
}

// Called once after isFinished returns true
void cSetTurretSetpoint::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void cSetTurretSetpoint::Interrupted() {

}
