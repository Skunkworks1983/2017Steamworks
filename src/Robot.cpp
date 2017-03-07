#include "WPILib.h"
#include "Commands/Command.h"
#include "CommandBase.h"
#include <errno.h>
#include "RobotMap.h"

#include <SmartDashboard/SmartDashboard.h>

#include "Subsystems/cDriveBase.h"
#include "Subsystems/cClimber.h"
#include "Subsystems/cGearCollector.h"
#include "Subsystems/cFuelCollector.h"
#include "Subsystems/cShooter.h"
#include "Subsystems/cTurret.h"
#include <Services/cMessenger.h>

#include "Commands/GearMechanism/cAcquireGear.h"
#include "Commands/DriveBase/cRunTankDrive.h"
#include "Commands/Shooter/cSetSetpointManually.h"

#include <Commands/DriveBase/cDriveStraight.h>
#include <Commands/Debugging/cRunOneMotor.h>
#include <Subsystems/cFuelIndexer.h>
#include <Subsystems/cFuelConveyor.h>
#include <Subsystems/Sensors/cColorSensor.h>


class Robot: public IterativeRobot
{
private:

	//Put commands out here for declaration
	cDriveStraight* driveStraight;
	cRunOneMotor* runMotor;
	cColorSensor* colorSensor;
	SmartDashboard* dashboard;
	cSetSetpointManually* runShooter;

    void RobotInit()
    {
        LOG_INFO("RobotInit called");

        CommandBase::s_drivebase = new cDriveBase();
        CommandBase::s_climber = new cClimber();
        CommandBase::s_turret = new cTurret();
        CommandBase::s_gearCollector = new cGearCollector();
        CommandBase::s_fuelCollector = new cFuelCollector();
        CommandBase::s_fuelIndexer = new cFuelIndexer();
        CommandBase::s_fuelConveyor = new cFuelConveyor();
        CommandBase::s_shooter = new cShooter();
        CommandBase::s_oi = new OI();

        CommandBase::s_boilerMessenger = new cMessenger(BOILER_PI_IP, BOILER_PI_PORT);
        CommandBase::s_liftMessenger = new cMessenger(GEAR_PI_IP, GEAR_PI_PORT);
        dashboard = new SmartDashboard;
        runShooter = new cSetSetpointManually();
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
        Scheduler::GetInstance()->RemoveAll();
        LOG_INFO("AutonomousInit called");

        //Scheduler::GetInstance()->AddCommand(new cAcquireGear(0, 5));
	}

    void AutonomousPeriodic()
    {
        Scheduler::GetInstance()->Run();

        CommandBase::s_boilerMessenger->sendMessage("auto");
        CommandBase::s_liftMessenger->sendMessage("auto");
    }

    void TeleopInit()
    {
        Scheduler::GetInstance()->RemoveAll();
        LOG_INFO("TeleopInit called");
        Scheduler::GetInstance()->AddCommand(runShooter);

    }

    void TeleopPeriodic()
    {
        Scheduler::GetInstance()->Run();

        CommandBase::s_boilerMessenger->sendMessage("tele");
        CommandBase::s_liftMessenger->sendMessage("tele");

    }

    void TestPeriodic()
    {
        LiveWindow::GetInstance()->Run();
    	dashboard->PutNumber("Left sonar distance", CommandBase::s_drivebase->GetLeftDistance());
    	dashboard->PutNumber("Right sonar distance", CommandBase::s_drivebase->GetRightDistance());

    	dashboard->PutNumber("Color sensor R value", CommandBase::s_drivebase->GetRValue());
    	dashboard->PutNumber("Color sensor G value", CommandBase::s_drivebase->GetGValue());
    	dashboard->PutNumber("Color sensor B value", CommandBase::s_drivebase->GetBValue());
    	dashboard->PutNumber("Color sensor C value", CommandBase::s_drivebase->GetCValue());

    	dashboard->PutNumber("Camera: Gear tape x pos", CommandBase::s_liftMessenger->receiveLiftData()->getX());

    	dashboard->PutNumber("Drivebase: left encoder", CommandBase::s_drivebase->getMotorGroupLeft()->getPosition());
    	dashboard->PutNumber("Drivebase: right encoder", CommandBase::s_drivebase->getMotorGroupRight()->getPosition());

    	dashboard->PutNumber("Shooter: encoder", CommandBase::s_shooter->getShooterMotor()->getPosition());
    	dashboard->PutNumber("Collector: encoder", CommandBase::s_fuelCollector->getCollectorMotor()->getPosition());
    	dashboard->PutNumber("Turret: encoder", CommandBase::s_turret->getTurretMotor()->getPosition());
    }
};
START_ROBOT_CLASS(Robot)
//if you comment this macro out
//you should probably change that
//when you build
//i mean i'm not an expert
//but its some pretty solid advice

//as an expert, i agree with this not-quite-expert-but-still-pretty-good analysis
