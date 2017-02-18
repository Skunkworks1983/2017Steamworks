/*
 * cTurnDegree.cpp
 *
 *  Created on: Jan 28, 2017
 *      Author: s-4036956
 */

#include <Commands/Autonomous/cTurnDegree.h>
#include <CommandBase.h>
#include <Subsystems/cDriveBase.h>
#include <RobotMap.h>
#include <PIDController.h>
#include <Subsystems/Sensors/cGyro.h>


cTurnDegree::cTurnDegree(float targetAngle)
{
    m_targetAngle = targetAngle;
    m_motorGroupGyro = CommandBase::s_drivebase->getMotorGroupGyro();
    m_realNiceGyro = CommandBase:: s_drivebase->getGyro();
    this->m_pidController = new PIDController(TURNDEGREE_PID_P, TURNDEGREE_PID_I, TURNDEGREE_PID_D ,m_realNiceGyro, m_motorGroupGyro);
    m_pidController->SetSetpoint(m_targetAngle);
}

void cTurnDegree::Initialize()
{
    m_pidController->Enable();
    m_pidController->SetAbsoluteTolerance(TURNANGLE_ABSTOLERANCE_ANGLE);
}

void cTurnDegree::Execute()
{

}

bool cTurnDegree::IsFinished()
{
    return m_pidController->OnTarget();
}

void cTurnDegree::End()
{
    m_pidController->Disable();
}

void cTurnDegree::Interrupted()
{
    End();
}

