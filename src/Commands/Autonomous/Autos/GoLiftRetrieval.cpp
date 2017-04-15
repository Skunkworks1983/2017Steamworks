#include "../AutoBase.h"
#include <RobotMap.h>
#include <Commands/Autonomous/cSimpleDriveForward.h>
#include <Commands/DriveBase/cTurnAngle.h>
#include <Commands/DriveBase/cDriveStraight.h>
#include <Commands/Autonomous/cConditionalWiggle.h>
#include <Commands/Autonomous/cWait.h>

AutoBase* AutoBase::goLiftRetrieval() {
    float backupFromLiftDistance = -50;
    float backupFromLiftSpeed = -0.35;
    float backupFromLiftTimeout = 5;

    // FUUUUUUUUUUUUdge
    float WIGGLE_SWEEP_ANGLE = 60; // the total angle we turn, far left to far right
    float WIGGLE_TURN_TIMEOUT = 1;

    float WIGGLE_BACKUP_DISTANCE = 1000;
    float WIGGLE_BACKUP_SPEED = .35;
    float WIGGLE_BACKUP_TIMEOUT = 1.5;

    float mult = AutoBase::getAlliance() == eAlliance::RED ? 1 : -1;

    // make commands: keep command groups in order! read bottom down
    AutoBase* commands = new AutoBase();

    CommandGroup* driveToLift = new CommandGroup();
    CommandGroup* wiggle = new CommandGroup();


    driveToLift->AddSequential(new cDriveStraight(6100, .5, 5)); // drive to lift
    driveToLift->AddSequential(new cTurnAngle(60 * mult, 3));
    driveToLift->AddSequential(new cDriveStraight(4000, 0.35, 2)); // drive to lift
    //driveToLift->AddParallel(new cShootPID(0)); // cShootPID broken
    driveToLift->AddSequential(new cDriveStraight(backupFromLiftDistance, backupFromLiftSpeed, backupFromLiftTimeout)); // back up to relieve spring pressure

    // HOLLLYYY shirt TTHIS IS UALGY AS fudge AND TRIGGERING
    // AS heck PELASE FIX AFTER SEASON OR SOMETHIGN juan FSCHIREST
    wiggle->AddSequential(new cWait(2));

    wiggle->AddSequential(new cConditionalWiggle()); // ugly

    wiggle->AddSequential(new cDriveStraight(-WIGGLE_BACKUP_DISTANCE, -WIGGLE_BACKUP_SPEED, WIGGLE_BACKUP_TIMEOUT, true, true)); // don't even get me started here
    wiggle->AddSequential(new cTurnAngle(-WIGGLE_SWEEP_ANGLE / 2, WIGGLE_TURN_TIMEOUT, true));
    wiggle->AddSequential(new cTurnAngle(WIGGLE_SWEEP_ANGLE, WIGGLE_TURN_TIMEOUT, true));
    wiggle->AddSequential(new cTurnAngle(-WIGGLE_SWEEP_ANGLE / 2, WIGGLE_TURN_TIMEOUT, true));
    wiggle->AddSequential(new cDriveStraight(WIGGLE_BACKUP_DISTANCE * 2, WIGGLE_BACKUP_SPEED, WIGGLE_BACKUP_TIMEOUT, true, true));


    // add commands and return base
    commands->AddSequential(driveToLift);
    commands->AddParallel(wiggle);

    return commands;
}
