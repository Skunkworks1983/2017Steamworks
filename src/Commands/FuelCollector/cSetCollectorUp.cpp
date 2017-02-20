#include "cSetCollectorUp.h"

cSetCollectorUp::cSetCollectorUp(bool up) {
	m_up = up;
}

// Called just before this Command runs the first time
void cSetCollectorUp::Initialize() {
	if(m_up) {
		//CommandBase::s_fuelCollector->setFlapSetpoint();
	}
}

// Called repeatedly when this Command is scheduled to run
void cSetCollectorUp::Execute() {

}

// Make this return true when this Command no longer needs to run execute()
bool cSetCollectorUp::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void cSetCollectorUp::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void cSetCollectorUp::Interrupted() {

}
