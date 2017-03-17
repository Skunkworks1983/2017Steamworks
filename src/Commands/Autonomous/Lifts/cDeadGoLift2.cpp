#include "../AutoBase.h"
#include <RobotMap.h>
#include <Commands/DriveBase/cDriveStraight.h>
#include <Commands/Turret/cAssignTargetBoiler.h>
#include <Commands/Shooter/cShootPID.h>
#include <Commands/Autonomous/cWait.h>
#include <Commands/FuelConveyor/cRunFuelConveyor.h>

AutoBase* AutoBase::goDead2()
{
    AutoBase* commands = new AutoBase();
    CommandGroup* waitThenIndex = new CommandGroup();

    waitThenIndex->AddSequential(new cWait(5));
	waitThenIndex->AddSequential(new cRunFuelConveyor());

	#ifdef PRACTICE_BOT
		commands->AddSequential(new cDriveStraight(7250, 0.3, 5));
	#endif

	#ifndef PRACTICE_BOT
		commands->AddSequential(new cDriveStraight(-7250, 0.2, 5));
	#endif

	commands->AddSequential(new cAssignTargetBoiler(LIFT_MIDDLE));

	commands->AddParallel(new cShootPID(79));
	commands->AddParallel(waitThenIndex);

	std::cout << "Added cDriveStraight" << std::endl;

    return commands;
}
