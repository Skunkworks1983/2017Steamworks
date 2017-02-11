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
    static cDriveBase *s_drivebase;
    static OI *s_oi;
    static cMessenger *s_boilerMessenger;
    static cMessenger* s_liftMessenger;
    static cClimber * s_climber;
    static cGearCollector* s_gearCollector;
    static cFuelCollector* s_fuelCollector;
    static cFuelLoader* s_fuelLoader;
    static cShooter* s_shooter;
};

#endif
