#include "CommandBase.h"
#include "Commands/Scheduler.h"
#include "Subsystems/cDriveBase.h"
#include "Subsystems/cClimber.h"
#include "Subsystems/cGearCollector.h"

cDriveBase* CommandBase::s_drivebase = NULL;
cClimber* CommandBase::s_climber = NULL;
OI* CommandBase::s_oi = NULL;
cMessenger* CommandBase::s_boilerMessenger = NULL;
cMessenger* CommandBase::s_liftMessenger = NULL;
cGearCollector* CommandBase::s_gearCollector = NULL;
cFuelCollector* CommandBase::s_fuelCollector = NULL;
cFuelLoader* CommandBase::s_fuelLoader = NULL;
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
