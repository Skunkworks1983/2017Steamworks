#include "cShooter.h"
#include <RobotMap.h>
#include "cMotor.h"

cShooter::cShooter(bool speed, bool brake) :
        Subsystem("cShooter")
{
    m_motor1 = new cMotor(SHOOTER_MOTOR1_PORT);
    m_motor2 = new cMotor(SHOOTER_MOTOR2_PORT);

	m_motor1->reverseSensorDirection();
	m_motor2->setControlMode(!speed);
	m_motor2->Set(SHOOTER_MOTOR1_PORT);
	m_motor1->setControlMode(speed);
	m_motor1->setBrakeMode(!brake);
	m_motor2->setBrakeMode(!brake);
	m_motor1->setFeedbackDevice();
	m_motor1->reverseOutput();
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
    m_motor2->setOutput(speed);
}

double cShooter::getSpeed()
{
	return 0;
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

void cShooter::EnablePID(bool speed)
{
	if(m_motor1->getControlMode() != CANTalon::ControlMode::kSpeed) {
		m_motor1->setControlMode(speed);
	}
	m_motor1->Enable();
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
