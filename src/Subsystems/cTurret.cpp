#include "cTurret.h"
#include <RobotMap.h>

cTurret::cTurret() :
        Subsystem("cTurret")
{
    m_motor1 = new cMotor(TURRET_MOTOR1_PORT);
}

cTurret::~cTurret()
{
    delete m_motor1;
}

void cTurret::InitDefaultCommand()
{

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
