#include "cTurnAngle.h"
#include <RobotMap.h>
#include <time.h>
#include <Commands/Autonomous/AutoBase.h>

cTurnAngle::cTurnAngle(float angle, float timeout, bool isWiggle) : m_isWiggle(isWiggle)
{
    Requires(CommandBase::s_drivebase);

    SetTimeout(timeout);

    float TURNANGLE_PID_P = 0.0325/0.75;
    float TURNANGLE_PID_I = 0;
    float TURNANGLE_PID_D = 0.075;

    m_startAngle = angle;
    m_finalAngle = 0; //set in initialize

    m_timeInTarget = 0;

    m_outputController = new PIDController(TURNANGLE_PID_P, TURNANGLE_PID_I, TURNANGLE_PID_D,
            CommandBase::s_drivebase->getGyro(), this);

    m_outputController->Disable();

    m_outputController->SetOutputRange(-0.5, 0.5);
}

void cTurnAngle::Initialize()
{
	m_finalAngle = m_startAngle + CommandBase::s_drivebase->getGyro()->getAngle();
	m_outputController->SetSetpoint(m_finalAngle);
    m_outputController->Enable();
    m_outputController->SetAbsoluteTolerance(TURNANGLE_ANGLE_OK_RANGE);
}

void cTurnAngle::Execute()
{
    if(m_outputController->OnTarget())
    {
        // ask me whats going on here if i dont add a comment eventually
        // doesnt actually return time
        m_timeInTarget += 0.01;
    }
    else
    {
        m_timeInTarget = 0;
    }
}

bool cTurnAngle::IsFinished()
{
    // TODO TODO TODO magic number range
	return m_timeInTarget > TURNANGLE_ANGLE_OK_TIMEOUT || IsTimedOut() || ((m_isWiggle && !AutoBase::m_wiggle));
}

void cTurnAngle::End()
{
	std::cout << "cTurnAngle end" << std::endl;
    m_outputController->Disable();
}

void cTurnAngle::Interrupted()
{
    End();
}

void cTurnAngle::PIDWrite(double output)
{
    output = clamp(output, -0.5, 0.5);

    CommandBase::s_drivebase->setLeftSpeed(-output);
    CommandBase::s_drivebase->setRightSpeed(output);
}
