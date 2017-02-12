#include "cTurret.h"
#include "cMotor.h"
#include <RobotMap.h>
#include <Commands/Turret/cRotateTurret.h>

cTurret::cTurret() :
        Subsystem("cTurret")
{
    //m_motor1 = new cMotor(TURRET_MOTOR1_PORT, NeveRest40);
    m_servo1 = new Servo(8);
}

cTurret::~cTurret()
{
    //delete m_motor1;
    delete m_servo1;
}

void cTurret::InitDefaultCommand()
{
    SetDefaultCommand(new cRotateTurret(0, 10));
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
