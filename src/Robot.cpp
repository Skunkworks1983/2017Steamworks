#include "WPILib.h"
#include "Commands/Command.h"
#include "CommandBase.h"
#include "Subsystems/cDriveBase.h"
#include <OI.h>
#include "Commands/cRunTankDrive.h"

bool postMatch = false;

class Robot: public IterativeRobot
{
private:
    std::unique_ptr<Command> autonomousCommand;

	void RobotInit()
	{
		CommandBase::s_drivebase = new cDriveBase();
		CommandBase::s_oi = new OI();
		CommandBase::s_messenger = new cMessenger(RPI_IP, RPI_PORT);
	}

    /**
     * This function is called once each time the robot enters Disabled mode.
     * You can use it to reset any subsystem information you want to clear when
     * the robot is disabled.
     */

	void DisabledInit()
	{
	    if(postMatch) {
	        CommandBase::s_messenger->SendMessage("disabled");
	        CommandBase::s_messenger->SendMessage("shutdown");
	    }
	}

	void DisabledPeriodic()
	{
	}

	/**
	 * This autonomous (along with the chooser code above) shows how to select between different autonomous modes
	 * using the dashboard. The sendable chooser code works with the Java SmartDashboard. If you prefer the LabVIEW
	 * Dashboard, remove all of the chooser code and uncomment the GetString code to get the auto name from the text box
	 * below the Gyro
	 *
	 * You can add additional auto modes by adding additional commands to the chooser code above (like the commented example)
	 * or additional comparisons to the if-else structure below with additional strings & commands.
	 */
	void AutonomousInit()
	{
	    postMatch = true;
	}

	void AutonomousPeriodic()
	{
		Scheduler::GetInstance()->Run();
	}

	void TeleopInit()
	{
	    postMatch = true;
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

