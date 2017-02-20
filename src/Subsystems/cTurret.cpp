#include "cTurret.h"
#include <Subsystems/Utilities/cMotor.h>
#include <RobotMap.h>
#include <Commands/Turret/cRotateTurret.h>
#include <WPILib.h>

cTurret::cTurret()
{
    m_motor1 = new cMotor(TURRET_MOTOR1_PORT, NeveRest40);
    m_motor1->setControlMode(frc::CANSpeedController::ControlMode::kPosition);
    m_motor1->configForwardLimit((double) turret_angle_to_rots(-90));
    m_motor1->configReverseLimit((double) turret_angle_to_rots(90));
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
    float desired = turret_angle_to_rots(heading);
    m_motor1->setSetpoint(desired);
}

void cTurret::rotate(float degrees)
{
    float current = turret_rots_to_angle(m_motor1->getPosition() / TURRET_MOTOR1_GEARING);
    float desired = turret_angle_to_rots(current + degrees);

    m_motor1->setSetpoint(desired);
}

float cTurret::getHeading()
{
    return turret_rots_to_angle(m_motor1->getPosition() / TURRET_MOTOR1_GEARING);
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
