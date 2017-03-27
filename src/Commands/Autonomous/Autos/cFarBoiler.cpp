#include <Commands/Autonomous/AutoBase.h>
#include <Commands/Autonomous/cWait.h>
#include <Commands/FuelConveyor/cRunFuelConveyor.h>
#include <Commands/DriveBase/cDriveStraight.h>
#include <Commands/Turret/cSetTurretSetpoint.h>
#include <Commands/Shooter/cShootPID.h>
#include <Commands/CommandGroup.h>
#include <RobotMap.h>

AutoBase* AutoBase::goFarBoiler() {
	//CONSTANTS
	float WAIT_TIME = 5.5;
	float AIRSHIP_TICK_DISTANCE = -7250*1.75;
	float AIRSHIP_TRAVEL_SPEED = 0.3;
	float TURRET_BLUE_SETPOINT = TURRET_SWEEP_RANGE+2050;
	float TURRET_RED_SETPOINT = -2050;
	float SHOOTER_SETPOINT = 9750;

	AutoBase* commands = new AutoBase();
	CommandGroup* waitThenIndex = new CommandGroup();

	waitThenIndex->AddSequential(new cWait(WAIT_TIME));
	waitThenIndex->AddSequential(new cRunFuelConveyor());

	commands->AddParallel(new cDriveStraight(AIRSHIP_TICK_DISTANCE, AIRSHIP_TRAVEL_SPEED));
	if(AutoBase::getAlliance() == BLUE) {
		commands->AddParallel(new cSetTurretSetpoint(TURRET_BLUE_SETPOINT));
	} else {
		commands->AddParallel(new cSetTurretSetpoint(TURRET_RED_SETPOINT));
	}
	commands->AddParallel(new cShootPID(SHOOTER_SETPOINT));
	commands->AddParallel(waitThenIndex);

	return commands;
}
