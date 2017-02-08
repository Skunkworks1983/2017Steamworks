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
#include "Subsystems/cMotorGroup.h"
cDriveBase::cDriveBase() :
        Subsystem("cDriveBase")
{
    m_leftMotor1 = new cMotor(DRIVEBASE_LEFTMOTOR_1_PORT, CIM);
    m_leftMotor2 = new cMotor(DRIVEBASE_LEFTMOTOR_2_PORT, CIM);
    m_leftMotor3 = new cMotor(DRIVEBASE_LEFTMOTOR_3_PORT, CIM);

    m_rightMotor1 = new cMotor(DRIVEBASE_RIGHTMOTOR_1_PORT, CIM);
    m_rightMotor2 = new cMotor(DRIVEBASE_RIGHTMOTOR_2_PORT, CIM);
    m_rightMotor3 = new cMotor(DRIVEBASE_RIGHTMOTOR_3_PORT, CIM);

    std::vector<iMotor*> leftMotors;
    leftMotors.push_back(m_leftMotor1);
    leftMotors.push_back(m_leftMotor2);
    leftMotors.push_back(m_leftMotor3);

    std::vector<iMotor*> rightMotors;
    rightMotors.push_back(m_rightMotor1);
    rightMotors.push_back(m_rightMotor2);
    rightMotors.push_back(m_rightMotor3);

    m_motorGroupLeft = new cMotorGroup(leftMotors);
    m_motorGroupRight = new cMotorGroup(rightMotors);

    std::vector<iMotor*> allMotors;
    allMotors.push_back(m_motorGroupLeft);
    allMotors.push_back(m_motorGroupRight);

    m_motorGroupAll = new cMotorGroup(allMotors);
}
cDriveBase::~cDriveBase()
{
    // TODO Auto-generated destructor stub
    delete m_motorGroupLeft;
    delete m_motorGroupRight;
}
void cDriveBase::setBrakeMode(bool brake)
{
    m_motorGroupAll->setBrakeMode(brake);
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
    m_motorGroupLeft->setOutput(speed);
}
void cDriveBase::setRightSpeed(double speed)
{
    speed = speed * DRIVEBASE_RIGHT_DIRECTION;
    m_motorGroupRight->setOutput(speed);
}

void cDriveBase::setEnabled(bool enabled)
{
    m_motorGroupAll->setEnabled(enabled);
}

cMotorGroup* cDriveBase::getMotorGroupRight()
{
    return m_motorGroupRight;
}
cMotorGroup* cDriveBase::getMotorGroupLeft()
{
    return m_motorGroupLeft;
}
cMotorGroup* cDriveBase::getMotorGroupAll()
{
    return m_motorGroupAll;
}
