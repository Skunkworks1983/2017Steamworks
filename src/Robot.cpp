#include "WPILib.h"
#include "Commands/Command.h"
#include "CommandBase.h"
#include "Subsystems/cDriveBase.h"
#include <OI.h>
#include "Commands/cRunTankDrive.h"

class Robot: public IterativeRobot
{
private:
	void RobotInit()
	{
		CommandBase::s_drivebase = new cDriveBase();
		CommandBase::s_oi = new OI();
		CommandBase::s_messenger = new cMessenger(RPI_IP, RPI_PORT);
	}

	void DisabledInit()
	{
	    if(CommandBase::s_messenger->m_isPostMatch) {
	        CommandBase::s_messenger->SendMessage(*(new cMessage("disabled")));
	        CommandBase::s_messenger->SendMessage(*(new cMessage("shutdown")));
	    }
	}

	void DisabledPeriodic()
	{
	}

	void AutonomousInit()
	{
	    CommandBase::s_messenger->m_isPostMatch = true;
	}

	void AutonomousPeriodic()
	{
		Scheduler::GetInstance()->Run();
	}

	void TeleopInit()
	{
	    CommandBase::s_messenger->m_isPostMatch = true;
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

