/*
 * cSimpleDriveForward.cpp
 *
 *  Created on: Jan 28, 2017
 *      Author: s-4036956
 */

#include <Commands/Autonomous/cSimpleDriveForward.h>
#include <Subsystems/cDriveBase.h>
#include <RobotMap.h>
#include <CommandBase.h>

cSimpleDriveForward::cSimpleDriveForward()
{
    Requires(CommandBase::s_drivebase);
}

void cSimpleDriveForward::Initialize()
{
    //somehow get starting position as 0
    //yaw and pitch
    //set time? idk how though
}

void cSimpleDriveForward::Execute()
{

    CommandBase::s_drivebase->setLeftSpeed(.75);
    CommandBase::s_drivebase->setRightSpeed(.75);
}

bool cSimpleDriveForward::IsFinished()
{
    return false;
}

void cSimpleDriveForward::End()
{
    CommandBase::s_drivebase->setLeftSpeed(0);
    CommandBase::s_drivebase->setLeftSpeed(0);
}

void cSimpleDriveForward::Interrupted()
{

}

cSimpleDriveForward::~cSimpleDriveForward()
{

}
