#include "cTurret.h"
#include <Subsystems/Utilities/cMotor.h>
#include <RobotMap.h>
#include <Commands/Turret/cRotateTurret.h>
#include <WPILib.h>

cTurret::cTurret()
{
    m_motor1 = new cMotor(TURRET_MOTOR1_PORT, NeveRest40);
}

cTurret::~cTurret()
{
    delete m_motor1;
}

void cTurret::InitDefaultCommand()
{
    SetDefaultCommand(new cRotateTurret());
}

void cTurret::setSpeed(float speed)
{
    m_motor1->setOutput(speed);
}

void cTurret::setOrientation(float heading)
{
    double desired = (heading / 360);
    desired *= (TURRET_GEAR1_TEETH / TURRET_GEAR2_TEETH);
}

void cTurret::rotate(float degrees)
{

}

void cTurret::setManualEnabled(bool state)
{
    m_manualEnabled = state;
}

bool cTurret::isManualEnabled()
{
    return m_manualEnabled;
}
