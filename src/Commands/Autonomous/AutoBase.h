/*
 * AutoBase.h
 *
 *  Created on: Jan 26, 2017
 *      Author: s-4036956
 *
 * This class is to create command groups for
 * the autonomous period. The AutoBase itself is
 * a command group, and calling member functions such
 * as goLift1 add groups of commands to the new
 * AutoBase command group, which then becomes the
 * entire list of commands for everything in the autonomous period.
 *
 * Each of the functions that return a new AutoBase
 * work by creating their own AutoBase (essentially a CommandGroup), and
 * adding it to the current master list of commands for
 * the autonomous period.
 *
 * tl;dr: we add commandgroups for small auto functions (go to lift 1),
 * and add them to the master list of auto commands (go to lift 1, then
 * place gear on lift 1).
 */

#ifndef SRC_COMMANDS_AUTONOMOUS_AUTOBASE_H_
#define SRC_COMMANDS_AUTONOMOUS_AUTOBASE_H_

#pragma once

#include <Commands/CommandGroup.h>
#include <RobotMap.h>

// TODO: idk where to put this so it's going here for now
// i know these shouldn't be constants, but it won't build
// without them being that way. todo: fix

eAlliance alliance = Red;
eStartingPosition startPosition = POS_1;

class AutoBase: public frc::CommandGroup
{
private:
    CommandGroup* m_placeGear;
    CommandGroup* m_driveToLine;

public:
    static double s_angleTapeRobotPivotPoint;
    static double s_distanceToPivotPoint;
    static double s_angleRobotPivotPointGoal;
    static bool s_reachedLine;

    AutoBase();
    ~AutoBase();

    AutoBase* configureAutonomous();

// returns the current auto starting position based on the dial/switch
    eStartingPosition getStartingPosition();

// returns the current alliance based on dial/switch
    eAlliance getAlliance();

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
