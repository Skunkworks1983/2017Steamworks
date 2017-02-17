#include "cShooter.h"
#include <RobotMap.h>

cShooter::cShooter() :
        Subsystem("cShooter")
{
    m_motor1 = new cMotor(SHOOTER_MOTOR1_PORT);
    m_motor2 = new cMotor(SHOOTER_MOTOR2_PORT);


	talon = new CANTalon(SHOOTER_MOTOR1_PORT);
	talon->SetSensorDirection(true);
	talonSlave = new CANTalon(SHOOTER_MOTOR2_PORT);
	talonSlave->SetControlMode(CANTalon::ControlMode::kFollower);
	talonSlave->Set(SHOOTER_MOTOR1_PORT);
	talon->SetControlMode(CANTalon::ControlMode::kSpeed);
	talon->ConfigNeutralMode(CANTalon::NeutralMode::kNeutralMode_Coast);
	talon->SetFeedbackDevice(CANTalon::FeedbackDevice::CtreMagEncoder_Absolute); //i don't actually know this yet
	talon->SetClosedLoopOutputDirection(true);
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
	return talon->GetSpeed();
}

bool cShooter::isPIDEnabled()
{
	return talon->IsEnabled();
}

double cShooter::getError()
{
	return talon->GetClosedLoopError();
}

void cShooter::EnablePID()
{
	if (talon->GetControlMode() != CANTalon::ControlMode::kSpeed) {
		talon->SetControlMode(CANTalon::ControlMode::kSpeed);
	}
	talon->Enable();
	talon->EnableControl();
}

void cShooter::DisablePID()
{
	talon->ClearStickyFaults();
	talon->SetControlMode(CANTalon::ControlMode::kPercentVbus);
	talon->Set(0.0);
	talon->SetControlMode(CANTalon::ControlMode::kSpeed);
	talon->SetSetpoint(0.0);
	talon->Set(0.0);
	talon->Disable();
	talon->Reset();
}

void cShooter::ResetPID()
{
	talon->Reset();
}

void cShooter::setSetpoint(float setpoint)
{
	if (setpoint != this->setpoint) {
		this->setpoint = setpoint;
	}
	setpoint = (setpoint * SHOOTER_ENCODER_TICKS_PER_REV) / 10;
	talon->Set(setpoint);
	talon->SetSetpoint(setpoint);
}

double cShooter::getSetpoint()
{
	return talon->GetSetpoint();
}

void cShooter::setPID(double p, double i, double d)
{
	talon->SetPID(p, i, d);
}
