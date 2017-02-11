#include "OI.h"
#include "RobotMap.h"
#include <Commands/GearMechanism/cAcquireGear.h>
#include <Commands/Climber/cClimbRope.h>
#include <Commands/GearMechanism/cDepositGear.h>
#include <Commands/Shooter/cShootHigh.h>
#include <Commands/Shooter/cSpinUpShooter.h>
#include <Commands/FuelCollector/cRunFuelFlap.h>
#include <Commands/FuelLoader/cRunFuelLoader.h>
#include <Commands/FuelCollector/cRunHopperIntake.h>

OI::OI()
{
    m_buttons = new Joystick(OI_JOYSTICK_OPERATOR_PORT);

    m_leftStick = new Joystick(OI_JOYSTICK_LEFT_PORT);
    m_rightStick = new Joystick(OI_JOYSTICK_RIGHT_PORT);

    m_fuelLoader = new JoystickButton(m_buttons, 9);
    m_acquireGear = new JoystickButton(m_buttons, 8);
    m_acquireBall = new JoystickButton(m_buttons, 7);
    m_assignTargetBoiler = new JoystickButton(m_buttons, 6);
    m_assignTargetGoal = new JoystickButton(m_buttons, 5);
    m_shootHigh = new JoystickButton(m_buttons, 4);
    m_climbRope = new JoystickButton(m_buttons, 3);
    m_spinUpShooter = new JoystickButton(m_buttons, 2);

    m_acquireGear->WhenPressed(new cAcquireGear(true, 1));
    m_acquireGear->WhenReleased(new cAcquireGear(false, 1));

    m_climbRope->WhenPressed(new cClimbRope(1, ROPECLIMB_COMMAND_TIME_ON));
    m_climbRope->WhenReleased(new cClimbRope(0, ROPECLIMB_COMMAND_TIME_OFF));

    m_acquireBall->WhenPressed(new cRunHopperIntake(1, FUELCOLLECTOR_COMMAND_TIME_ON));

    m_fuelLoader->WhenPressed(new cRunFuelLoader(1, FUELLOADER_COMMAND_TIME_ON));
}

float OI::getLeftStickY()
{
    return m_leftStick->GetY();
}
float OI::getRightStickY()
{
    return m_rightStick->GetY();
}

