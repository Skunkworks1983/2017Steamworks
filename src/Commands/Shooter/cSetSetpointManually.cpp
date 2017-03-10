/*
 * cSetSetpointManually.cpp
 *
 *  Created on: Feb 22, 2017
 *      Author: S-2505674
 */
#include "cSetSetpointManually.h"
#include "Subsystems/cShooter.h"
#include "CommandBase.h"
#include "OI.h"
#include "RobotMap.h"


cSetSetpointManually::cSetSetpointManually(float timeout) : timeout(timeout)
{
	Requires (CommandBase::s_shooter);
}

void cSetSetpointManually::Initialize()
{
	std::cout << "cSetSetpointManually Initialize";
	CommandBase::s_shooter->setManualEnabled(true);
	CommandBase::s_shooter->EnablePID();
	CommandBase::s_shooter->setPID(p, i, d, f);

	if(timeout != 0){
		SetTimeout(timeout);
	}
}

void cSetSetpointManually::Execute()
{
	std::cout << "cSetSetpointManually Execute";
	if (!CommandBase::s_shooter->isPIDEnabled()) {
		CommandBase::s_shooter->EnablePID();
	}

	CommandBase::s_shooter->setSetpoint(CommandBase::s_oi->getShooterSlider()*MANUAL_SHOOTER_CONTROL_SCALAR);
}

bool cSetSetpointManually::IsFinished()
{
	return IsTimedOut();
}

void cSetSetpointManually::End()
{
	CommandBase::s_shooter->setManualEnabled(false);
	CommandBase::s_shooter->DisablePID();
	std::cout << "cSetSetpointManually Ended";
}

void cSetSetpointManually::Interrupted()
{
	End();
}

