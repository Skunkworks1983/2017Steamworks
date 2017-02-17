#include "WPILib.h"
#include "Commands/Command.h"
#include "CommandBase.h"
#include "Subsystems/cDriveBase.h"
#include "Subsystems/cClimber.h"
#include <OI.h>
#include "Commands/DriveBase/cRunTankDrive.h"
#include "Commands/Turret/cPointToBoiler.h"
#include "Commands/DriveBase/cDriveStraight.h"
#include <errno.h>
#include "RobotMap.h"

class Robot: public IterativeRobot
{
private:

	//Put commands out here for declaration
	cDriveStraight* driveStraight;

    void RobotInit()
    {
        LOG_INFO("RobotInit called");

        //CommandBase::s_drivebase = new cDriveBase();
        //CommandBase::s_oi = new OI();
        //CommandBase::s_climber = new cClimber();
        CommandBase::s_turret = new cTurret();
        //CommandBase::s_gearCollector = new cGearCollector();
        //CommandBase::s_fuelCollector = new cFuelCollector();
        //CommandBase::s_fuelLoader = new cFuelLoader();
        CommandBase::s_shooter = new cShooter();

        CommandBase::s_boilerMessenger = new cMessenger(BOILER_PI_IP, BOILER_PI_PORT);
        CommandBase::s_liftMessenger = new cMessenger(GEAR_PI_IP, GEAR_PI_PORT);

        CommandBase::s_drivebase->getGyro()->initGyro();
        CommandBase::s_drivebase->getGyro()->zeroYaw();

        //Put construction of commands here
        driveStraight = new cDriveStraight(6);

        CameraServer::GetInstance()->StartAutomaticCapture();
    }

    void DisabledInit()
    {
    	Scheduler::GetInstance()->RemoveAll();
        LOG_INFO("DisabledInit called");
    }

    void DisabledPeriodic()
    {

    }

	void AutonomousInit()
	{
		CommandBase::s_drivebase->setBrakeMode(false);
	    Scheduler::GetInstance()->AddCommand(driveStraight);
        LOG_INFO("AutonomousInit called");
	}

    void AutonomousPeriodic()
    {
        Scheduler::GetInstance()->Run();
    }

    void TeleopInit()
    {
        LOG_INFO("TeleopInit called");
        Scheduler::GetInstance()->AddCommand(new cRunTankDrive());
    }

    void TeleopPeriodic()
    {
        Scheduler::GetInstance()->Run();
    }

    void TestPeriodic()
    {
        LiveWindow::GetInstance()->Run();
    }
};

START_ROBOT_CLASS(Robot)
//if you comment this macro out
//you should probably change that
//when you build
//i mean i'm not an expert
//but its some pretty solid advice
