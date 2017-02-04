#include "cClimber.h"
#include <RobotMap.h>

cClimber::cClimber() :
        Subsystem("cClimber")
{
    m_motor1 = new cMotor(CLIMBER_MOTOR1_PORT);
    m_motor2 = new cMotor(CLIMBER_MOTOR2_PORT);
}

cClimber::~cClimber()
{
    delete m_motor1;
    delete m_motor2;
}

void cClimber::InitDefaultCommand()
{

}

void cClimber::setSpeed(float speed)
{
    m_motor1->setOutput(speed);
    m_motor2->setOutput(speed);
}