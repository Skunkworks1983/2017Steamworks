/*
 * cMotorGroup.cpp
 *
 *  Created on: Feb 1, 2017
 *      Author: s-4036956
 */

#include <Subsystems/Utilities/cMotorGroup.h>

cMotorGroup::cMotorGroup(std::vector<iMotor*> motorList) :
        m_motorList(motorList)
{
    
}

void cMotorGroup::setBrakeMode(bool brake)
{
    for(std::size_t i = 0; i < m_motorList.size(); i++)
    {
        m_motorList[i]->setBrakeMode(brake);
    }
}

void cMotorGroup::setOutput(float output)
{
    for(std::size_t i = 0; i < m_motorList.size(); i++)
    {
        m_motorList[i]->setOutput(output);
    }
}

void cMotorGroup::PIDWrite(double output)
{
    for(std::size_t i = 0; i < m_motorList.size(); i++)
    {
        m_motorList[i]->PIDWrite(output);
    }
}

void cMotorGroup::setEnabled(bool enabled)
{
    for(std::size_t i = 0; i < m_motorList.size(); i++)
    {
        m_motorList[i]->setEnabled(enabled);
    }
}

double cMotorGroup::PIDGet()
{
    for(std::size_t i = 0; i < m_motorList.size(); i++)
    {
        if(m_motorList[i]->hasEncoder())
        {
            return m_motorList[i]->PIDGet();
        }
    }
    return 0;
}
cMotorGroup::~cMotorGroup()
{
// TODO Auto-generated destructor stub
}

bool cMotorGroup::hasEncoder()
{
    for(std::size_t i = 0; i < m_motorList.size(); i++)
    {
        if(m_motorList[i]->hasEncoder())
        {
            return true;
        }
    }
    return false; //TODO fix this
}

std::vector<iMotor*> cMotorGroup::GetMotorList()
{
    return m_motorList;
}

frc::CANSpeedController::ControlMode cMotorGroup::getControlMode()
{
    return m_motorList[0]->getControlMode();
}

void cMotorGroup::setControlMode(frc::CANSpeedController::ControlMode mode)
{
    for(std::size_t i = 0; i < m_motorList.size(); i++)
    {
        m_motorList[i]->setControlMode(mode);
    }
}

void cMotorGroup::setSetpoint(double value)
{
    for(std::size_t i = 0; i < m_motorList.size(); i++)
    {
        m_motorList[i]->setSetpoint(value);
    }
}

double cMotorGroup::getPosition()
{
    for(std::size_t i = 0; i < m_motorList.size(); i++)
    {
        if(m_motorList[i]->hasEncoder())
        {
            return m_motorList[i]->getPosition();
        }
    }

    return 0;
}

void cMotorGroup::setPosition(double position)
{

}

double cMotorGroup::getOutput() {
	//SOMEBODY PUT SOMETHING HERE
	//WHAT ON HECK EVEN IS THIS
	//I ONLY PUT THIS HERE BECAUSE ECLIPSE GAVE ME A WARNING
	//this is bella btw
	//TODO

	return 1234;
}
