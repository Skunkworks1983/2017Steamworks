#include <Commands/Autonomous/AutoBase.h>
#include <Commands/Autonomous/cWait.h>
#include <Commands/FuelConveyor/cRunFuelConveyor.h>
#include <Commands/DriveBase/cDriveStraight.h>
#include <Commands/Turret/cSetTurretSetpoint.h>
#include <Commands/Shooter/cShootPID.h>
#include <Commands/CommandGroup.h>
#include <RobotMap.h>
#include <Commands/DriveBase/cTurnAngle.h>
#include <Commands/Autonomous/cConditionalWiggle.h>
#include <Commands/Turret/cAssignTargetBoiler.h>
#include <Commands/Autonomous/AutoBase.h>

AutoBase* AutoBase::goLiftBoiler()
{
    float backupFromLiftDistance = -100;
    float backupFromLiftSpeed = -0.25;
    float backupFromLiftTimeout = 5;

    // FUUUUUUUUUUUUdge
    float WIGGLE_SWEEP_ANGLE = 60; // the total angle we turn, far left to far right
    float WIGGLE_TURN_TIMEOUT = 1;

    float WIGGLE_BACKUP_DISTANCE = 1000;
    float WIGGLE_BACKUP_SPEED = .25;
    float WIGGLE_BACKUP_TIMEOUT = 1.5;

    float mult = AutoBase::getAlliance() == eAlliance::RED ? 1 : -1;

    // make commands: keep command groups in order! read bottom down
    AutoBase* commands = new AutoBase();

    CommandGroup* driveToLift = new CommandGroup();

    CommandGroup* shoot = new CommandGroup();
    CommandGroup* wiggle = new CommandGroup();

    driveToLift->AddParallel(new cAssignTargetBoiler(LIFT_CLOSE)); // turn turret
    driveToLift->AddSequential(new cDriveStraight(FLIP*7250, 0.5, 7)); // drive to lift
    driveToLift->AddSequential(new cTurnAngle(-60 * mult, 3));
    driveToLift->AddSequential(new cDriveStraight(FLIP*3000, 0.5, 3)); // drive to lift
    driveToLift->AddSequential(new cDriveStraight(FLIP*backupFromLiftDistance, backupFromLiftSpeed, backupFromLiftTimeout)); // back up to relieve spring pressure
    driveToLift->AddSequential(new cWait(2));

	driveToLift->AddSequential(new cConditionalWiggle()); // ugly

	driveToLift->AddSequential(new cDriveStraight(-WIGGLE_BACKUP_DISTANCE, -WIGGLE_BACKUP_SPEED, WIGGLE_BACKUP_TIMEOUT, true, true)); // don't even get me started here
	driveToLift->AddSequential(new cTurnAngle(-WIGGLE_SWEEP_ANGLE / 2, WIGGLE_TURN_TIMEOUT, true));
	driveToLift->AddSequential(new cTurnAngle(WIGGLE_SWEEP_ANGLE, WIGGLE_TURN_TIMEOUT, true));
	driveToLift->AddSequential(new cTurnAngle(-WIGGLE_SWEEP_ANGLE / 2, WIGGLE_TURN_TIMEOUT, true));
	driveToLift->AddSequential(new cDriveStraight(WIGGLE_BACKUP_DISTANCE * 2, WIGGLE_BACKUP_SPEED, WIGGLE_BACKUP_TIMEOUT, true, true));

	shoot->AddParallel(new cWait(0.01));
	shoot->AddParallel(new cShootPID(0));
	shoot->AddSequential(new cWait(5));
	shoot->AddSequential(new cRunFuelConveyor(1, 10));

    // HOLLLYYY shirt TTHIS IS UALGY AS fudge AND TRIGGERING
    // AS heck PELASE FIX AFTER SEASON OR SOMETHIGN juan FSCHIREST



    // add commands and return base
    commands->AddParallel(driveToLift);

    commands->AddParallel(shoot);
    //commands->AddParallel(wiggle);

    return commands;
}
    /*
	float WAIT_TIME = 6;
	float TURRET_BLUE_SETPOINT = TURRET_SWEEP_RANGE+2050; //quod? TODO
	float TURRET_RED_SETPOINT = -2800; //placeholder TODO
	float SHOOTER_SETPOINT = 9500; //the placest of holders TODO
    const std::string friendlyWarning = "But the soul is still oracular; amid the market's din \nList the ominous stern whisper from the Delphic cave within \nThey enslave their children's children who make compromise with sin";
    std::cout << "GO LIFT BOILER" << std::endl;
    AutoBase* commands = new AutoBase();
    CommandGroup* shooting = new CommandGroup();
    CommandGroup* driving = new CommandGroup();

    cConditionalWiggle* wiggle = new cConditionalWiggle();

    shooting->AddParallel(new cShootPID(SHOOTER_SETPOINT)); //is this sequential? is this parallel? does evil exist, or are there just good people making bad decisions? these are the things I wonder
    CommandBase::s_turret->m_heading = TurretShootPosition::CloseLift;

    shooting->AddParallel(new cAssignTargetBoiler(LIFT_CLOSE));

    driving->AddSequential(new cDriveStraight(-0.885 * BOILER_START_DRIVE_DISTANCE));
    if (AutoBase::getAlliance() == 	RED) {
        driving->AddSequential(new cTurnAngle(-1 * BOILER_START_FIRST_ANGLE));
    } else {
    	driving->AddSequential(new cTurnAngle(BOILER_START_FIRST_ANGLE));
    }

    driving->AddSequential(new cDriveStraight(DISTANCE_BASE_LINE_TO_PEG * 2, .25, 1, true));
    driving->AddSequential(new cDriveStraight(-100, .25, .5, true));

    driving->AddSequential(new cWait(.5));
    driving->AddSequential(wiggle);
    driving->AddSequential(wiggle->m_commands);

	CommandGroup* waitThenIndex = new CommandGroup();
	waitThenIndex->AddSequential(new cWait(WAIT_TIME));
	waitThenIndex->AddSequential(new cRunFuelConveyor());
	commands->AddParallel(waitThenIndex);

	commands->AddParallel(shooting);
	commands->AddParallel(driving);

    return commands;
}
*/
