/*
 * cRotateTurret.cpp
 *
 *  Created on: Feb 5, 2017
 *      Author: s-4036956
 */

#include <Commands/Turret/cRotateTurret.h>
#include <RobotMap.h>
#include <CommandBase.h>
#include <Services/cMessage.h>
#include <Commands/Autonomous/Autobase.h>

cRotateTurret::cRotateTurret(float timeout)
{
    Requires(CommandBase::s_turret);

    if(timeout != 0)
    {
        SetTimeout(timeout);
    }
}

void cRotateTurret::Initialize()
{

}

void cRotateTurret::Execute()
{
    // only control the turret when manual control is disabled
    if(!CommandBase::s_turret->isManualEnabled())
    {
        // get the data from our vision system
        cBoilerData* data = CommandBase::s_boilerMessenger->receiveBoilerData();

        // turn the turret towards the boiler using our vision system
        if(data->isFound() && CommandBase::s_boilerMessenger->isNotTimedOut())
        {
            // get the current angle of the boiler relative to the turret
            float angle = data->getX() * (BOILER_PI_CAMERA_FOV / 2);
            float current = CommandBase::s_turret->getHeading();

            float desired = clamp(current + angle, -TURRET_SWEEP_RANGE / 2, TURRET_SWEEP_RANGE / 2);

            // TODO: motion tracking, idk what to call it
            // target leading? whatever
            CommandBase::s_turret->setOrientation(desired);
        }
        // turn the turret towards where we think the boiler is, using our gyro
        else
        {
            // searching
            //CommandBase::s_turret->setOrientation(alliance ? TURRET_SEARCH_HEADING : -TURRET_SEARCH_HEADING);
        }
    }
}

bool cRotateTurret::IsFinished()
{
    return IsTimedOut();
}

void cRotateTurret::End()
{

}

void cRotateTurret::Interrupted()
{
    End();
}

cRotateTurret::~cRotateTurret()
{

}

