#include "cShooter.h"
#include <RobotMap.h>
#include "Utilities/cMotor.h"


cShooter::cShooter()
{
    m_motor1 = new cMotor(SHOOTER_MOTOR1_PORT, BaneBots775, true); //one of these needs an encoder. Which? god only knows
    m_motor2 = new cMotor(SHOOTER_MOTOR2_PORT, BaneBots775);

	//m_motor1->reverseSensorDirection();
	m_motor2->setControlMode(CANSpeedController::kFollower);
	m_motor2->Set(SHOOTER_MOTOR1_PORT);
	m_motor1->setControlMode(CANSpeedController::kSpeed);
	m_motor1->setBrakeMode(false);
	m_motor2->setBrakeMode(false);
	m_motor1->setFeedbackDevice();

}

cShooter::~cShooter()
{
    delete m_motor1;
    delete m_motor2;
}

void cShooter::InitDefaultCommand()
{

}

void cShooter::setSpeed(float speed)
{
    m_motor1->setOutput(speed);
    m_motor2->setOutput(-1*speed);
}

double cShooter::getSpeed()
{
    return m_motor1->GetSpeed();
}

double cShooter::PIDGet()
{
	return m_motor1->GetSpeed();
}

bool cShooter::isPIDEnabled()
{
	return m_motor1->isEnabled();
}

double cShooter::getError()
{
	return m_motor1->getClosedLoopError();
}

void cShooter::EnablePID()
{
	if(m_motor1->getControlMode() != CANTalon::ControlMode::kSpeed) {
		m_motor1->setControlMode(CANSpeedController::kSpeed);
	}

	m_motor2->setControlMode(CANSpeedController::kFollower);
	m_motor1->Enable();

	std::cout << "Shooter PID enabled" << std::endl;
}

void cShooter::DisablePID()
{
	m_motor1->Disable();
}

void cShooter::ResetPID()
{
	m_motor1->Reset();
}

void cShooter::setSetpoint(float setpoint)
{
	m_motor1->Set(setpoint);
	m_motor1->SetSetpoint(setpoint);
}

double cShooter::getSetpoint()
{
	return m_motor1->GetSetpoint();
}

void cShooter::setPID(double p, double i, double d, double f)
{
	m_motor1->SetPID(p, i, d, f);
}

void cShooter::setManualEnabled(bool state)
{
	if(state) {
		m_motor1->setControlMode(CANSpeedController::kPercentVbus);
		m_motor2->setControlMode(CANSpeedController::kPercentVbus);
	} else {
		m_motor1->setControlMode(CANSpeedController::kSpeed);
		m_motor2->setControlMode(CANSpeedController::kFollower);
	}
    m_manualEnabled = state;
}

bool cShooter::isManualEnabled()
{
    return m_manualEnabled;
}

cMotor* cShooter::getShooterMotor() {
	return m_motor1;
}
