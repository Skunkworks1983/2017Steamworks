#include "cSetCollectorSpeed.h"

cSetCollectorSpeed::cSetCollectorSpeed(double speed) {
	m_speed = speed;
}

// Called just before this Command runs the first time
void cSetCollectorSpeed::Initialize() {
	CommandBase::s_floorCollector->setEnabled(false);
}

// Called repeatedly when this Command is scheduled to run
void cSetCollectorSpeed::Execute() {
	CommandBase::s_floorCollector->setFlapSpeed(m_speed);
}

// Make this return true when this Command no longer needs to run execute()
bool cSetCollectorSpeed::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void cSetCollectorSpeed::End() {
	CommandBase::s_floorCollector->setFlapSpeed(0);
	CommandBase::s_floorCollector->setEnabled(true);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void cSetCollectorSpeed::Interrupted() {
	End();
}
