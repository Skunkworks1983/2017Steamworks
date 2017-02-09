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
        CommandBase::s_messenger->m_isPostMatch = true;

        cMessage* msg1 = new cMessage("disabled");
        CommandBase::s_messenger->SendMessage(msg1);

        if(CommandBase::s_messenger->m_isPostMatch)
        {
            CommandBase::s_messenger->SendMessage(msg1);
        }

        delete msg1;
    }

    void TeleopPeriodic()
    {
        Scheduler::GetInstance()->Run();

        std::string msg = CommandBase::s_messenger->ReceiveMessage()->GetMessage();

        if(msg[0] != 0)
        {
            std::cout << msg << "\n";
        }
    }

    void TestPeriodic()
    {
        LiveWindow::GetInstance()->Run();
    }
};

START_ROBOT_CLASS(Robot)

