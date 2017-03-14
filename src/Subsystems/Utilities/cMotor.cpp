/*
 * cMotor.cpp
 *
 *  Created on: Jan 17, 2017
 *      Author: s-4036956
 */

#include <Subsystems/Utilities/cMotor.h>
#include <CANSpeedController.h>
#include <CANTalon.h>
#include <RobotMap.h>
#include <Utility.h>

cMotor::cMotor(int port, eMotorType motorType, bool hasEncoder, frc::CANSpeedController::ControlMode controlMode) :
        m_motor(port), m_motorType(motorType) //this is ok
{
    m_hasEncoder = hasEncoder;
    m_motor.SetControlMode(controlMode);

    m_timeStall = 0;
}

cMotor::~cMotor()
{

}

void cMotor::setBrakeMode(bool brake)
{
    if(brake == true)
    {
        m_motor.ConfigNeutralMode(frc::CANSpeedController::kNeutralMode_Brake);
    }
    else
    {
        m_motor.ConfigNeutralMode(frc::CANSpeedController::kNeutralMode_Coast);
    }
}

void cMotor::setOutput(float output)
{
    if(GetFPGATime() > m_timeStall + 250000)
    {
        switch(m_motorType)
        {
        case BaneBots775:
            if(m_motor.GetOutputCurrent() >= BANEBOTS775_STALLING_CURRENT)
            {
                m_motor.Set(0);
                m_timeStall = GetFPGATime();
                LOG_WARNING("BaneBots775 stall");
                return;
            }
            break;
        case NeveRest40:
            if(m_motor.GetOutputCurrent() >= NEVEREST40_STALLING_CURRENT)
            {
                m_motor.Set(0);
                m_timeStall = GetFPGATime();
                LOG_WARNING("NeveRest40 stall");
                return;
            }
            break;
        case CIM:
            if(m_motor.GetOutputCurrent() >= CIM_STALLING_CURRENT)
            {
                m_motor.Set(0);
                m_timeStall = GetFPGATime();
                LOG_WARNING("CIM stall");
                return;
            }
            break;
        }
        m_motor.Set(output);
    }
    else {
        m_motor.Set(0); //kill.
    }
}

void cMotor::PIDWrite(double output)
{
    setOutput(output);
}

double cMotor::PIDGet()
{
    return m_motor.GetPosition();
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

bool cMotor::hasEncoder()
{
    return m_hasEncoder;
}

frc::CANSpeedController::ControlMode cMotor::getControlMode()
{
    return m_motor.GetControlMode();
}

void cMotor::setControlMode(frc::CANSpeedController::ControlMode mode)
{
    m_motor.SetControlMode(mode);
}

void cMotor::setSetpoint(double value)
{
    m_motor.SetSetpoint(value);
}

double cMotor::getPosition()
{
    return m_motor.GetPosition();
}

void cMotor::configForwardLimit(double position)
{
    m_motor.ConfigForwardLimit(position);
}

void cMotor::configReverseLimit(double position)
{
    m_motor.ConfigReverseLimit(position);
}

////
////shooter
double cMotor::GetSpeed() const
{
    return m_motor.GetSpeed();
}

void cMotor::SetSetpoint(double setpoint)
{
	return m_motor.SetSetpoint(setpoint);
}

double cMotor::GetSetpoint() const
{
    return m_motor.GetSetpoint();
}

void cMotor::SetPID(double p, double i, double d, double f)
{
	m_motor.SelectProfileSlot(0);
	m_motor.ConfigMaxOutputVoltage(12);
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

void cMotor::setPosition(double position)
{
    m_motor.SetPosition(position);
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

double cMotor::getOutput() {
	return m_motor.Get();
}
