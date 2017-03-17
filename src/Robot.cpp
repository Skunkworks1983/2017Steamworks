#include "WPILib.h"
#include "Commands/Command.h"
#include "CommandBase.h"
#include <errno.h>
#include "RobotMap.h"

#include <Commands/Autonomous/AutoBase.h>

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

#include <Commands/Autonomous/AutoBase.h>

#include <Commands/Autonomous/cSimpleDriveForward.h>
#include <Commands/DriveBase/cDriveUntilWall.h>
#include <Commands/DriveBase/cDriveStraight.h>
#include <Commands/DriveBase/cTurnAngle.h>
#include <Commands/Debugging/cRunOneMotor.h>
#include <Subsystems/cFuelIndexer.h>
#include <Subsystems/cFuelConveyor.h>
#include <Subsystems/Sensors/cColorSensor.h>

#include <DigitalInput.h>


class Robot: public IterativeRobot {

private:
	//Put commands out here for declaration
	cRunOneMotor* runMotor;

	cSetSetpointManually* runShooter;

	cRunTankDrive* tankDrive;
	cDriveStraight* driveStraight;

	void RobotInit() {
		LOG_INFO("RobotInit called");

		SmartDashboard::PutNumber("P", SHOOTER_P);
		SmartDashboard::PutNumber("I", SHOOTER_I);
		SmartDashboard::PutNumber("D", SHOOTER_D);
		SmartDashboard::PutNumber("F", SHOOTER_F);
		SmartDashboard::PutNumber("TestShootSpeed", -80);

		CommandBase::s_drivebase = new cDriveBase();
		CommandBase::s_climber = new cClimber();
		CommandBase::s_turret = new cTurret();
		CommandBase::s_gearCollector = new cGearCollector();
		CommandBase::s_fuelCollector = new cFuelCollector();
		//CommandBase::s_fuelLoader = new cFuelLoader();
		CommandBase::s_fuelIndexer = new cFuelIndexer();
		CommandBase::s_fuelConveyor = new cFuelConveyor();
		CommandBase::s_shooter = new cShooter();


		CommandBase::s_oi = new OI();

		CommandBase::s_boilerMessenger = new cMessenger(BOILER_PI_IP,
				BOILER_PI_PORT);
		CommandBase::s_liftMessenger = new cMessenger(GEAR_PI_IP, GEAR_PI_PORT);


        runShooter = new cSetSetpointManually();
		CommandBase::s_drivebase->getGyro()->initGyro();
		CommandBase::s_drivebase->getGyro()->zeroYaw();


		//colorSensor = new cColorSensor();

		//Put construction of commands here
		std::cout << "Before" << std::endl;
		//driveStraight = new cDriveStraight(6);
		std::cout << "After" << std::endl;


		tankDrive = new cRunTankDrive();
		runMotor = new cRunOneMotor();

		//CameraServer::GetInstance()->StartAutomaticCapture();

        // enable turret
        CommandBase::s_turret->setEnabled(true);
        /*AutoBase* auto_base = new AutoBase();
        Scheduler::GetInstance()->AddCommand(auto_base->configureAutonomous());*/

		CommandBase::m_postMatch = false;

		AutoBase::m_d1 = new DigitalInput(POS_SELECTION_PORT1);
		AutoBase::m_d2 = new DigitalInput(POS_SELECTION_PORT2);
	}

	void DisabledInit() {
		Scheduler::GetInstance()->RemoveAll();
		LOG_INFO("DisabledInit called");

		// disable the turret
		CommandBase::s_turret->setEnabled(false);
		CommandBase::s_drivebase->setBrakeMode(false);
	}

	void DisabledPeriodic() {
		// spam with packets
		if (CommandBase::m_postMatch) {
			CommandBase::s_boilerMessenger->sendMessage("shutdown");
			CommandBase::s_liftMessenger->sendMessage("shutdown");
		}
	}

	void AutonomousInit() {
		Scheduler::GetInstance()->RemoveAll();
		Scheduler::GetInstance()->AddCommand(AutoBase::configureAutonomous());

		//Scheduler::GetInstance()->AddCommand(new cTurnAngle(90));
		LOG_INFO("AutonomousInit called");
	}

	void AutonomousPeriodic() {
		Scheduler::GetInstance()->Run();

		CommandBase::s_boilerMessenger->sendMessage("auto");
		CommandBase::s_liftMessenger->sendMessage("auto");
	}

	void TeleopInit() {
		Scheduler::GetInstance()->RemoveAll();
		Scheduler::GetInstance()->AddCommand(tankDrive);
		//Scheduler::GetInstance()->AddCommand(runMotor);
		LOG_INFO("TeleopInit called");
		std::cout << "Init" << std::endl;

		// enable turret
		CommandBase::s_turret->setEnabled(true);

		CommandBase::m_postMatch = true;
	}

	void TeleopPeriodic() {
		Scheduler::GetInstance()->Run();

		CommandBase::s_boilerMessenger->sendMessage("tele");
		CommandBase::s_liftMessenger->sendMessage("tele");

		std::cout << "Position: " << AutoBase::getStartingPosition() << "\tGet Alliance: " << AutoBase::getAlliance() << std::endl;
	}

	void TestPeriodic() {
		/* NOTE
		 * Running the robot in Test mode will also allow access in SmartDashboard to all of the CANTalons.
		 * We may want to move this to another portion and have a debug switch in RobotMap.h
		 */
		LiveWindow::GetInstance()->Run();
		SmartDashboard::PutNumber("Left sonar distance",
				CommandBase::s_drivebase->GetLeftDistance());
		SmartDashboard::PutNumber("Right sonar distance",
				CommandBase::s_drivebase->GetRightDistance());

		/*dashboard->PutNumber("Color sensor R value", CommandBase::s_drivebase->GetRValue());
		 dashboard->PutNumber("Color sensor G value", CommandBase::s_drivebase->GetGValue());
		 dashboard->PutNumber("Color sensor B value", CommandBase::s_drivebase->GetBValue());
		 dashboard->PutNumber("Color sensor C value", CommandBase::s_drivebase->GetCValue());*/

		SmartDashboard::PutNumber("Camera: Gear tape x pos",
				CommandBase::s_liftMessenger->receiveLiftData()->getX());

		SmartDashboard::PutNumber("Drivebase: left encoder",
				CommandBase::s_drivebase->getMotorGroupLeft()->getPosition());
		SmartDashboard::PutNumber("Drivebase: right encoder",
				CommandBase::s_drivebase->getMotorGroupRight()->getPosition());

		SmartDashboard::PutNumber("Shooter: encoder",
				CommandBase::s_shooter->getShooterMotor()->getPosition());
		//SmartDashboard::PutNumber("Collector: encoder", CommandBase::s_fuelCollector->getCollectorMotor()->getPosition());
		SmartDashboard::PutNumber("Turret: encoder",
				CommandBase::s_turret->getTurretMotor()->getPosition());
	}

};

START_ROBOT_CLASS(Robot)
