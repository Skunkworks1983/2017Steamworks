/*
 * cSwitchBackFront.cpp
 *
 *  Created on: Feb 15, 2017
 *      Author: s-4036956
 */

#include <Commands/DriveBase/cSwitchBackFront.h>
#include <Subsystems/cReversingMotorGroup.h>
#include <CommandBase.h>

cSwitchBackFront::cSwitchBackFront()
{
    Requires(CommandBase::s_drivebase);
    // TODO Auto-generated constructor stub
    

}

cSwitchBackFront::~cSwitchBackFront()
{
    // TODO Auto-generated destructor stub
}

void cSwitchBackFront::Initialize()
{
    CommandBase::s_drivebase->getMotorGroupGyro()->ToggleReversal();
}

void cSwitchBackFront::Execute()
{

}

bool cSwitchBackFront::IsFinished()
{
    return false;
}

void cSwitchBackFront::End()
{

}

void cSwitchBackFront::Interrupted()
{

}

