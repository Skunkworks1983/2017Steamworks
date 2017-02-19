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

cMotor::cMotor(int port, eMotorType motorType, bool hasEncoder, frc::CANSpeedController::ControlMode controlMode) :
        m_motor(port), m_motorType(motorType) //this is ok
{
    m_hasEncoder = hasEncoder;
    m_motor.SetControlMode(controlMode);
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
    switch(m_motorType)
    {
    case BaneBots775:
        if(m_motor.GetOutputCurrent() >= BANEBOTS775_STALLING_CURRENT)
        {
            m_motor.Set(0);
            return;
        }
        break;
    case NeveRest40:
        if(m_motor.GetOutputCurrent() >= NEVEREST40_STALLING_CURRENT)
        {
            m_motor.Set(0);
            return;
        }
        break;
    case CIM:
        if(m_motor.GetOutputCurrent() >= CIM_STALLING_CURRENT)
        {
            m_motor.Set(0);
            return;
        }
        break;
    }
    m_motor.Set(output);
}

void cMotor::PIDWrite(double output)
{
    setOutput(output);
}

double cMotor::PIDGet()
{
    return m_motor.PIDGet();
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
