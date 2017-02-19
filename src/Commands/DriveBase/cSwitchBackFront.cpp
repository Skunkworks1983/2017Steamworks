/*
 * cSwitchBackFront.cpp
 *
 *  Created on: Feb 15, 2017
 *      Author: s-4036956
 */

#include <Commands/DriveBase/cSwitchBackFront.h>
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
    CommandBase::s_drivebase->setIsReversed(!CommandBase::s_drivebase->getIsReversed());
}

void cSwitchBackFront::Execute()
{

}

bool cSwitchBackFront::IsFinished()
{
    return true;
}

void cSwitchBackFront::End()
{

}

void cSwitchBackFront::Interrupted()
{

}

