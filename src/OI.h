#ifndef OI_H
#define OI_H

#include "WPILib.h"
class OI
{
private:

    Joystick *m_buttons; //this isn't a joystick
    //its the operating buttons <3

    Joystick *m_leftStick;
    Joystick *m_rightStick;

    JoystickButton *m_acquireGear;
    JoystickButton *m_acquireBall;
    JoystickButton *m_assignTargetBoiler;
    JoystickButton *m_assignTargetGoal;
    JoystickButton *m_shootHigh;
    JoystickButton *m_climbRope;
    JoystickButton *m_spinUpShooter;

public:
    OI();
    ~OI();
    float getLeftStickY();
    float getRightStickY();
};

#endif
