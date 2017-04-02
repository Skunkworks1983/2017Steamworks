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
