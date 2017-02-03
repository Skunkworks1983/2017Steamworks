#include "cTurret.h"
#include <RobotMap.h>

cTurret::cTurret() : Subsystem("cTurret")
{
    motor1 = new cMotor(TURRET_MOTOR1_PORT);
}

cTurret::~cTurret()
{
    delete motor1;
}

void cTurret::InitDefaultCommand() {

}

void cTurret::setSpeed(float speed)
{
    motor1->setOutput(speed);
}


void cTurret::setOrientation(float heading) {

}


void cTurret::rotate(float degrees) {

}
