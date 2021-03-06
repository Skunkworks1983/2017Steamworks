#include "OI.h"
#include <RobotMap.h>
#include <Commands/GearMechanism/cAcquireGear.h>
#include <Commands/Climber/cClimbRope.h>
#include <Commands/GearMechanism/cDepositGear.h>
#include <Commands/Shooter/cShootHigh.h>
#include <Commands/Shooter/cSpinUpShooter.h>
#include <Commands/Shooter/cAcquireBall.h>
#include <Commands/Turret/cRotateTurret.h>
#include <Commands/FuelCollector/cRunFuelCollector.h>
#include <Commands/FuelCollector/cSetCollectorPos.h>
#include <Commands/DriveBase/cSwitchBackFront.h>
#include <Commands/FuelIndexer/cRunFuelIndexer.h>
#include <Commands/FuelConveyor/cRunFuelConveyor.h>
#include <Commands/Turret/cManualTurretControl.h>
#include <Commands/Shooter/cManualShooterControl.h>
OI::OI()
{
    m_buttons = new Joystick(OI_JOYSTICK_OPERATOR_PORT);

    m_leftStick = new Joystick(OI_JOYSTICK_LEFT_PORT);
    m_rightStick = new Joystick(OI_JOYSTICK_RIGHT_PORT);

    m_loadBall = new JoystickButton(m_buttons, OI_JOYSTICK_INDEXER_BUTTON);
    m_runConveyor = new JoystickButton(m_buttons, 10); //this does both now

    m_collectorPos = new JoystickButton(m_buttons, OI_JOYSTICK_COLLECTORPOS);

    m_climbRope = new JoystickButton(m_buttons, 11);

    m_loadBall->WhileHeld(new cRunFuelIndexer());
    m_runConveyor->WhileHeld(new cRunFuelConveyor());

    m_collectorPos->WhileHeld(new cSetCollectorPos());

    m_climbRope->WhileHeld(new cClimbRope(0.9, 0));

    m_acquireGear = new JoystickButton(m_buttons, OI_JOYSTICK_ACQUIREGEAR_BUTTON);
    m_acquireBall = new JoystickButton(m_buttons, OI_JOYSTICK_ACQUIREBALL_BUTTON);

    m_enableManualShooting = new JoystickButton(m_buttons, OI_JOYSTICK_TURRET_CONTROL);
    m_enableManualShooting->WhileHeld(new cManualShooterControl());

    m_spinUpShooter = new JoystickButton(m_buttons, OI_JOYSTICK_SPINUPSHOOTER);
    m_spinUpShooter->WhileHeld(new cSpinUpShooter());

    m_acquireBall->WhileHeld(new cRunFuelCollector(1));
    m_acquireGear->WhileHeld(new cAcquireGear(true, 10000));
}

float OI::getLeftStickY()
{
    return m_leftStick->GetY();
}

float OI::getRightStickY()
{
    return m_rightStick->GetY();
}
float OI::getTurretSlider()
{
    return (m_buttons->GetY() - (OI_TURRET_SLIDER_RANGE / 2)) * (1 / OI_TURRET_SLIDER_RANGE);
}

float OI::getShooterSlider()
{
    return (m_buttons->GetX() - (OI_SHOOTER_SLIDER_RANGE / 2)) * (1 / OI_SHOOTER_SLIDER_RANGE);
}

bool OI::getLeftTriggerPressed()
{
    return m_leftStick->GetButton(Joystick::kTriggerButton);
}

bool OI::getRightTriggerPressed()
{
    return m_rightStick->GetButton(Joystick::kTriggerButton);
}

bool OI::getLeft2Pressed()
{
    return m_leftStick->GetRawButton(2);
}

double OI::getSliderPos() {
	double x = m_buttons->GetX();
	x = pow(x, 10);
	x /= .618726;
	x = 1 - x;
	std::cout << x << std::endl;
	return x;
}

double OI::getRotPos() {
	return m_buttons->GetY();
}
