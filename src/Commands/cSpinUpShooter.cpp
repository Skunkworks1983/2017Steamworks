/*
 * spinUpShooter.cpp
 *
 *  Created on: Jan 25, 2017
 *      Author: s-4036956
 */

#include <Commands/cSpinUpShooter.h>
#include <RobotMap.h>

cSpinUpShooter::cSpinUpShooter()
{
    // TODO Auto-generated constructor stub
    
}
void cSpinUpShooter::Initialize()
{
    LOG_INFO("starting cSpinUpShooter");
}

void cSpinUpShooter::Execute()
{

}

bool cSpinUpShooter::IsFinished()
{
    return false;
}

void cSpinUpShooter::End()
{
    LOG_INFO("ending cSpinUpShooter");
}

void cSpinUpShooter::Interrupted()
{
    LOG_INFO("interrupted cSpinUpShooter");
}

cSpinUpShooter::~cSpinUpShooter()
{
    // TODO Auto-generated destructor stub
}

