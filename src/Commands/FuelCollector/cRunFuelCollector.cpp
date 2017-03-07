#include "cRunFuelCollector.h"

cRunFuelCollector::cRunFuelCollector(double speed) {
	m_speed = speed;
}

// Called just before this Command runs the first time
void cRunFuelCollector::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void cRunFuelCollector::Execute() {
	CommandBase::s_fuelCollector->setCollectorSpeed(m_speed);
}

// Make this return true when this Command no longer needs to run execute()
bool cRunFuelCollector::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void cRunFuelCollector::End() {
	CommandBase::s_fuelCollector->setCollectorSpeed(0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void cRunFuelCollector::Interrupted() {
	End();
}
