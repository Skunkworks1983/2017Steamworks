#ifndef ROBOTMAP_H
#define ROBOTMAP_H

#include "WPILib.h"
#include <Services/cLogger.h>
#include <math.h>

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
const char* const ROBOT_NAME = "tim scoot";
const char* const LOGFILE_NAME = "/U/robotLog";

enum FuelCollectorPosition
{
    UP = 90, DOWN = 0
};

#define BOILER_PI_IP "10.19.83.6"
#define BOILER_PI_PORT "5802"

const int BOILER_PI_ID = 1;

#define GEAR_PI_IP "10.19.83.7"
#define GEAR_PI_PORT "5800"

const int GEAR_PI_ID = 0;

const int MSG_LEN = 1024;

const int DRIVEBASE_LEFT_DIRECTION = -1;
const int DRIVEBASE_RIGHT_DIRECTION = 1;

//LEFT: R and F are switched
//RIGHT:

//11 climber: backwards is forwards
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
const int OI_JOYSTICK_TURRET_CONTROL = 10000;
const int OI_JOYSTICK_SHOOTER_CONTROL = 10000;

const int MANUAL_TURRET_CONTROL_SCALAR = 0.5;
const int OI_TURRET_SLIDER_RANGE = 100;

const int MANUAL_SHOOTER_CONTROL_SCALAR = 1;
const int OI_SHOOTER_SLIDER_RANGE = 100;

const float DRIVEBASE_FOOT_PER_TICK = 0.0025;

const float SIMPLEDRIVEFORWARD_PID_P = 1;
const float SIMPLEDRIVEFORWARD_PID_I = 1;
const float SIMPLEDRIVEFORWARD_PID_D = 1;

const float TURNDEGREE_PID_P = 1;
const float TURNDEGREE_PID_I = 1;
const float TURNDEGREE_PID_D = 1;

const int CLIMBER_MOTOR1_PORT = 10000;
const int CLIMBER_MOTOR2_PORT = 10000;

const float CLIMBER_MOTOR_DIRECTION = 1;

const int FUELCOLLECTOR_MOTOR1_PORT = 10000;
const int FUELCOLLECTOR_MOTOR2_PORT = 10000;

const int FUELCOLLECTOR_COMMAND_TIME_ON = 5;

const int FUELLOADER_MOTOR1_PORT = 10000;

const int FUELLOADER_COMMAND_TIME_ON = 5;

const int TURRET_MOTOR1_PORT = 10000;

const int TURRET_MOTOR1_P = 1;
const int TURRET_MOTOR1_I = 0;
const int TURRET_MOTOR1_D = 0;

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

const float BANEBOTS775_STALLING_CURRENT = 130;
const float NEVEREST40_STALLING_CURRENT = 11.5;
const float CIM_STALLING_CURRENT = 133;

const float TURNANGLE_TARGET_ANGLE = 71;
const float TURNANGLE_ABSTOLERANCE_ANGLE = .01;

//AUTONOMOUS THINGS

enum eStartingPosition
{
    POS_1, POS_2, POS_3
};

const bool USE_SHOOTER = true;
const bool USE_TURRET = true;
const bool USE_COLOR_SENSOR = true;
const bool USE_SONAR_SENSOR = true;
const bool USE_CAMERA = true;

const int AUTO_MOVE_FORWARD_FEET = 3;
const int AUTO_TURN_DEGREES = 45; //assuming we are at lift 1

//COLOR SENSOR
//datasheet: https://cdn-shop.adafruit.com/datasheets/TCS34725.pdf
const int COLOR_SENSOR_I2C_SLAVE_ADR = 0x29;
const int COLOR_SENSOR_R_HIGH_REG = 0x17; //apparently the high value of each registry is the accurate one.
const int COLOR_SENSOR_G_HIGH_REG = 0x19;
const int COLOR_SENSOR_B_HIGH_REG = 0x1B;
const unsigned int COLOR_SENSOR_BYTE_LENGTH = 2;
const int I2C_CHANNEL = 1234;
const int FLOOR_TAPE_R = 1234; //these are found experimentally, unfortunately.
const int FLOOR_TAPE_G = 1234; //ibid
const int FLOOR_TAPE_B = 1234; //hebids

//SPECIFICALLY GEAR PLACEMENT THINGS

// positions start from the top of the field moving down

/*
 * boiler           boiler
 *
 * red________________blue
 *   |1               |
 *   |      1 /       |
 *   |2    2 |        |
 *   |      3 \       |
 *   |3_______________|
 */

const float ARM_ANGLE = ((70 * 3.14) / 180); // Angle of the arms surrounding the hook from the wall. Radians. Placeholder.
const float DISTANCE_TO_RECOVERY_POINT = 5; //placeholder! In feet, apparently (though that's super dumb)
/* the commented out values below are so because they pertain to the path if the robot is outside of the arms, an unlikely scenario.
 #define anglePerpindicularGoalRecoveryPoint ((70*3.14)/180) // same! radians
 #define anglePerpindicularGoalPivotPoint ((70*3.14)/180) //marcador de posicion
 #define DISTANCE_FROM_REC_POINT_TO_PIVOT_POINT 10 //same! feet
 #define anglePivotPointRecoveryPointGoal ((30*3.14)/180) //placeholder radians
 */
const float angleWallTapePivotPoint = ((100 * 3.14) / 180); //can you guess what im going to say here?
const float DISTANCE_FROM_TAPE_TO_PIVOT_POINT = 1.5; // ibid.
const float angleGoalPivotPointTape = ((45 * 3.14) / 180); // surrogate for a real value
const float DISTANCE_FROM_PIVOT_POINT_TO_GOAL = 1234; //listen, i'm not an expert, but I'm almost certain that the distance from the pivot point to the goal will not be 1234 feet

#define LOG_DEBUG(...) {\
            char buf[1024];\
            sprintf(buf, __VA_ARGS__);\
            Logger::getLogger()->log(buf, LogDebug);}

#define LOG_INFO(...) {\
            char buf[1024];\
            sprintf(buf, __VA_ARGS__);\
            Logger::getLogger()->log(buf, LogInfo);}

#define LOG_WARNING(...) {\
            char buf[1024];\
            sprintf(buf, __VA_ARGS__);\
            Logger::getLogger()->log(buf, LogWarning);}

#define LOG_ERROR(...) {\
            char buf[1024];\
            sprintf(buf, __VA_ARGS__);\
            Logger::getLogger()->log(buf, LogError);}

#define LOG_RECORD(...) {\
            char buf[1024];\
            sprintf(buf, __VA_ARGS__);\
            Logger::getLogger()->log(buf, Record);}

const float WHEEL_CIRCUMFERENCE = (4*M_PI)/12; //Feet
const int TICKS_PER_REVOLUTION = 4020;

// If you are using multiple modules, make sure to define both the port
// number and the module. For example you with a rangefinder:
//const int RANGE_FINDER_PORT = 1;
//const int RANGE_FINDER_MODULE = 1;

#endif
