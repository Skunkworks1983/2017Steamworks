#include <Commands/Shooter/cAcquireBall.h>
#include "OI.h"
#include "RobotMap.h"
#include <Commands/cAcquireGear.h>
#include <Commands/cClimbRope.h>
#include <Commands/cDepositGear.h>
#include <Commands/cShootHigh.h>
#include <Commands/cSpinUpShooter.h>
#include <Commands/cRunFuelFlap.h>
#include <Commands/cRunFuelLoader.h>
#include <Commands/cRunHopperIntake.h>

OI::OI()
{
    m_buttons = new Joystick(OI_JOYSTICK_OPERATOR_PORT);

    m_leftStick = new Joystick(OI_JOYSTICK_LEFT_PORT);
    m_rightStick = new Joystick(OI_JOYSTICK_RIGHT_PORT);

    m_acquireGear = new JoystickButton(m_buttons, OI_JOYSTICK_ACQUIREGEAR_BUTTON);
    m_acquireBall = new JoystickButton(m_buttons, OI_JOYSTICK_ACQUIREBALL_BUTTON);
    m_assignTargetBoiler = new JoystickButton(m_buttons, OI_JOYSTICK_ASSIGNTARGETBOILER);
    m_assignTargetGoal = new JoystickButton(m_buttons, OI_JOYSTICK_ASSIGNTARGETGOAL);
    m_shootHigh = new JoystickButton(m_buttons, OI_JOYSTICK_SHOOTHIGH);
    m_climbRope = new JoystickButton(m_buttons, OI_JOYSTICK_CLIMBROPE);
    m_spinUpShooter = new JoystickButton(m_buttons, OI_JOYSTICK_SPINUPSHOOTER);
    m_rotateTurretLeft = new JoystickButton(m_buttons, OI_JOYSTICK_ROTATETURRETLEFT);
    m_rotateTurretRight = new JoystickButton(m_buttons, OI_JOYSTICK_ROTATETURRETRIGHT);
    m_fuelLoader = new JoystickButton(m_buttons, 9);
    m_assignTargetBoiler = new JoystickButton(m_buttons, 6);

    m_acquireGear->WhenPressed(new cAcquireGear(true, 1));
    m_acquireGear->WhenReleased(new cAcquireGear(false, 1));

    m_climbRope->WhenPressed(new cClimbRope(1, ROPECLIMB_COMMAND_TIME_ON));
    m_climbRope->WhenReleased(new cClimbRope(0, ROPECLIMB_COMMAND_TIME_OFF));

    m_rotateTurretLeft->WhenPressed(new cRotateTurret(CROTATETURRET_LEFT_SPEED));
    m_rotateTurretRight->WhenPressed(new cRotateTurret(CROTATETURRET_RIGHT_SPEED));


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

