/*
 * assignTargetGear.cpp
 *
 *  Created on: Jan 26, 2017
 *      Author: s-4036956
 */

#include <Commands/GearMechanism/cAssignTargetGear.h>
#include <RobotMap.h>
#include "cAssignTargetGear.h"

cAssignTargetGear::cAssignTargetGear()
{
    // TODO Auto-generated constructor stub
    
}
void cAssignTargetGear::Initialize()
{
    LOG_INFO("starting cAssignTargetGear");
}

void cAssignTargetGear::Execute()
{

}

bool cAssignTargetGear::IsFinished()
{
    return false;
}

void cAssignTargetGear::End()
{
    LOG_INFO("ending cAssignTargetGear");
}

void cAssignTargetGear::Interrupted()
{
    LOG_INFO("interrupted cAssignTargetGear");
    End();
}

cAssignTargetGear::~cAssignTargetGear()
{
    // TODO Auto-generated destructor stub
}

