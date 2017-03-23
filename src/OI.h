#ifndef OI_H
#define OI_H
#include <Subsystems/Interfaces/iOI.h>

#include "WPILib.h"
#include <math.h>

class OI: public iOI
{
private:

	double SLIDER_MIN = -.953125;
	double SLIDER_MAX = .0787402;

    Joystick *m_buttons; //this isn't a joystick
    //it's the operating buttons <3

    Joystick *m_leftStick;
    Joystick *m_rightStick;


    JoystickButton *m_loadBall;
    JoystickButton *m_runConveyor;

    JoystickButton *m_collectorPosUp;
    JoystickButton *m_collectorPosDown;

    // outdated
    JoystickButton *m_acquireGear;
    JoystickButton *m_acquireBall;
    JoystickButton *m_enableManual;
    JoystickButton *m_spinUpShooter;
    JoystickButton *m_shootPosLiftMiddle;
    JoystickButton *m_shootPosLiftClose;
    JoystickButton *m_shootPosHopperClose;
    JoystickButton *m_pidSpinUpShooter;
    JoystickButton *m_unjam;
    /*JoystickButton *m_assignTargetBoiler;
    JoystickButton *m_assignTargetGoal;
    JoystickButton *m_shootHigh;*/
    JoystickButton *m_climbRope;
    /*JoystickButton *m_spinUpShooter;
    JoystickButton *m_loadBall;
    JoystickButton *m_fuelIndexer;
    JoystickButton *m_togglereversal;
    JoystickButton *m_enableTurretControl;
    JoystickButton *m_enableShooterControl;
    */

public:
    OI();
    ~OI();
    float getLeftStickY();
    float getRightStickY();

    bool getLeftTriggerPressed();
    bool getRightTriggerPressed();

    bool getLeft2Pressed();

    double getSliderPos();
    double getRotPos();
};

#endif
