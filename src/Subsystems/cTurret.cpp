#include "cTurret.h"
#include <Subsystems/Utilities/cMotor.h>
#include <RobotMap.h>
#include <Commands/Turret/cRotateTurret.h>
#include <WPILib.h>

cTurret::cTurret()
{
    m_motor1 = new cMotor(TURRET_MOTOR1_PORT, NeveRest40);
    m_motor1->setControlMode(frc::CANSpeedController::ControlMode::kPosition);
    m_motor1->configForwardLimit((double) turret_angle_to_ticks(-90));
    m_motor1->configReverseLimit((double) turret_angle_to_ticks(90));

    m_motor1->setEnabled(false);
}

cTurret::~cTurret()
{
    delete m_motor1;
}

void cTurret::setSpeed(float speed)
{
    m_motor1->setOutput(speed);
}

void cTurret::setOrientation(float heading)
{
    float desired = turret_angle_to_ticks(heading);
    m_motor1->setSetpoint(desired);
}

void cTurret::rotate(float degrees)
{
    float current = turret_ticks_to_angle(m_motor1->getPosition() / TURRET_MOTOR1_GEARING);
    float desired = turret_angle_to_ticks(current + degrees);

    m_motor1->setSetpoint(desired);
}

float cTurret::getHeading()
{
    return turret_ticks_to_angle(m_motor1->getPosition() / TURRET_MOTOR1_GEARING);
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

cMotor* cTurret::getTurretMotor()
{
    return m_motor1;
}

void cTurret::setSetpoint(int ticks)
{
	std::cout << "Setpoint: " << ticks << std::endl;
    m_motor1->setSetpoint(ticks);
}

double cTurret::PIDGet()
{
    return m_motor1->PIDGet();
}

double cTurret::getSetpoint()
{
    return m_motor1->GetSetpoint();
}

void cTurret::setEnabled(bool enabled)
{
    m_motor1->setEnabled(enabled);
}
