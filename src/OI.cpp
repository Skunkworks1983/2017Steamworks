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
//#include <Commands/Shooter/cTurtles>
OI::OI()
{
    m_buttons = new Joystick(OI_JOYSTICK_OPERATOR_PORT);

    m_leftStick = new Joystick(OI_JOYSTICK_LEFT_PORT);
    m_rightStick = new Joystick(OI_JOYSTICK_RIGHT_PORT);

    m_loadBall = new JoystickButton(m_buttons, OI_JOYSTICK_INDEXER_BUTTON);
    m_runConveyor = new JoystickButton(m_buttons, 10); //this does both now

    m_collectorPos = new JoystickButton(m_buttons, OI_JOYSTICK_COLLECTORPOS);

    m_loadBall->WhileHeld(new cRunFuelIndexer());
    m_runConveyor->WhileHeld(new cRunFuelConveyor());

    m_collectorPos->WhileHeld(new cSetCollectorPos());


    m_acquireGear = new JoystickButton(m_buttons, OI_JOYSTICK_ACQUIREGEAR_BUTTON);
    m_acquireBall = new JoystickButton(m_buttons, OI_JOYSTICK_ACQUIREBALL_BUTTON);
    /*m_assignTargetBoiler = new JoystickButton(m_buttons, OI_JOYSTICK_ASSIGNTARGETBOILER);
    m_assignTargetGoal = new JoystickButton(m_buttons, OI_JOYSTICK_ASSIGNTARGETGOAL);
    m_shootHigh = new JoystickButton(m_buttons, OI_JOYSTICK_SHOOTHIGH);
    m_climbRope = new JoystickButton(m_buttons, OI_JOYSTICK_CLIMBROPE);
    m_spinUpShooter = new JoystickButton(m_buttons, OI_JOYSTICK_SPINUPSHOOTER);
    */
    m_enableManualShooting = new JoystickButton(m_buttons, OI_JOYSTICK_TURRET_CONTROL);
    m_enableManualShooting->WhileHeld(new cManualShooterControl());

    m_spinUpShooter = new JoystickButton(m_buttons, OI_JOYSTICK_SPINUPSHOOTER);
    m_spinUpShooter->WhileHeld(new cSpinUpShooter());

    m_acquireBall->WhileHeld(new cRunFuelCollector(1));

    /*m_acquireGear->WhenPressed(new cAcquireGear(true, 1));
    m_acquireGear->WhenReleased(new cAcquireGear(false, 1));

    m_climbRope->WhenPressed(new cClimbRope(1, ROPECLIMB_COMMAND_TIME_ON));
    m_climbRope->WhenReleased(new cClimbRope(0, ROPECLIMB_COMMAND_TIME_OFF));

    m_enableTurretControl->WhileHeld(new cManualTurretControl());


    m_FuelIndexer->WhenPressed(new cRunFuelIndexer(1, FuelIndexer_COMMAND_TIME_ON));

    m_togglereversal->WhenPressed(new cSwitchBackFront());

    m_enableShooterControl->WhileHeld(new cManualShooterControl());*/

    //m_FuelIndexer->WhenPressed(new cRunFuelIndexer(1, FuelIndexer_COMMAND_TIME_ON));

    m_acquireGear->WhileHeld(new cAcquireGear(0, 1000));


}

float OI::getLeftStickY()
{
    return m_leftStick->GetY();
}
float OI::getRightStickY()
{
    return m_rightStick->GetY();
}
//ayy lmao
float OI::getTurretSlider()
{
    return (m_buttons->GetY() - (OI_TURRET_SLIDER_RANGE / 2)) *
            (1 / OI_TURRET_SLIDER_RANGE);
}

float OI::getShooterSlider()
{
    return (m_buttons->GetX() - (OI_SHOOTER_SLIDER_RANGE / 2)) *
            (1 / OI_SHOOTER_SLIDER_RANGE);
}

bool OI::getLeftTriggerPressed() {
	return m_leftStick->GetButton(Joystick::kTriggerButton);
}

bool OI::getRightTriggerPressed() {
	return m_rightStick->GetButton(Joystick::kTriggerButton);
}

bool OI::getLeft2Pressed() {
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
