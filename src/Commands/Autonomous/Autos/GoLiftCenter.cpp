#include <Commands/Autonomous/AutoBase.h>
#include <RobotMap.h>
#include <Commands/DriveBase/cDriveStraight.h>
#include <Commands/Turret/cAssignTargetBoiler.h>
#include <Commands/Shooter/cShootPID.h>
#include <Commands/Autonomous/cWait.h>
#include <Commands/FuelConveyor/cRunFuelConveyor.h>
#include <Commands/DriveBase/cTurnAngle.h>
#include <Commands/Autonomous/cConditionalWiggle.h>

AutoBase* AutoBase::goLiftCenter()
{
    // constants
    float driveToLiftDistance = 7200;
    float driveToLiftSpeed = 0.25;
    float driveToLiftTimeout = 5;

    float backupFromLiftDistance = -100;
    float backupFromLiftSpeed = -0.25;
    float backupFromLiftTimeout = 5;

    // FUUUUUUUUUUUUdge
    float WIGGLE_SWEEP_ANGLE = 60; // the total angle we turn, far left to far right
    float WIGGLE_TURN_TIMEOUT = 1;

    float WIGGLE_BACKUP_DISTANCE = 1000;
    float WIGGLE_BACKUP_SPEED = 1;
    float WIGGLE_BACKUP_TIMEOUT = 1.5;

    // make commands: keep command groups in order! read bottom down
    AutoBase* commands = new AutoBase();

    CommandGroup* driveToLift = new CommandGroup();

    CommandGroup* shoot = new CommandGroup();
    CommandGroup* wiggle = new CommandGroup();


    driveToLift->AddSequential(new cDriveStraight(driveToLiftDistance, driveToLiftSpeed, driveToLiftTimeout)); // drive to lift
    driveToLift->AddParallel(new cAssignTargetBoiler(LIFT_MIDDLE)); // turn turret
    //driveToLift->AddParallel(new cShootPID(0)); // cShootPID broken
    driveToLift->AddSequential(new cDriveStraight(backupFromLiftDistance, backupFromLiftSpeed, backupFromLiftTimeout)); // back up to relieve spring pressure

    shoot->AddParallel(new cRunFuelConveyor(1, 10));

    // HOLLLYYY shirt TTHIS IS UALGY AS fudge AND TRIGGERING
    // AS heck PELASE FIX AFTER SEASON OR SOMETHIGN juan FSCHIREST
    wiggle->AddSequential(new cWait(2));

    wiggle->AddSequential(new cConditionalWiggle()); // ugly

    wiggle->AddSequential(new cDriveStraight(-WIGGLE_BACKUP_DISTANCE, -WIGGLE_BACKUP_SPEED, WIGGLE_BACKUP_TIMEOUT, true, true)); // don't even get me started here
    wiggle->AddSequential(new cTurnAngle(-WIGGLE_SWEEP_ANGLE / 2, WIGGLE_TURN_TIMEOUT, true));
    wiggle->AddSequential(new cTurnAngle(WIGGLE_SWEEP_ANGLE, WIGGLE_TURN_TIMEOUT, true));
    wiggle->AddSequential(new cTurnAngle(-WIGGLE_SWEEP_ANGLE / 2, WIGGLE_TURN_TIMEOUT, true));
    wiggle->AddSequential(new cDriveStraight(WIGGLE_BACKUP_DISTANCE, WIGGLE_BACKUP_SPEED, WIGGLE_BACKUP_TIMEOUT, true, true));


    // add commands and return base
    commands->AddSequential(driveToLift);

    commands->AddParallel(shoot);
    commands->AddParallel(wiggle);

    return commands;
}

    /*
	float WAIT_TIME = 6;
	float DRIVE_DISTANCE = -7250; // not used for wiggle
	float DRIVE_STRAIGHT_SPEED = 0.25; // not used wiggle
	float DRIVE_TIMEOUT = 5.5; // not used for wiggle
	float BACKUP_DIST = 100;
	float BACKUP_SPEED = -0.15;
	float BACKUP_TIMEOUT = 1;
	float SHOOTER_SETPOINT = 9700;

    AutoBase* commands = new AutoBase();
    CommandGroup* waitThenIndex = new CommandGroup();
    CommandGroup* forwardThenBack = new CommandGroup();

    cConditionalWiggle* wiggle = new cConditionalWiggle();

    commands->AddParallel(new cShootPID(SHOOTER_SETPOINT));

    waitThenIndex->AddSequential(new cWait(WAIT_TIME));
	waitThenIndex->AddSequential(new cRunFuelConveyor());

	#ifdef PRACTICE_BOT
		commands->AddSequential(new cDriveStraight(7250, 0.3, 5)); //FIX WITH FORWARD THEN BACK
	#endif

	#ifndef PRACTICE_BOT
		forwardThenBack->AddSequential(new cDriveStraight(DRIVE_DISTANCE, DRIVE_STRAIGHT_SPEED, DRIVE_TIMEOUT));
		forwardThenBack->AddSequential(new cDriveStraight(BACKUP_DIST, BACKUP_SPEED, BACKUP_TIMEOUT));
		forwardThenBack->AddSequential(new cWait(1.5));
		forwardThenBack->AddSequential(wiggle);
		forwardThenBack->AddSequential(wiggle->m_commands);
	#endif

	commands->AddParallel(forwardThenBack);
	commands->AddParallel(new cAssignTargetBoiler(LIFT_MIDDLE));

	commands->AddParallel(waitThenIndex);

	std::cout << "Added cDriveStraight" << std::endl;

    return commands;
}*/
