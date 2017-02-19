#include "cTurret.h"
#include <Subsystems/Utilities/cMotor.h>
#include <RobotMap.h>
#include <Commands/Turret/cRotateTurret.h>
#include <WPILib.h>

cTurret::cTurret()
{
    m_motor1 = new cMotor(TURRET_MOTOR1_PORT, NeveRest40);
    m_motor1->setControlMode(frc::CANSpeedController::ControlMode::kPosition);
    m_motor1->configForwardLimit((double) TURRET_ANGLE_TO_ROTS(-90));
    m_motor1->configReverseLimit((double) TURRET_ANGLE_TO_ROTS(90));
}

cTurret::~cTurret()
{
    delete m_motor1;
}

void cTurret::InitDefaultCommand()
{

}

void cTurret::setSpeed(float speed)
{
    m_motor1->setOutput(speed);
}

void cTurret::setOrientation(float heading)
{
    float desired = TURRET_ANGLE_TO_ROTS(heading);
    m_motor1->setSetpoint(desired);
}

void cTurret::rotate(float degrees)
{
    float current = TURRET_ROTS_TO_ANGLE(m_motor1->getPosition() / TURRET_MOTOR1_GEARING);
    float desired = TURRET_ANGLE_TO_ROTS(current + degrees);

    m_motor1->setSetpoint(desired);
}

float cTurret::getHeading()
{
    return TURRET_ROTS_TO_ANGLE(m_motor1->getPosition() / TURRET_MOTOR1_GEARING);
}

void cTurret::setManualEnabled(bool state)
{
    // disable sensor input
    m_motor1->setControlMode(
            state ? frc::CANSpeedController::ControlMode::kPercentVbus : frc::CANSpeedController::ControlMode::kPosition);
    m_manualEnabled = state;
}

bool cTurret::isManualEnabled()
{
    return m_manualEnabled;
}
