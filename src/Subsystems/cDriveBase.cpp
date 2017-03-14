/*
 * cDriveBase.cpp
 *
 *  Created on: Jan 16, 2017
 *      Author: paella
 */


#include <RobotMap.h>
#include <Subsystems/Utilities/cMotor.h>
#include <Subsystems/cDriveBase.h>
#include "Commands/DriveBase/cRunTankDrive.h"
#include <Subsystems/Utilities/cMotorGroup.h>
#include <Subsystems/Utilities/cReversingMotorGroup.h>
#include <PIDController.h>
#include <Utility.h>

cDriveBase::cDriveBase()
{
    m_leftMotor1 = new cMotor(DRIVEBASE_LEFTMOTOR_1_PORT, CIM);
    m_leftMotor2 = new cMotor(DRIVEBASE_LEFTMOTOR_2_PORT, CIM, true);
    m_leftMotor3 = new cMotor(DRIVEBASE_LEFTMOTOR_3_PORT, CIM);

    m_rightMotor1 = new cMotor(DRIVEBASE_RIGHTMOTOR_1_PORT, CIM);
    m_rightMotor2 = new cMotor(DRIVEBASE_RIGHTMOTOR_2_PORT, CIM, true);
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

	m_colorSensor = new I2C(I2C::kOnboard, COLOR_SENSOR_I2C_SLAVE_ADR);

    m_motorGroupGyro = new cReversingMotorGroup(reversed, allMotors);
    m_motorGroupAll = new cMotorGroup(allMotors);


    m_gyro = new cGyro();

    m_IsReversed = false;

	m_sonarControl = new DigitalOutput(SONAR_CONTROL_PORT);
	m_leftSonar = new AnalogInput(L_SONAR_PORT);
	m_rightSonar = new AnalogInput(R_SONAR_PORT);

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


bool cDriveBase::CanSeeTape() {
	uint8_t bufferR[COLOR_SENSOR_BYTE_LENGTH];
	uint8_t bufferG[COLOR_SENSOR_BYTE_LENGTH];
	uint8_t bufferB[COLOR_SENSOR_BYTE_LENGTH];
	m_colorSensor->Read(COLOR_SENSOR_R_HIGH_REG, COLOR_SENSOR_BYTE_LENGTH, bufferR);
	m_colorSensor->Read(COLOR_SENSOR_G_HIGH_REG, COLOR_SENSOR_BYTE_LENGTH, bufferG);
	m_colorSensor->Read(COLOR_SENSOR_B_HIGH_REG, COLOR_SENSOR_BYTE_LENGTH, bufferB);
	if (BitShift(bufferR) > FLOOR_TAPE_R_LOW && BitShift(bufferR) < FLOOR_TAPE_R_HIGH) {
		if (BitShift(bufferG) > FLOOR_TAPE_G_LOW && BitShift(bufferR) < FLOOR_TAPE_G_HIGH) {
			if (BitShift(bufferB) > FLOOR_TAPE_B_LOW && BitShift(bufferR) < FLOOR_TAPE_B_HIGH) {
				return true;
			}
		}
	}

	return false;

}

double cDriveBase::GetRValue() {
	uint8_t bufferR[COLOR_SENSOR_BYTE_LENGTH];
	m_colorSensor->Read(COLOR_SENSOR_R_HIGH_REG, COLOR_SENSOR_BYTE_LENGTH, bufferR);
	return BitShift(bufferR);
}
double cDriveBase::GetGValue() {
	uint8_t bufferG[COLOR_SENSOR_BYTE_LENGTH];
	m_colorSensor->Read(COLOR_SENSOR_G_HIGH_REG, COLOR_SENSOR_BYTE_LENGTH, bufferG);
	return BitShift(bufferG);
}
double cDriveBase::GetBValue() {
	uint8_t bufferB[COLOR_SENSOR_BYTE_LENGTH];
	m_colorSensor->Read(COLOR_SENSOR_B_HIGH_REG, COLOR_SENSOR_BYTE_LENGTH, bufferB);
	return BitShift(bufferB);
}
double cDriveBase::GetCValue() {
	uint8_t bufferC[COLOR_SENSOR_BYTE_LENGTH];
	m_colorSensor->Read(COLOR_SENSOR_C_HIGH_REG, COLOR_SENSOR_BYTE_LENGTH, bufferC);
	return BitShift(bufferC);
}

int cDriveBase::BitShift(uint8_t *colorReadout) {
	int shiftee = colorReadout[0] << 8;
	shiftee = shiftee | colorReadout[1];
	return shiftee;
}

double cDriveBase::GetLeftDistance() {
	//return GetSonarDistance();
}

double cDriveBase::GetRightDistance() {
	//return GetSonarDistance();
}

cReversingMotorGroup* cDriveBase::getMotorGroupGyro()
{
    return m_motorGroupGyro;
}

iGyro* cDriveBase::getGyro()
{
    return m_gyro;
}

void cDriveBase::GetSonarDistance() {
	m_sonarControl->Set(true);
	unsigned initialTime = GetFPGATime();
	while (GetFPGATime() < initialTime + 100) {

	}

	m_leftSonarReading = m_leftSonar->GetVoltage();
	m_rightSonarReading = m_rightSonar->GetVoltage();
	m_sonarControl->Set(false);
	/*
	SerialPort* serialPort = new SerialPort(SONAR_BAUD_RATE);
	double distanceFeet;
//	for (int a = 0; a < 1000000; a++) { //we need to do this every million or so cycles, I think. (segun mr desilva senior)
	//	if (a == 1000000) {
			char buffer[80];
			int totalDistance;
			//distanceFeet = serialPort->GetBytesReceived();
			serialPort->Read(buffer, 8);
			std::string foo = buffer;
			return foo;
//		}
//	}
	//return distanceFeet;
*/
}
double cDriveBase::GetLeftSonarReading() {
	return m_leftSonarReading;
}

double cDriveBase::GetRightSonarReading() {
	return m_rightSonarReading;
}
bool cDriveBase::getIsReversed()
{
    return m_IsReversed;
}

void cDriveBase::setIsReversed(bool isreversed)
{
    m_IsReversed = isreversed;
}
