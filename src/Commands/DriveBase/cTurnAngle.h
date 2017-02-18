/* cTurnAngle
 * Turns the drivebase (clockwise for +, counter for -) by float angle input
 */

#ifndef cTurnAngle_H
#define cTurnAngle_H

#include "../../CommandBase.h"
#include <PIDController.h>
#include <math.h>

class cTurnAngle : public CommandBase, public PIDOutput {
private:
	float m_finalAngle;
	float m_startingAngle;

	float m_p;
	float m_i;
	float m_d;

	PIDController* m_controller;

	bool m_isDisabled;
public:
	cTurnAngle(float angle);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();

	void PIDWrite(double output);
};

#endif  // cTurnAngle_H
