/*
 * cSwivelCamera.h
 * When the top button is pressed on the joystick, set the turret to an extreme, rotating driver camera.
 */
#ifndef cSwivelCamera_H
#define cSwivelCamera_H

#include <CommandBase.h>
#include <RobotMap.h>

class cSwivelCamera : public CommandBase {
private:
	bool m_forward;
public:
	cSwivelCamera(bool forward); //if not forward we assume back
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // cSwivelCamera_H
