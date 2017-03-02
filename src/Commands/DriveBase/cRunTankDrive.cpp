#include <Commands/DriveBase/cRunTankDrive.h>
#include <Subsystems/cDriveBase.h>
#include <OI.h>
#include <CommandBase.h>
#include <RobotMap.h>
cRunTankDrive::cRunTankDrive()
{
    Requires(s_drivebase);
}

void cRunTankDrive::Initialize()
{
    LOG_INFO("starting cRunTankDrive");
    CommandBase::s_drivebase->setEnabled(true);
}

void cRunTankDrive::Execute()
{
    float leftSpeed;
    float rightSpeed;
    if(CommandBase::s_drivebase->getIsReversed() == false)
    {
        leftSpeed = CommandBase::s_oi->getLeftStickY();
        rightSpeed = CommandBase::s_oi->getRightStickY();
    }
    else
    {
        leftSpeed = CommandBase::s_oi->getRightStickY() * -1;
        rightSpeed = CommandBase::s_oi->getLeftStickY() * -1;
        //reverses robot -> switches joystick control and robot front/back
    }

    if(leftSpeed < .05 && leftSpeed > -.05) //creates deadzone
    {
        CommandBase::s_drivebase->setLeftSpeed(0);
    }
    else if(leftSpeed < 0)
    {
        CommandBase::s_drivebase->setLeftSpeed((leftSpeed * leftSpeed) * -1); //scalling
    }
    else
    {
        CommandBase::s_drivebase->setLeftSpeed(leftSpeed * leftSpeed);
    }

    if(rightSpeed < .05 && rightSpeed > -.05)
    {
        CommandBase::s_drivebase->setRightSpeed(0);
    }
    else if(rightSpeed < 0)
    {
        CommandBase::s_drivebase->setRightSpeed((rightSpeed * rightSpeed) * -1);
    }
    else
    {
        CommandBase::s_drivebase->setRightSpeed(rightSpeed * rightSpeed);
    }
    //std::cout << "Left: " << CommandBase::s_drivebase->getMotorGroupLeft()->getPosition() << "\t\tRight: " << CommandBase::s_drivebase->getMotorGroupRight()->getPosition() << std::endl;
}

bool cRunTankDrive::IsFinished()
{
    return false;
}

void cRunTankDrive::End()
{
    LOG_INFO("ending cRunTankDrive");
}

void cRunTankDrive::Interrupted()
{
    LOG_INFO("interrupted cRunTankDrive");
    End();
}

