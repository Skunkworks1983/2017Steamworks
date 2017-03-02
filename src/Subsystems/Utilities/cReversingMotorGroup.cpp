/*
 * cReversingMotorGroup.cpp
 *
 *  Created on: Feb 8, 2017
 *      Author: s-4036956
 */

#include <Subsystems/Utilities/cReversingMotorGroup.h>

cReversingMotorGroup::cReversingMotorGroup(std::vector<bool> motorReverse, std::vector<iMotor*> motorList) :
        cMotorGroup(motorList), m_motorReverse(motorReverse)
{

}

cReversingMotorGroup::~cReversingMotorGroup()
{

}

void cReversingMotorGroup::setOutput(float output)
{
    for(std::size_t i = 0; i < cMotorGroup::GetMotorList().size(); i++)
    {
        if(m_motorReverse[i] == true)
        {
            cMotorGroup::GetMotorList()[i]->setOutput(-output);
        }
        else
        {
           cMotorGroup::GetMotorList()[i]->setOutput(output);
        }
    }
}

void cReversingMotorGroup::PIDWrite(double output)
{
    setOutput(output);
}


