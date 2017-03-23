#include <Commands/FloorCollector/cRunFloorCollector.h>

cRunFloorCollector::cRunFloorCollector(double speed) {
	m_speed = speed;
}

// Called just before this Command runs the first time
void cRunFloorCollector::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void cRunFloorCollector::Execute() {
	CommandBase::s_floorCollector->setCollectorSpeed(m_speed);
}

// Make this return true when this Command no longer needs to run execute()
bool cRunFloorCollector::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void cRunFloorCollector::End() {
	CommandBase::s_floorCollector->setCollectorSpeed(0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void cRunFloorCollector::Interrupted() {
	End();
}
