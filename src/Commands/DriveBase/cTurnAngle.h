/* cTurnAngle
 * Turns the drivebase (clockwise for +, counter for -) by float angle input
 */

#ifndef cTurnAngle_H
#define cTurnAngle_H

#include "../../CommandBase.h"
#include <PIDController.h>
#include <math.h>

class cTurnAngle : public CommandBase, public PIDOutput {
	float m_finalAngle;
	float m_startingAngle;

	float m_p;
	float m_i;
	float m_d;

	int m_leftStart;
	int m_rightStart;

	PIDController* m_gyroController;
	PIDController* m_leftController;
	PIDController* m_rightController;

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
