#ifndef COMMAND_BASE_H
#define COMMAND_BASE_H

#include <Services/cMessenger.h>
#include <string>
#include "Commands/Command.h"
#include "OI.h"
#include "WPILib.h"
#include "Subsystems/cDriveBase.h"
#include "Subsystems/cClimber.h"
#include "Subsystems/cGearCollector.h"
#include "Subsystems/cFuelCollector.h"
#include "Subsystems/cFuelLoader.h"
#include "Subsystems/cShooter.h"
#include "Subsystems/cTurret.h"

/**
 * The base for all commands. All atomic commands should subclass CommandBase.
 * CommandBase stores creates and stores each control system. To access a
 * subsystem elsewhere in your code in your code use CommandBase.examplesubsystem
 */
class CommandBase: public Command
{
public:
    CommandBase(const std::string &name);
    CommandBase();
    static void init();
    static iDriveBase *s_drivebase;
    static iOI *s_oi;
    static cMessenger *s_boilerMessenger;
    static cMessenger* s_liftMessenger;
    static iClimber * s_climber;
    static iGearCollector* s_gearCollector;
    static iFuelCollector* s_fuelCollector;
    static iFuelLoader* s_fuelLoader;
    static iShooter* s_shooter;
    static iTurret* s_turret;
};

#endif
