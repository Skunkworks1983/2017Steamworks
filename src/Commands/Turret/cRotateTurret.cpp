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
        if(data->isFound())
        {
            float angle = data->getX() * (53.5/2); // the angular pos of boiler on screen
            float current;

            float target = current + angle;

            CommandBase::s_turret->setOrientation(target);

        }
        // turn the turret towards where we think the boiler is, using our gyro
        else
        {
            //CommandBase::s_turret->setOrientation(CommandBase::s_turret->m_isRedAlliance ? -45 : 45);
        }
    }
}

bool cRotateTurret::IsFinished()
{
    return false;
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

