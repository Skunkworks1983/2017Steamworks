#include <Commands/DriveBase/cRunTankDrive.h>
#include <Subsystems/cDriveBase.h>
#include <OI.h>
#include <CommandBase.h>
cRunTankDrive::cRunTankDrive()
{
    Requires(s_drivebase);
}

void cRunTankDrive::Initialize()
{
    CommandBase::s_drivebase->setEnabled(true);
}

void cRunTankDrive::Execute()
{
    float leftSpeed;
    float rightSpeed;

    leftSpeed = CommandBase::s_oi->getLeftStickY();
    rightSpeed = CommandBase::s_oi->getRightStickY();

    if(leftSpeed < .05 && leftSpeed > -.05)
    {
        CommandBase::s_drivebase->setLeftSpeed(0);
    }
    else if(leftSpeed < 0)
    {
        CommandBase::s_drivebase->setLeftSpeed((leftSpeed * leftSpeed) * -1);
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
}

bool cRunTankDrive::IsFinished()
{
    return false;
}

void cRunTankDrive::End()
{

}

void cRunTankDrive::Interrupted()
{
    End();
}

