#include "WPILib.h"
#include "Commands/Command.h"
#include "CommandBase.h"
#include "Subsystems/cDriveBase.h"
#include <OI.h>
#include "Commands/cRunTankDrive.h"
#include <errno.h>

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
        cMessage* msg1 = new cMessage("disabled");

        if(CommandBase::s_messenger->m_isPostMatch) {
            CommandBase::s_messenger->SendMessage(msg1);
        }

        std::cout << CommandBase::s_messenger->ReceiveMessage()->getmessage() << "\n";

        delete msg1;
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

