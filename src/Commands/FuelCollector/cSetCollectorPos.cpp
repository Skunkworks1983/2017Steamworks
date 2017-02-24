#include <Commands/FuelCollector/cSetCollectorPos.h>

cSetCollectorPos::cSetCollectorPos() {

}

// Called just before this Command runs the first time
void cSetCollectorPos::Initialize() {
	std::cout << "INITIALIZED" << std::endl;
	CommandBase::s_fuelCollector->setEnabled(true);
	CommandBase::s_fuelCollector->setFlapSetpoint(FUELCOLLECTOR_MAX_ENC_ANGLE);
}

// Called repeatedly when this Command is scheduled to run
void cSetCollectorPos::Execute() {

}

// Make this return true when this Command no longer needs to run execute()
bool cSetCollectorPos::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void cSetCollectorPos::End() {
	CommandBase::s_fuelCollector->setFlapSetpoint(FUELCOLLECTOR_MIN_ENC_ANGLE);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void cSetCollectorPos::Interrupted() {
	End();
}
