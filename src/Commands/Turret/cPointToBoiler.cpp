#include "cPointToBoiler.h"
#include <CommandBase.h>

cPointToBoiler::cPointToBoiler() {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	std::cout << "cptb const start" << std::endl;
	m_p = 1;
	m_i = 0;
	m_d = 0;
	m_udpInput = new cPidUDP();
	std::cout << "cptb const after new pidudp" << std::endl;
	m_pidCont = new cPIDOutputContainer();
	std::cout << "cptb const after pidoc" << std::endl;
	m_controller = new PIDController(m_p, m_i, m_d, m_udpInput, m_pidCont);

	m_controller->SetInputRange(-1, 1);
	m_controller->SetOutputRange(-0.25, 0.25);
	m_controller->SetSetpoint(0);

	CommandBase::s_drivebase->setEnabled(true);
}

cPointToBoiler::~cPointToBoiler()
{
	m_controller->Enable();
}

// Called just before this Command runs the first time
void cPointToBoiler::Initialize() {
	m_controller->Enable();
}

// Called repeatedly when this Command is scheduled to run
void cPointToBoiler::Execute() {
	double speed = m_pidCont->getVal();

	CommandBase::s_drivebase->setLeftSpeed(speed);
	CommandBase::s_drivebase->setRightSpeed(-1*speed);
}

// Make this return true when this Command no longer needs to run execute()
bool cPointToBoiler::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void cPointToBoiler::End() {
	m_controller->Disable();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void cPointToBoiler::Interrupted() {

}
