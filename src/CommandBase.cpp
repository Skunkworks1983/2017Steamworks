#include "CommandBase.h"
#include "Commands/Scheduler.h"
#include "Subsystems/cDriveBase.h"
#include "Subsystems/cClimber.h"

cDriveBase* CommandBase::s_drivebase = NULL;
cClimber* CommandBase::s_climber = NULL;
OI* CommandBase::s_oi = NULL;
cMessenger* CommandBase::s_messenger = NULL;
cGearCollector* CommandBase::s_gearCollector = NULL;
cShooter* CommandBase::s_shooter = NULL;

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
