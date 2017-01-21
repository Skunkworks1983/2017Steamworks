#include "CommandBase.h"
#include "Commands/Scheduler.h"    //forward slash
#include "Subsystems\cDriveBase.h" //backslash

cDriveBase* CommandBase::s_drivebase = NULL;
OI* CommandBase::s_oi = NULL;

CommandBase::CommandBase(const std::string &name) :
		Command(name)
{
}
CommandBase::CommandBase() :
		Command()
{
}
void CommandBase::init()
{
}
