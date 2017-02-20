#include "./cRunOneMotor.h"

cRunOneMotor::cRunOneMotor() {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	//m_motor2 = new cMotor(10, BaneBots775);

	for(int i=0; i<16; i++) {
		cMotor* motor = new cMotor(i, BaneBots775, true);
		motor->setFeedbackDevice();
		m_motors.push_back(motor);
	}

	m_index = 0;
	m_pressedLastLoop = false;
}

// Called just before this Command runs the first time
void cRunOneMotor::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void cRunOneMotor::Execute() {
	if(!m_pressedLastLoop) {
		if(CommandBase::s_oi->getLeftTriggerPressed()) {
			//m_motors[m_index]->
			if(m_index == 0) {
				m_index = 15;
			} else {
				m_index -= 1;
			}
			std::cout << "m_index: " << m_index << std::endl;
			m_pressedLastLoop = true;
		} else if(CommandBase::s_oi->getRightTriggerPressed()) {
			if(m_index == 15) {
				m_index = 0;
			} else {
				m_index += 1;
			}
			std::cout << "m_index: " << m_index << std::endl;
			m_pressedLastLoop = true;
		}
	} else {
		m_pressedLastLoop = false;
	}
	if(CommandBase::s_oi->getLeft2Pressed()) {
		std::cout << "Pos: \t\t" << m_motors[m_index]->getPosition() << std::endl;
	}
	m_motors[m_index]->setOutput(CommandBase::s_oi->getLeftStickY());
}

// Make this return true when this Command no longer needs to run execute()
bool cRunOneMotor::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void cRunOneMotor::End() {
	//m_motor2->setOutput(0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void cRunOneMotor::Interrupted() {

}
