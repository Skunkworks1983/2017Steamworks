#include "WPILib.h"
#include "Commands/Command.h"
#include "CommandBase.h"
#include "Subsystems/cDriveBase.h"
#include "Subsystems/cClimber.h"
#include <OI.h>
#include "Commands/DriveBase/cRunTankDrive.h"
#include "Commands/Turret/cPointToBoiler.h"
#include <errno.h>
#include "RobotMap.h"

class Robot: public IterativeRobot
{
private:
    void RobotInit()
    {
        LOG_INFO("RobotInit called");

        CommandBase::s_drivebase = new cDriveBase();
        CommandBase::s_oi = new OI();
        CommandBase::s_climber = new cClimber();
        CommandBase::s_messenger = new cMessenger(RPI_IP, RPI_PORT);
    }

    void DisabledInit()
    {
        LOG_INFO("DisabledInit called");
    }

    void DisabledPeriodic()
    {

    }

	void AutonomousInit()
	{
		std::cout << "whoa whoa whoa 0" << std::endl;
	    CommandBase::s_messenger->m_isPostMatch = true;
	    cPointToBoiler* pointing = new cPointToBoiler();
	    std::cout << "whoa man got here" << std::endl;
	    Scheduler::GetInstance()->AddCommand(pointing);
        LOG_INFO("AutonomousInit called");
	}

    void AutonomousPeriodic()
    {
        Scheduler::GetInstance()->Run();
    }

    void TeleopInit()
    {
        LOG_INFO("TeleopInit called");
    }

    void TeleopPeriodic()
    {
        Scheduler::GetInstance()->Run();

        cLiftData* dat = CommandBase::s_messenger->receiveLiftData();

        if(dat->getX() != -1)
            std::cout << dat->getX() << std::endl;
    }

    void TestPeriodic()
    {
        LiveWindow::GetInstance()->Run();
    }
};

START_ROBOT_CLASS(Robot)

