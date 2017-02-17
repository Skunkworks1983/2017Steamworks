/*
 * cDriveBase.cpp
 *
 *  Created on: Jan 16, 2017
 *      Author: paella
 */

#include <RobotMap.h>
#include "cMotor.h"
#include <Subsystems/cDriveBase.h>
#include "Commands/DriveBase/cRunTankDrive.h"
#include "Subsystems/cMotorGroup.h"
#include "Subsystems/cReversingMotorGroup.h"
#include <PIDController.h>

cDriveBase::cDriveBase()
{
    m_leftMotor1 = new cMotor(DRIVEBASE_LEFTMOTOR_1_PORT, CIM);
    m_leftMotor2 = new cMotor(DRIVEBASE_LEFTMOTOR_2_PORT, CIM, true);
    m_leftMotor3 = new cMotor(DRIVEBASE_LEFTMOTOR_3_PORT, CIM);

    m_rightMotor1 = new cMotor(DRIVEBASE_RIGHTMOTOR_1_PORT, CIM, true);
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

    std::vector<bool> reversed;
    reversed.push_back(false);
    reversed.push_back(true);

    m_motorGroupGyro = new cReversingMotorGroup(reversed, allMotors);
    m_motorGroupAll = new cMotorGroup(allMotors);

    m_gyro = new cGyro();

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
    //SetDefaultCommand(new cRunTankDrive());
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

cReversingMotorGroup* cDriveBase::getMotorGroupGyro()
{
    return m_motorGroupGyro;
}

iGyro* cDriveBase::getGyro()
{
    return m_gyro;
}
bool cDriveBase::CanSeeTape()
{
    colorSensor = new I2C(I2C::kOnboard, COLOR_SENSOR_I2C_SLAVE_ADR);
    uint8_t bufferR[COLOR_SENSOR_BYTE_LENGTH];
    uint8_t bufferG[COLOR_SENSOR_BYTE_LENGTH];
    uint8_t bufferB[COLOR_SENSOR_BYTE_LENGTH];
    colorSensor->Read(COLOR_SENSOR_R_HIGH_REG, COLOR_SENSOR_BYTE_LENGTH, bufferR);
    colorSensor->Read(COLOR_SENSOR_G_HIGH_REG, COLOR_SENSOR_BYTE_LENGTH, bufferG);
    colorSensor->Read(COLOR_SENSOR_B_HIGH_REG, COLOR_SENSOR_BYTE_LENGTH, bufferB);
    if(BitShift(bufferR) == FLOOR_TAPE_R)
    {
        if(BitShift(bufferG) == FLOOR_TAPE_G)
        {
            if(BitShift(bufferB) == FLOOR_TAPE_B)
            {
                return true;
            }
        }
    }
    return false;
}
int cDriveBase::BitShift(uint8_t *colorReadout)
{
    int shiftee = colorReadout[0] << 8;
    shiftee = shiftee | colorReadout[1];
    return shiftee;

}
