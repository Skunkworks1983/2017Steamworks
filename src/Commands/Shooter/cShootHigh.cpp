/*
 * shootHigh.cpp
 *
 *  Created on: Jan 25, 2017
 *      Author: s-4036956
 */

#include <Commands/Shooter/cShootHigh.h>
#include <RobotMap.h>

cShootHigh::cShootHigh()
{
    // TODO Auto-generated constructor stub
    
}
void cShootHigh::Initialize()
{
    LOG_INFO("started cShootHigh");
}

void cShootHigh::Execute()
{

}

bool cShootHigh::IsFinished()
{
    return false;
}

void cShootHigh::End()
{
    LOG_INFO("ending cShootHigh");
}

void cShootHigh::Interrupted()
{
    LOG_INFO("interrupted cShootHigh");
}

cShootHigh::~cShootHigh()
{
    // TODO Auto-generated destructor stub
}

