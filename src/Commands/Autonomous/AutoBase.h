/*
 * AutoBase.h
 *
 *  Created on: Jan 26, 2017
 *      Author: s-4036956
 */

#ifndef SRC_COMMANDS_AUTONOMOUS_AUTOBASE_H_
#define SRC_COMMANDS_AUTONOMOUS_AUTOBASE_H_
#include <Commands/CommandGroup.h>

class AutoBase : CommandGroup
{
private:

public:
    static double s_angleTapeRobotPivotPoint;
    static double s_distanceToPivotPoint;
    static double s_angleRobotPivotPointGoal;
    static bool s_reachedLine;

    AutoBase();
    ~AutoBase();

    AutoBase* configureAutonomous();

    AutoBase* goLift1();
    AutoBase* goLift2();
    AutoBase* goLift3();

    AutoBase* placeGear();

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
