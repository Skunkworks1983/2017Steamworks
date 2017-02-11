#include "WPILib.h"
#include "Commands/Command.h"
#include "CommandBase.h"
#include "Subsystems/cDriveBase.h"
#include "Subsystems/cClimber.h"
#include <OI.h>
#include "Commands/cRunTankDrive.h"
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
        LOG_INFO("AutonomousInit called");
        CommandBase::s_messenger->m_isPostMatch = true;
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

