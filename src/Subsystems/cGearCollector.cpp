#include "cGearCollector.h"
#include <RobotMap.h>
#include <Subsystems/Utilities/cServo.h>
#include <Commands/GearMechanism/cAcquireGear.h>
#include <Commands/Autonomous/AutoBase.h>

cGearCollector::cGearCollector()
{
    m_servo1 = new cServo(GEARCOLLECTOR_SERVO1_PORT);
    m_servo2 = new cServo(GEARCOLLECTOR_SERVO2_PORT);
}

cGearCollector::~cGearCollector()
{
	delete m_gearButton;
	delete m_servo1;
	delete m_servo2;
}

void cGearCollector::InitDefaultCommand()
{

}

// 7:1 gear rotation

void cGearCollector::setFlapState(bool open)
{
    // open flap
    if(open)
    {
        setServoAngle(GEARCOLLECTOR_OPEN_ANGLE);
    }
    // close flap
    else
    {
        setServoAngle(GEARCOLLECTOR_CLOSE_ANGLE);
    }
}

void cGearCollector::setServoAngle(float angle)
{
    m_servo1->setAngle(angle);
    m_servo2->setAngle(GEARCOLLECTOR_SERVO_MAX - angle);
}

bool cGearCollector::isGearIn()
{
	return AutoBase::m_button->Get();
}
