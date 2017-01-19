#include "CommandBase.h"
#include "Commands/Scheduler.h"    //forward slash
#include "Subsystems\cDriveBase.h" //backslash

cDriveBase* CommandBase::drivebase = NULL;

CommandBase::CommandBase(const std::string &name) :
		Command(name)
{
}

CommandBase::CommandBase() :
		Command()
{
//extraneous newline here fix please
}

void CommandBase::init()
{
}
