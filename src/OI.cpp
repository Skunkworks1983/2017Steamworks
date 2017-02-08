#include <Commands/cAcquireBall.h>
#include "OI.h"
#include "RobotMap.h"
#include <Commands/cAcquireGear.h>
#include <Commands/cClimbRope.h>
#include <Commands/cDepositGear.h>
#include <Commands/cShootHigh.h>
#include <Commands/cSpinUpShooter.h>

OI::OI()
{
    m_buttons = new Joystick(OI_JOYSTICK_OPERATOR_PORT);

    m_leftStick = new Joystick(OI_JOYSTICK_LEFT_PORT);
    m_rightStick = new Joystick(OI_JOYSTICK_RIGHT_PORT);

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
}

float OI::getLeftStickY()
{
    return m_leftStick->GetY();
}
float OI::getRightStickY()
{
    return m_rightStick->GetY();
}

