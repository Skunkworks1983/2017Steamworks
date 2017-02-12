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

