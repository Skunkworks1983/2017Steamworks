/*
 * cMotor.cpp
 *
 *  Created on: Jan 17, 2017
 *      Author: s-4036956
 */

#include <Subsystems/cMotor.h>
#include <CANTalon.h>
#include <RobotMap.h>

cMotor::cMotor(int port, bool hasEncoder):m_motor(port) //this is ok
{
    m_hasEncoder = hasEncoder;
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
bool cMotor::hasEncoder()
{
    return m_hasEncoder;
}
