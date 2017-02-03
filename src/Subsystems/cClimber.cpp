#include "cClimber.h"
#include <RobotMap.h>

cClimber::cClimber() : Subsystem("cClimber")
{
    motor1 = new cMotor(CLIMBER_MOTOR1_PORT);
    motor2 = new cMotor(CLIMBER_MOTOR2_PORT);
}

cClimber::~cClimber()
{
    delete motor1;
    delete motor2;
}

void cClimber::InitDefaultCommand() {

}

void cClimber::setSpeed(float speed)
{
    motor1->setOutput(speed);
    motor2->setOutput(speed);
}
