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
             /*
             float yaw_current = CommandBase::s_turret->m_servoYaw->GetAngle();
             float yaw_final = yaw_current + (data->getX() > 0 ? -1 : 1);

             CommandBase::s_turret->m_servoYaw->SetAngle(yaw_final);

             bool m_manualEnabled = false;
             float pitch_current = CommandBase::s_turret->m_servoPitch->GetAngle();
             float pitch_final = pitch_current + (data->getY() > 0 ? -1 : 1);

             CommandBase::s_turret->m_servoPitch->SetAngle(pitch_final);
             */
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

