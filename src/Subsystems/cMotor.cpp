/*
 * cMotor.cpp
 *
 *  Created on: Jan 17, 2017
 *      Author: s-4036956
 */

#include <cMotor.h>
#include <CANTalon.h>
#include <RobotMap.h>

cMotor::cMotor(int port) :
        m_motor(port)
{
}

cMotor::~cMotor()
{
}
void cMotor::setBrakeMode(bool brake)

{
    if(brake == true)
    {
        m_motor.ConfigNeutralMode(CANSpeedController::kNeutralMode_Brake);
    }
    else
    {
        m_motor.ConfigNeutralMode(CANSpeedController::kNeutralMode_Coast);
    }

}
void cMotor::setOutput(float output)
{
    m_motor.Set(output);
}
void cMotor::PIDWrite(double output)
{
    m_motor.Set(output);
}
double cMotor::PIDGet()
{
    return m_motor.GetEncPosition();
    //we need to change this, not right
    //return sensor output for pid
}

void cMotor::setEnabled(bool enabled)
{
    if(m_motor.IsEnabled() && !enabled)
    {
        m_motor.Enable();
    }
    if(!m_motor.IsEnabled() && enabled)
    {
        m_motor.Disable();
    }

}


////
////shooter
double cMotor::GetSpeed() const
{
	return m_motor.GetSpeed();
}

void cMotor::SetSetpoint(double value)
{
	return m_motor.SetSetpoint(value);
}

double cMotor::GetSetpoint() const
{
	return m_motor.GetSetpoint();
}

void cMotor::SetPID(double p, double i, double d, double f)
{
	return m_motor.SetPID(p, i, d, f);
}

void cMotor::Set(double value)
{
	m_motor.Set(value);
}

void cMotor::reverseSensorDirection()
{
	m_motor.SetSensorDirection(true);
}

void cMotor::reverseOutput()
{
	m_motor.SetClosedLoopOutputDirection(true);
}

void cMotor::setFeedbackDevice()
{
	m_motor.SetFeedbackDevice(CANTalon::FeedbackDevice::QuadEncoder); //need to ask someone about this
}

bool cMotor::isEnabled() const
{
	return m_motor.IsEnabled();
}

int cMotor::getClosedLoopError() const
{
	return m_motor.GetClosedLoopError();
}

void cMotor::Enable()
{
	m_motor.Enable();
	m_motor.EnableControl();
}

void cMotor::Disable()
{
	m_motor.ClearStickyFaults();
	m_motor.SetControlMode(CANTalon::ControlMode::kPercentVbus);
	m_motor.Set(0.0);
	m_motor.SetControlMode(CANTalon::ControlMode::kSpeed);
	m_motor.SetSetpoint(0.0);
	m_motor.Set(0.0);
	m_motor.Disable();
	m_motor.Reset();
}

void cMotor::Reset()
{
	m_motor.Reset();
}
