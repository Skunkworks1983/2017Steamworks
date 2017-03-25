#include "OI.h"
#include <RobotMap.h>
#include <Commands/GearMechanism/cAcquireGear.h>
#include <Commands/Climber/cClimbRope.h>
#include <Commands/GearMechanism/cDepositGear.h>
#include <Commands/Shooter/cShootPID.h>
#include <Commands/Shooter/cShootHigh.h>
#include <Commands/Shooter/cSpinUpShooter.h>
#include <Commands/Shooter/cAcquireBall.h>
#include <Commands/Shooter/cShootPID.h>
#include <Commands/Turret/cRotateTurret.h>
#include <Commands/DriveBase/cSwitchBackFront.h>
#include <Commands/FloorCollector/cRunFloorCollector.h>
#include <Commands/FloorCollector/cSetCollectorPos.h>
#include <Commands/FloorCollector/cSetCollectorSpeed.h>
#include <Commands/FuelIndexer/cRunFuelIndexer.h>
#include <Commands/FuelConveyor/cRunFuelConveyor.h>
#include <Commands/Turret/cManualTurretControl.h>
#include <Commands/Shooter/cManualShooterControl.h>
#include <Commands/Turret/cAssignTargetBoiler.h>

OI::OI()
{
    m_buttons = new Joystick(OI_JOYSTICK_OPERATOR_PORT);

    m_leftStick = new Joystick(OI_JOYSTICK_LEFT_PORT);
    m_rightStick = new Joystick(OI_JOYSTICK_RIGHT_PORT);

    m_loadBall = new JoystickButton(m_buttons, OI_JOYSTICK_INDEXER_BUTTON);
    m_runConveyor = new JoystickButton(m_buttons, 10); //this does both now

    m_climbRope = new JoystickButton(m_buttons, 11);

    m_collectorPosUp = new JoystickButton(m_buttons, OI_JOYSTICK_COLLECTORPOSUP);
    m_collectorPosDown = new JoystickButton(m_buttons, OI_JOYSTICK_COLLECTORPOSDOWN);

    m_acquireGear = new JoystickButton(m_buttons, OI_JOYSTICK_ACQUIREGEAR_BUTTON);
    m_acquireBall = new JoystickButton(m_buttons, OI_JOYSTICK_ACQUIREBALL_BUTTON);

    m_manualCollectorUp = new JoystickButton(m_buttons, 12);
    m_manualCollectorDown = new JoystickButton(m_buttons, 13);

    m_shootPosLiftMiddle = new JoystickButton(m_buttons, OI_JOYSTICK_ASSIGN_LIFT_MIDDLE);
    m_shootPosLiftClose = new JoystickButton(m_buttons, OI_JOYSTICK_ASSIGN_LIFT_CLOSE);
    m_shootPosHopperClose = new JoystickButton(m_buttons, 5);

    m_climbRope->WhileHeld(new cClimbRope(0.9));

    m_shootPosLiftMiddle->WhenPressed(new cAssignTargetBoiler(LIFT_MIDDLE));
    m_shootPosLiftClose->WhenPressed(new cAssignTargetBoiler(LIFT_CLOSE));
    m_shootPosHopperClose->WhenPressed(new cAssignTargetBoiler(HOPPER_CLOSE));

    m_enableManual = new JoystickButton(m_buttons, OI_JOYSTICK_TURRET_CONTROL);
    CommandGroup* manualControllers = new CommandGroup();
    manualControllers->AddParallel(new cManualShooterControl());
    manualControllers->AddParallel(new cManualTurretControl());
    m_enableManual->WhileHeld(manualControllers);
    m_runConveyor->WhileHeld(new cRunFuelConveyor());

    m_collectorPosUp->WhileHeld(new cRunFloorCollector(-1));
    CommandGroup* DownRoll = new CommandGroup();
    DownRoll->AddParallel(new cRunFloorCollector(1));
    DownRoll->AddParallel(new cSetCollectorPos(FLOORCOLLECTOR_MAX_ENC_ANGLE));
    m_collectorPosDown->WhileHeld(DownRoll);

    m_spinUpShooter = new JoystickButton(m_buttons, OI_JOYSTICK_SPINUPSHOOTER);
    m_spinUpShooter->WhileHeld(new cSpinUpShooter());

    m_pidSpinUpShooter = new JoystickButton(m_buttons, 4);
    m_pidSpinUpShooter->WhileHeld(new cShootPID(8800));

    m_manualCollectorUp->WhileHeld(new cSetCollectorSpeed(0.25));
    m_manualCollectorDown->WhileHeld(new cSetCollectorSpeed(-0.25));

    // // // // // //

    // testing. will be removed later. don't get upset at me for magic numbers

    m_unjam = new JoystickButton(m_buttons, OI_UNJAM_BUTTON);
    m_unjam->WhileHeld(new cRunFuelConveyor(-1));

    // // // // // //

    //m_acquireBall->WhileHeld(new cRunFloorCollector(-1));
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
	return x;
}

double OI::getRotPos() {
    // this shit is so broken. i'm too lazy to fix this though
	return clamp((m_buttons->GetY() - 0.5) * -1.25, -0.5, 0.5) * 2;
}

