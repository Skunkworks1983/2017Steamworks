#include "cTurret.h"
#include <Subsystems/Utilities/cMotor.h>
#include <RobotMap.h>
#include <Commands/Turret/cRotateTurret.h>

cTurret::cTurret()
{
    //m_motor1 = new cMotor(TURRET_MOTOR1_PORT, NeveRest40);
    m_servoYaw = new Servo(8);
    m_servoPitch = new Servo(9);

    m_servoYaw->SetAngle(85);
    m_servoPitch->SetAngle(85);
}

cTurret::~cTurret()
{
    m_servoYaw->SetAngle(85);
    m_servoPitch->SetAngle(85);

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
