#include <Commands/Autonomous/AutoBase.h>
#include <RobotMap.h>
#include <Commands/DriveBase/cDriveStraight.h>
#include <Commands/Turret/cAssignTargetBoiler.h>
#include <Commands/Shooter/cShootPID.h>
#include <Commands/Autonomous/cWait.h>
#include <Commands/FuelConveyor/cRunFuelConveyor.h>

AutoBase* AutoBase::goLiftCenter()
{
	float WAIT_TIME = 6;
	float DRIVE_DISTANCE = -7250;
	float DRIVE_STRAIGHT_SPEED = 0.2;
	float DRIVE_TIMEOUT = 5.5;
	float BACKUP_DIST = 100;
	float BACKUP_SPEED = -0.15;
	float BACKUP_TIMEOUT = 1;
	float SHOOTER_SETPOINT = 79;

    AutoBase* commands = new AutoBase();
    CommandGroup* waitThenIndex = new CommandGroup();
    CommandGroup* forwardThenBack = new CommandGroup();

    waitThenIndex->AddSequential(new cWait(WAIT_TIME));
	waitThenIndex->AddSequential(new cRunFuelConveyor());

	#ifdef PRACTICE_BOT
		commands->AddSequential(new cDriveStraight(7250, 0.3, 5)); //FIX WITH FORWARD THEN BACK
	#endif

	#ifndef PRACTICE_BOT
		forwardThenBack->AddSequential(new cDriveStraight(DRIVE_DISTANCE, DRIVE_STRAIGHT_SPEED, DRIVE_TIMEOUT));
		forwardThenBack->AddSequential(new cDriveStraight(BACKUP_DIST, BACKUP_SPEED, BACKUP_TIMEOUT));
	#endif

	commands->AddParallel(forwardThenBack);
	commands->AddParallel(new cAssignTargetBoiler(LIFT_MIDDLE));

	commands->AddParallel(new cShootPID(SHOOTER_SETPOINT));
	commands->AddParallel(waitThenIndex);

	std::cout << "Added cDriveStraight" << std::endl;

    return commands;
}
