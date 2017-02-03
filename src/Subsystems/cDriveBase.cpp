/*
 * cDriveBase.cpp
 *
 *  Created on: Jan 16, 2017
 *      Author: paella
 */

#include <RobotMap.h>
#include "cMotor.h"
#include <Subsystems/cDriveBase.h>
#include "Commands/cRunTankDrive.h"
cDriveBase::cDriveBase() :
        Subsystem("cDriveBase")
{
    m_leftMotor1 = new cMotor(DRIVEBASE_LEFTMOTOR_1_PORT);
    m_leftMotor2 = new cMotor(DRIVEBASE_LEFTMOTOR_2_PORT);
    m_leftMotor3 = new cMotor(DRIVEBASE_LEFTMOTOR_3_PORT);

    m_rightMotor1 = new cMotor(DRIVEBASE_RIGHTMOTOR_1_PORT);
    m_rightMotor2 = new cMotor(DRIVEBASE_RIGHTMOTOR_2_PORT);
    m_rightMotor3 = new cMotor(DRIVEBASE_RIGHTMOTOR_3_PORT);
}
cDriveBase::~cDriveBase()
{
    // TODO Auto-generated destructor stub
    delete m_leftMotor1;
    delete m_leftMotor2;
    delete m_leftMotor3;
    delete m_rightMotor1;
    delete m_rightMotor2;
    delete m_rightMotor3;
}
void cDriveBase::setBrakeMode(bool brake)
{
    m_leftMotor1->setBrakeMode(brake);
    m_leftMotor2->setBrakeMode(brake);
    m_leftMotor3->setBrakeMode(brake);
    m_rightMotor1->setBrakeMode(brake);
    m_rightMotor2->setBrakeMode(brake);
    m_rightMotor3->setBrakeMode(brake);
}
void cDriveBase::InitDefaultCommand()
{
    SetDefaultCommand(new cRunTankDrive());
}
void cDriveBase::resetEncoder()
{
}
void cDriveBase::setLeftSpeed(double speed)
{
    speed = speed * DRIVEBASE_LEFT_DIRECTION;
    m_leftMotor1->setOutput(speed);
    m_leftMotor2->setOutput(speed);
    m_leftMotor3->setOutput(speed);
}
void cDriveBase::setRightSpeed(double speed)
{
    speed = speed * DRIVEBASE_RIGHT_DIRECTION;
    m_rightMotor1->setOutput(speed);
    m_rightMotor2->setOutput(speed);
    m_rightMotor3->setOutput(speed);
}

void cDriveBase::setEnabled(bool enabled)
{
    m_leftMotor1->setEnabled(enabled);
    m_leftMotor2->setEnabled(enabled);
    m_leftMotor3->setEnabled(enabled);
    m_rightMotor1->setEnabled(enabled);
    m_rightMotor2->setEnabled(enabled);
    m_rightMotor3->setEnabled(enabled);
}

