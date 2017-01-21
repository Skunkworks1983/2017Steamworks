/*
 * cMotor.cpp
 *
 *  Created on: Jan 17, 2017
 *      Author: s-4036956
 */

#include <Subsystems/cMotor.h>
#include <CANTalon.h>
#include <RobotMap.h>

cMotor::cMotor(int port):m_motor(port) {
	// TODO Auto-generated constructor stub
}

cMotor::~cMotor() {
	// TODO Auto-generated destructor stub
}
 bool cMotor::setBrakeMode(bool brake) { //don't ignore warnings

	if(brake == true){
		 m_motor.ConfigNeutralMode(CANSpeedController::kNeutralMode_Brake);
		 return true;
	}
	else{
		m_motor.ConfigNeutralMode(CANSpeedController::kNeutralMode_Coast);
		return false;
	}

}
void cMotor::setOutput(float output) {
	m_motor.Set(output);
}
void cMotor::PIDWrite(float output){
	m_motor.Set(output);
}
double cMotor::PIDGet(){ //don't ignore warnings
	return m_motor.GetEncPosition();
	//we need to change this, not right
	//return sensor output for pid
};
