#include "CommandBase.h"
#include "Commands/Scheduler.h"
#include "Subsystems/cDriveBase.h"
#include "Subsystems/cClimber.h"
#include "Subsystems/cGearCollector.h"
#include "Subsystems/iDriveBase.h"

iDriveBase* CommandBase::s_drivebase = NULL;
iClimber* CommandBase::s_climber = NULL;
OI* CommandBase::s_oi = NULL;
cMessenger* CommandBase::s_boilerMessenger = NULL;
cMessenger* CommandBase::s_liftMessenger = NULL;
iGearCollector* CommandBase::s_gearCollector = NULL;
iFuelCollector* CommandBase::s_fuelCollector = NULL;
iFuelLoader* CommandBase::s_fuelLoader = NULL;
iShooter* CommandBase::s_shooter = NULL;
iTurret* CommandBase::s_turret = NULL;

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
