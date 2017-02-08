/*
 * assignTargetBoiler.cpp
 *
 *  Created on: Jan 26, 2017
 *      Author: s-4036956
 */

#include <RobotMap.h>
#include "cAssignTargetBoiler.h"

cAssignTargetBoiler::cAssignTargetBoiler()
{
    // TODO Auto-generated constructor stub
    
}
void cAssignTargetBoiler::Initialize()
{
    LOG_INFO("starting cAssignTargetBoiler");
}

void cAssignTargetBoiler::Execute()
{

}

bool cAssignTargetBoiler::IsFinished()
{
    return false;
}

void cAssignTargetBoiler::End()
{
    LOG_INFO("ending cAssignTargetBoiler");
}

void cAssignTargetBoiler::Interrupted()
{
    LOG_INFO("interrupted cAssignTargetBoiler");
    End();
}

cAssignTargetBoiler::~cAssignTargetBoiler()
{
    // TODO Auto-generated destructor stub
}

