/*
 * This command waits for the
 * shooter to get up to speed and
 * for the turret to be aiming at a
 * target before running the fuel indexer.
 */

#include <Commands/Shooter/cShootWhenReady.h>
#include <CommandBase.h>
#include <math.h>
#include <RobotMap.h>

cShootWhenReady::cShootWhenReady(float timeout)
{
    SetTimeout(timeout);
}

void cShootWhenReady::Initialize()
{
    Requires(CommandBase::s_turret);
    Requires(CommandBase::s_shooter);
    Requires(CommandBase::s_fuelIndexer);
}

void cShootWhenReady::Execute()
{
    if(!CommandBase::s_turret->isManualEnabled() && !CommandBase::s_shooter->isManualEnabled())
    {
        // check whether or not we're in the
        bool turretReady = abs(CommandBase::s_turret->PIDGet() - CommandBase::s_turret->getSetpoint())
                < CommandBase::s_turret->getSetpoint() * (TURRET_ANGLE_TOLERANCE / 2);

        bool shooterReady = abs(CommandBase::s_shooter->PIDGet() - CommandBase::s_shooter->getSetpoint())
                < CommandBase::s_shooter->getSetpoint() * (SHOOTER_SPEED_TOLERANCE / 2);

        if(turretReady && shooterReady)
        {
            // run the indexer to load balls into the shooter
            CommandBase::s_fuelIndexer->setSpeed(FUELINDEXER_MOTOR1_SPEED);
        }
        else
        {
            CommandBase::s_fuelIndexer->setSpeed(0);
        }
    }
}

bool cShootWhenReady::IsFinished()
{
    return IsTimedOut();
}

void cShootWhenReady::End()
{
    CommandBase::s_fuelIndexer->setSpeed(0);
}

void cShootWhenReady::Interrupted()
{
    End();
}

cShootWhenReady::~cShootWhenReady()
{
    // TODO Auto-generated constructor stub
    
}
