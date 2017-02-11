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

#define ROBOT_NAME "lol"
#define LOGFILE_NAME "/U/robotLog"

enum FuelCollectorPosition {
    UP = 90,
    DOWN = 0
};

#define BOILER_PI_IP "10.19.83.237"
#define BOILER_PI_PORT "5802"

const int BOILER_PI_ID = 1;

#define GEAR_PI_IP "10.19.83.217"
#define GEAR_PI_PORT "5800"

const int GEAR_PI_ID = 1;


const int MSG_LEN = 1024;

const int DRIVEBASE_LEFT_DIRECTION = -1;
const int DRIVEBASE_RIGHT_DIRECTION = 1;

const int DRIVEBASE_LEFTMOTOR_1_PORT = 12;
const int DRIVEBASE_LEFTMOTOR_2_PORT = 14;
const int DRIVEBASE_LEFTMOTOR_3_PORT = 14;
const int DRIVEBASE_RIGHTMOTOR_1_PORT = 15;
const int DRIVEBASE_RIGHTMOTOR_2_PORT = 13;
const int DRIVEBASE_RIGHTMOTOR_3_PORT = 13;

const int OI_JOYSTICK_LEFT_PORT = 1;
const int OI_JOYSTICK_RIGHT_PORT = 0;

const int OI_JOYSTICK_OPERATOR_PORT = 2;

const int OI_JOYSTICK_ACQUIREGEAR_BUTTON = 1;
const int OI_JOYSTICK_ACQUIREBALL_BUTTON = 2;
const int OI_JOYSTICK_ASSIGNTARGETBOILER = 3;
const int OI_JOYSTICK_ASSIGNTARGETGOAL = 4;
const int OI_JOYSTICK_SHOOTHIGH = 5;
const int OI_JOYSTICK_CLIMBROPE = 6;
const int OI_JOYSTICK_SPINUPSHOOTER = 7;
const int OI_JOYSTICK_ROTATETURRETLEFT = 8;
const int OI_JOYSTICK_ROTATETURRETRIGHT = 9;

const float DRIVEBASE_FOOT_PER_TICK = 0.0025;

const float SIMPLEDRIVEFORWARD_PID_P = 1;
const float SIMPLEDRIVEFORWARD_PID_I = 1;
const float SIMPLEDRIVEFORWARD_PID_D = 1;

const int CLIMBER_MOTOR1_PORT = 10000;
const int CLIMBER_MOTOR2_PORT = 10000;

const float CLIMBER_MOTOR_DIRECTION = 1;

const int FUELCOLLECTOR_MOTOR1_PORT = 10000;
const int FUELCOLLECTOR_MOTOR2_PORT = 10000;

const int FUELCOLLECTOR_COMMAND_TIME_ON = 5;

const int FUELLOADER_MOTOR1_PORT = 10000;

const int FUELLOADER_COMMAND_TIME_ON = 5;

const int TURRET_MOTOR1_PORT = 10000;

const int SHOOTER_MOTOR1_PORT = 10000;
const int SHOOTER_MOTOR2_PORT = 10000;
const double SHOOTER_TARGET_SPEED = 1; //rps

const int GEARCOLLECTOR_SERVO1_PORT = 10000;

const int GEARCOLLECTOR_OPEN_ANGLE = 170;
const int GEARCOLLECTOR_CLOSE_ANGLE = 0;

const float ROPECLIMB_COMMAND_TIME_ON = 30;
const float ROPECLIMB_COMMAND_TIME_OFF = 1;

const float CROTATETURRET_LEFT_SPEED = .5;
const float CROTATETURRET_RIGHT_SPEED = -.5;

#include <Services/cLogger.h>

#define LOG_DEBUG(...) {\
            char buf[1024];\
            sprintf(buf, __VA_ARGS__);\
            Logger::getLogger()->log(buf, Debug);}

#define LOG_INFO(...) {\
            char buf[1024];\
            sprintf(buf, __VA_ARGS__);\
            Logger::getLogger()->log(buf, Info);}

#define LOG_WARNING(...) {\
            char buf[1024];\
            sprintf(buf, __VA_ARGS__);\
            Logger::getLogger()->log(buf, Warning);}

#define LOG_ERROR(...) {\
            char buf[1024];\
            sprintf(buf, __VA_ARGS__);\
            Logger::getLogger()->log(buf, Error);}

#define LOG_RECORD(...) {\
            char buf[1024];\
            sprintf(buf, __VA_ARGS__);\
            Logger::getLogger()->log(buf, Record);}

const float BANEBOTS775_STALLING_CURRENT = 130;
const float NEVEREST40_STALLING_CURRENT = 11.5;
const float CIM_STALLING_CURRENT = 133;

//AUTONOMOUS THINGS

//SPECIFICALLY GEAR PLACEMENT THINGS
#define ARM_ANGLE ((70*3.14)/180) // Angle of the arms surrounding the hook from the wall. Radians. Placeholder.
#define DISTANCE_TO_RECOVERY_POINT 5 //placeholder! In feet, apparently (though that's super dumb)
/* the commented out values below are so because they pertain to the path if the robot is outside of the arms, an unlikely scenario.
#define anglePerpindicularGoalRecoveryPoint ((70*3.14)/180) // same! radians
#define anglePerpindicularGoalPivotPoint ((70*3.14)/180) //marcador de posicion
#define DISTANCE_FROM_REC_POINT_TO_PIVOT_POINT 10 //same! feet
#define anglePivotPointRecoveryPointGoal ((30*3.14)/180) //placeholder radians
 */
#define angleWallTapePivotPoint ((100 * 3.14)/180) //can you guess what im going to say here?
#define DISTANCE_FROM_TAPE_TO_PIVOT_POINT 1.5 // ibid.
#define angleGoalPivotPointTape ((45 * 3.14)/180) // surrogate for a real value
#define DISTANCE_FROM_PIVOT_POINT_TO_GOAL 1234 //listen, i'm not an expert, but I'm almost certain that the distance from the pivot point to the goal will not be 1234 feet

#include <Services/cLogger.h>

#define LOG_DEBUG(...) {\
            char buf[1024];\
            sprintf(buf, __VA_ARGS__);\
            Logger::getLogger()->log(buf, Debug);}

#define LOG_INFO(...) {\
            char buf[1024];\
            sprintf(buf, __VA_ARGS__);\
            Logger::getLogger()->log(buf, Info);}

#define LOG_WARNING(...) {\
            char buf[1024];\
            sprintf(buf, __VA_ARGS__);\
            Logger::getLogger()->log(buf, Warning);}

#define LOG_ERROR(...) {\
            char buf[1024];\
            sprintf(buf, __VA_ARGS__);\
            Logger::getLogger()->log(buf, Error);}

#define LOG_RECORD(...) {\
            char buf[1024];\
            sprintf(buf, __VA_ARGS__);\
            Logger::getLogger()->log(buf, Record);}

// If you are using multiple modules, make sure to define both the port
// number and the module. For example you with a rangefinder:
//const int RANGE_FINDER_PORT = 1;
//const int RANGE_FINDER_MODULE = 1;

#endif
