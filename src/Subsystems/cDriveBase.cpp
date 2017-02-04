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
    leftMotor1 = new cMotor(DRIVEBASE_LEFTMOTOR_1_PORT);
    leftMotor2 = new cMotor(DRIVEBASE_LEFTMOTOR_2_PORT);
    leftMotor3 = new cMotor(DRIVEBASE_LEFTMOTOR_3_PORT);

    rightMotor1 = new cMotor(DRIVEBASE_RIGHTMOTOR_1_PORT);
    rightMotor2 = new cMotor(DRIVEBASE_RIGHTMOTOR_2_PORT);
    rightMotor3 = new cMotor(DRIVEBASE_RIGHTMOTOR_3_PORT);

    std::vector<iMotor*> leftMotors;
    leftMotors.push_back(leftMotor1);
    leftMotors.push_back(leftMotor2);
    leftMotors.push_back(leftMotor3);

    std::vector<iMotor*> rightMotors;
    rightMotors.push_back(rightMotor1);
    rightMotors.push_back(rightMotor2);
    rightMotors.push_back(rightMotor3);

    motorGroupLeft = new cMotorGroup(leftMotors);
    motorGroupRight = new cMotorGroup(rightMotors);

    std::vector<iMotor*> allMotors;
    allMotors.push_back(motorGroupLeft);
    allMotors.push_back(motorGroupRight);

    motorGroupAll = new cMotorGroup(allMotors);
}
cDriveBase::~cDriveBase()
{
    // TODO Auto-generated destructor stub
    delete leftMotor1;
    delete leftMotor2;
    delete leftMotor3;
    delete rightMotor1;
    delete rightMotor2;
    delete rightMotor3;
}
void cDriveBase::setBrakeMode(bool brake)
{
    leftMotor1->setBrakeMode(brake);
    leftMotor2->setBrakeMode(brake);
    leftMotor3->setBrakeMode(brake);
    rightMotor1->setBrakeMode(brake);
    rightMotor2->setBrakeMode(brake);
    rightMotor3->setBrakeMode(brake);
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
    leftMotor1->setOutput(speed);
    leftMotor2->setOutput(speed);
    leftMotor3->setOutput(speed);
}
void cDriveBase::setRightSpeed(double speed)
{
    speed = speed * DRIVEBASE_RIGHT_DIRECTION;
    rightMotor1->setOutput(speed);
    rightMotor2->setOutput(speed);
    rightMotor3->setOutput(speed);
}

void cDriveBase::setEnabled(bool enabled)
{
    leftMotor1->setEnabled(enabled);
    leftMotor2->setEnabled(enabled);
    leftMotor3->setEnabled(enabled);
    rightMotor1->setEnabled(enabled);
    rightMotor2->setEnabled(enabled);
    rightMotor3->setEnabled(enabled);
}

cMotorGroup* cDriveBase::getMotorGroupRight()
{
    return motorGroupRight;
}
cMotorGroup* cDriveBase::getMotorGroupLeft()
{
    return motorGroupLeft;
}
cMotorGroup* cDriveBase::getMotorGroupAll()
{
    return motorGroupAll;
}
