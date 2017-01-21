#ifndef ROBOTMAP_H
#define ROBOTMAP_H

#include "WPILib.h"


/**
 * The RobotMap is a mapping from the ports sensors and actuators are wired into
 * to a variable name. This provides flexibility changing wiring, makes checking
 * the wiring easier and significantly reduces the number of magic numbers
 * floating around.
 */
 
// For example to map the left and right motors, you could define the
// following variables to use with your drivetrain subsystem.
//const int LEFTMOTOR = 1;
//const int RIGHTMOTOR = 2;
const int DRIVEBASE_LEFTMOTOR_1_PORT = 1;
const int DRIVEBASE_LEFTMOTOR_2_PORT = 2;
const int DRIVEBASE_LEFTMOTOR_3_PORT = 3;
const int DRIVEBASE_RIGHTMOTOR_1_PORT = 4;
const int DRIVEBASE_RIGHTMOTOR_2_PORT = 5;
const int DRIVEBASE_RIGHTMOTOR_3_PORT = 6;

const int OI_JOYSTICK_LEFT_PORT = 1;
const int OI_JOYSTICK_RIGHT_PORT = 2;
// If you are using multiple modules, make sure to define both the port
// number and the module. For example you with a rangefinder:
//const int RANGE_FINDER_PORT = 1;
//const int RANGE_FINDER_MODULE = 1;

#endif
