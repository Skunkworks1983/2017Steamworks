#include "cTurnAngle.h"
#include <RobotMap.h>
#include <time.h>

cTurnAngle::cTurnAngle(float angle)
{
    Requires(CommandBase::s_drivebase);

    m_finalAngle = angle + CommandBase::s_drivebase->getGyro()->getAngle();

    m_lastTime = clock();
    m_timeInTarget = 0;

    m_outputController = new PIDController(TURNDEGREE_PID_P, TURNDEGREE_PID_I, TURNDEGREE_PID_D,
            CommandBase::s_drivebase->getGyro(), this);

    m_outputController->Disable();

    m_outputController->SetOutputRange(-1, 1);
}

void cTurnAngle::Initialize()
{
    m_outputController->Enable();
    m_outputController->SetSetpoint(m_finalAngle);
}

void cTurnAngle::Execute()
{
    if(abs(m_finalAngle - CommandBase::s_drivebase->getGyro()->getAngle()) < TURNANGLE_ANGLE_OK_RANGE)
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
    return m_timeInTarget > TURNANGLE_ANGLE_OK_TIMEOUT;
}

void cTurnAngle::End()
{
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
