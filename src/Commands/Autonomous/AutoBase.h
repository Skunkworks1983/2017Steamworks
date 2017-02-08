/*
 * AutoBase.h
 *
 *  Created on: Jan 26, 2017
 *      Author: s-4036956
 */

#ifndef SRC_COMMANDS_AUTONOMOUS_AUTOBASE_H_
#define SRC_COMMANDS_AUTONOMOUS_AUTOBASE_H_
#include <RobotMap.h>


class AutoBase
{
private:

    CommandGroup placeGear = new CommandGroup;


public:
	static double angleTapeRobotPivotPoint;
	static double distanceToPivotPoint;
	static double angleRobotPivotPointGoal;
    AutoBase();
    ~AutoBase();
    void Initialize();
    void Execute();
    bool IsFinished();
    void End();
    void Interrupted();
    float setTargetAngle();
    float setDistance();
//TODO REQUIRES
    //gyro code (navx, ahrs?)
    //gear mechanism
    //drive train layout
    //color sensor (maybe)
//TODO GOALS
    //cross baseline
    //deposit gear
    //shoot high? (need to ask)
    //position front of loading zone
};



#endif /* SRC_COMMANDS_AUTONOMOUS_AUTOBASE_H_ */
