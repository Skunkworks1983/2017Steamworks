/*
 * GoHopper.cpp
 *
 *  Created on: Mar 21, 2017
 *      Author: S-2505674
 */
#include <Commands/Autonomous/Autobase.h>
#include <Commands/DriveBase/cDriveStraight.h>
#include <Commands/Autonomous/cTurnDegree.h>
#include <Commands/Turret/cSetTurretSetpoint.h>
#include <Commands/FuelConveyor/cRunFuelConveyor.h>
#include <Commands/Autonomous/cWait.h>
#include <Commands/Shooter/cShootPID.h>
#include <Commands/CommandGroup.h>

AutoBase* AutoBase::goHopper()
{
	//Constants (all are placeholders if you couldn't tell)
	float HWAIT_TIME = 7;
	float HOPPER_TICK_DISTANCE = 7250*1.1;
	float HOPPER_TRAVEL_SPEED = 0.2;
	float HOPPER_TICK_DISTANCE_2 = 250;
	float HOPPER_BLUE_TURN_DEGREE = 90;
	float HOPPER_RED_TURN_DEGREE = -HOPPER_BLUE_TURN_DEGREE;
	float HTURRET_BLUE_SETPOINT = 1;
	float HTURRET_RED_SETPOINT = 0;
	float HSHOOTER_SETPOINT = 1234;

	AutoBase* commands = new AutoBase();
	CommandGroup* waitNIndex = new CommandGroup();

	waitNIndex->AddSequential(new cWait(HWAIT_TIME));
	waitNIndex->AddSequential(new cRunFuelConveyor());

	commands->AddSequential(new cDriveStraight(HOPPER_TICK_DISTANCE, HOPPER_TRAVEL_SPEED));

	if(AutoBase::getAlliance() == BLUE)
	{
		commands->AddSequential(new cTurnDegree(HOPPER_BLUE_TURN_DEGREE));
		commands->AddParallel(new cSetTurretSetpoint(HTURRET_BLUE_SETPOINT));
	} else{
		commands->AddSequential(new cTurnDegree(HOPPER_RED_TURN_DEGREE));
		commands->AddParallel(new cSetTurretSetpoint(HTURRET_RED_SETPOINT));
	}

	commands->AddSequential(new cDriveStraight(HOPPER_TICK_DISTANCE_2, HOPPER_TRAVEL_SPEED));
	commands->AddSequential(new cShootPID(HSHOOTER_SETPOINT));
	commands->AddParallel(waitNIndex);

	return commands;
}


