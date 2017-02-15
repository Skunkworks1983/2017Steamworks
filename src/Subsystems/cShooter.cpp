#include "cShooter.h"
#include <RobotMap.h>

cShooter::cShooter() :
        Subsystem("cShooter")
{
    m_motor1 = new cMotor(SHOOTER_MOTOR1_PORT, BaneBots775);
    m_motor2 = new cMotor(SHOOTER_MOTOR2_PORT, BaneBots775);
}

cShooter::~cShooter()
{
    delete m_motor1;
    delete m_motor2;
}

void cShooter::InitDefaultCommand()
{

}

void cShooter::setSpeed(float speed)
{
    m_motor1->setOutput(speed);
    m_motor2->setOutput(speed);
}

double cShooter::getSpeed()
{
    return 0;
}

void cShooter::setManualEnabled(bool state)
{
    m_manualEnabled = state;
}

bool cShooter::isManualEnabled()
{
    return m_manualEnabled;
}

