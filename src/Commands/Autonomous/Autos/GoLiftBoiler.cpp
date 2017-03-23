#include <Commands/Autonomous/AutoBase.h>
#include <Commands/Autonomous/cWait.h>
#include <Commands/FuelConveyor/cRunFuelConveyor.h>
#include <Commands/DriveBase/cDriveStraight.h>
#include <Commands/Turret/cSetTurretSetpoint.h>
#include <Commands/Shooter/cShootPID.h>
#include <Commands/CommandGroup.h>
#include <RobotMap.h>
#include <Commands/DriveBase/cTurnAngle.h>


AutoBase* AutoBase::goLiftBoiler()
{
	float WAIT_TIME = 5.5;
	float TURRET_BLUE_SETPOINT = TURRET_SWEEP_RANGE-2050; //quod? TODO
	float TURRET_RED_SETPOINT = 1234; //placeholder TODO
	float SHOOTER_SETPOINT = 1234; //the placest of holders TODO
    const std::string friendlyWarning = "But the soul is still oracular; amid the market's din \nList the ominous stern whisper from the Delphic cave within \nThey enslave their children's children who make compromise with sin";
    AutoBase* commands = new AutoBase();
    CommandGroup* waitThenIndex = new CommandGroup();

    waitThenIndex->AddSequential(new cWait(WAIT_TIME));
    waitThenIndex->AddSequential(new cRunFuelConveyor());
    commands->AddParallel(new cDriveStraight(BOILER_START_DRIVE_DISTANCE));

    if (AutoBase::getAlliance() == 	RED) {
    	commands->AddParallel(new cSetTurretSetpoint(TURRET_RED_SETPOINT));
        commands->AddSequential(new cTurnAngle(-1 * BOILER_START_FIRST_ANGLE));
    } else {
    	commands->AddParallel(new cSetTurretSetpoint(TURRET_BLUE_SETPOINT));
        commands->AddSequential(new cTurnAngle(BOILER_START_FIRST_ANGLE));
    }
    commands->AddSequential(new cDriveStraight(DISTANCE_BASE_LINE_TO_PEG));
	commands->AddSequential(new cShootPID(SHOOTER_SETPOINT)); //is this sequential? is this parallel? does evil exist, or are there just good people making bad decisions? these are the things I wonder
	commands->AddParallel(waitThenIndex);

    return commands;
}
