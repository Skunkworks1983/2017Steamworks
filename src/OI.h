#ifndef OI_H
#define OI_H

#include "WPILib.h"

class OI
{
private:
	Joystick *m_leftStick;
	Joystick *m_rightStick;
public:
	OI();
	~OI();
	float getLeftStickY();
	float getRightStickY();

};

#endif
