#ifndef COMMAND_BASE_H
#define COMMAND_BASE_H

#include <string>
#include "Commands/Command.h" //fslash
#include "OI.h"
#include "WPILib.h"
#include "Subsystems\cDriveBase.h" //bslash
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
	static cDriveBase *drivebase; //used c at beginning but not necessary (see rules)
};

#endif
