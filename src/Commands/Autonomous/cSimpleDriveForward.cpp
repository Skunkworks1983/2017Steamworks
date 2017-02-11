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


cSimpleDriveForward::cSimpleDriveForward(float distance, bool mode)
{
    Requires(CommandBase::s_drivebase);
    double p = SIMPLEDRIVEFORWARD_PID_P;
    double i = SIMPLEDRIVEFORWARD_PID_I;
    double d = SIMPLEDRIVEFORWARD_PID_D;
    m_driveToLine = mode;
    motorGroupAll = CommandBase::s_drivebase->getMotorGroupAll();
    this->m_pidController = new PIDController(p, i, d, motorGroupAll, motorGroupAll);
    this->m_distance = (distance / DRIVEBASE_FOOT_PER_TICK);
}

void cSimpleDriveForward::Initialize()
{
    m_pidController->SetSetpoint(m_distance);
    m_pidController->Enable();
}

void cSimpleDriveForward::Execute()
{
	if (m_driveToLine == true) {
		if (CommandBase::s_drivebase->CanSeeTape() == true) {
			End();
		}
	}
}

bool cSimpleDriveForward::IsFinished()
{
    return m_pidController->OnTarget(); //TODO ensure is set up
}

void cSimpleDriveForward::End()
{
    CommandBase::s_drivebase->setLeftSpeed(0);
    CommandBase::s_drivebase->setRightSpeed(0);
    m_pidController->Disable();
}

void cSimpleDriveForward::Interrupted()
{
    End();
}

cSimpleDriveForward::~cSimpleDriveForward()
{
    delete m_pidController;
}
