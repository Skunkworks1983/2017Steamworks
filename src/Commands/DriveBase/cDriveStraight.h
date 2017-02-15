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
                 HD`-. `,`. ._ )
                      ```  `--`
*/
class cDriveStraight : public CommandBase, public PIDOutput {
private:
	int m_rotations;
	double m_beginningYaw;

	PIDController* m_controller;

	float m_p;
	float m_i;
	float m_d;

	float m_curRevolutions;
	float m_revolutionOffset;

	float m_speed;
public:
	cDriveStraight(float distance, float speed=0.5); //In feet
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();

	void PIDWrite(double output);
};

#endif
