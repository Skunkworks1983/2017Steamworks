#include "CommandBase.h"
#include "Commands/Scheduler.h"



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
