/* cDriveStraight
 * Drives straight with the gyro, taking in a number of feet of forward movement.
 * Use in combination with a cTurnAngle to make the dank autos happen
 */

#ifndef cDriveStraight_H
#define cDriveStraight_H

#include "../../CommandBase.h"
#include "../../Subsystems/cDriveBase.h"
#include <RobotMap.h>
#include <PIDController.h>
#include <PIDOutput.h>
/*needs more yurtles and fewer rocks
         __.._
____...-`  \ /``'-..
`~-..`(.-~~~|    /  `-.
    : :   ,``. .<____/ `:_
    ` `..`   .` /   / \ /:`-.
     `. `. ,`  /    \_.'.`.,,:
      |`._`-.__\_.-``.-'  `._
      `.,,`-`....-.`~`.'`. c `.
                   `-. `,`. ._ )
                      ```  `--`
*/
class cDriveStraight : public CommandBase, public PIDOutput, public PIDSource {
private:
	float m_timeout;

	int m_endTicks;
	double m_beginningYaw;

	PIDController* m_controller;

	bool m_isWiggle = false;

	float m_p;
	float m_i;
	float m_d;
	float m_f;

	float m_curTicks;

	float m_speed;

	bool m_isDisabled;

	bool m_gyroMode;
public:
	cDriveStraight(float distance, float speed=0.25, float timeout=0, bool wiggly = false, bool isWiggle = false); //In feet
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();

	void PIDWrite(double output);
	double PIDGet();
};

#endif
