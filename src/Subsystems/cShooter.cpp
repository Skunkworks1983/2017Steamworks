#include "cShooter.h"
#include <RobotMap.h>

cShooter::cShooter() : Subsystem("cShooter")
{
    motor1 = new cMotor(SHOOTER_MOTOR1_PORT);
    motor2 = new cMotor(SHOOTER_MOTOR2_PORT);
}

cShooter::~cShooter()
{
    delete motor1;
    delete motor2;
}

void cShooter::InitDefaultCommand() {

}

void cShooter::setSpeed(float speed)
{
    motor1->setOutput(speed);
    motor2->setOutput(speed);
}
