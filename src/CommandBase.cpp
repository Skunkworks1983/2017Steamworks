#include "CommandBase.h"
#include "Commands/Scheduler.h"
#include "Subsystems/cDriveBase.h"
#include "Subsystems/cClimber.h"
#include "Subsystems/cGearCollector.h"
#include "Subsystems/Interfaces/iDriveBase.h"

iDriveBase* CommandBase::s_drivebase = NULL;
iClimber* CommandBase::s_climber = NULL;
iOI* CommandBase::s_oi = NULL;
iMessenger* CommandBase::s_boilerMessenger = NULL;
iMessenger* CommandBase::s_liftMessenger = NULL;
iGearCollector* CommandBase::s_gearCollector = NULL;
iFuelCollector* CommandBase::s_floorCollector = NULL;
iFuelIndexer* CommandBase::s_fuelIndexer = NULL;
iFuelConveyor* CommandBase::s_fuelConveyor = NULL;
iShooter* CommandBase::s_shooter = NULL;
iTurret* CommandBase::s_turret = NULL;
bool CommandBase::m_postMatch = false;

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
