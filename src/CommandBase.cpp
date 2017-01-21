#include "CommandBase.h"
#include "Commands/Scheduler.h"
#include "Subsystems\cDriveBase.h"

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
