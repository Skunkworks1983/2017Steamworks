#ifndef ROBOTMAP_H
#define ROBOTMAP_H

#include "WPILib.h"
#include <Services/cLogger.h>

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

const int DEBUG = 1;

const char* const ROBOT_NAME = "tim scoot";
const char* const LOGFILE_NAME = "/U/robotLog";

enum FuelCollectorPosition {
    UP = 90,
    DOWN = 0
};

const char* const BOILER_PI_IP = "10.19.83.237";
const char* const BOILER_PI_PORT = "5802";

const int BOILER_PI_ID = 0;

const char* const GEAR_PI_IP = "10.19.83.217";
const char* const GEAR_PI_PORT = "5800";

const int GEAR_PI_ID = 1;

const int MSG_LEN = 1024;

const int DRIVEBASE_LEFT_DIRECTION = -1;
const int DRIVEBASE_RIGHT_DIRECTION = 1;

const int DRIVEBASE_LEFTMOTOR_1_PORT = 0;
const int DRIVEBASE_LEFTMOTOR_2_PORT = 1;
const int DRIVEBASE_LEFTMOTOR_3_PORT = 2;
const int DRIVEBASE_RIGHTMOTOR_1_PORT = 15;
const int DRIVEBASE_RIGHTMOTOR_2_PORT = 14;
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

const float BANEBOTS775_STALLING_CURRENT = 130;
const float NEVEREST40_STALLING_CURRENT = 11.5;
const float CIM_STALLING_CURRENT = 133;

const float TURNANGLE_TARGET_ANGLE = 71;
const float TURNANGLE_ABSTOLERANCE_ANGLE = .01;

//AUTONOMOUS THINGS

//COLOR SENSOR
//datasheet: https://cdn-shop.adafruit.com/datasheets/TCS34725.pdf
#define COLOR_SENSOR_I2C_SLAVE_ADR 0x29
#define COLOR_SENSOR_R_HIGH_REG 0x17 //apparently the high value of each registry is the accurate one.
#define COLOR_SENSOR_G_HIGH_REG 0x19
#define COLOR_SENSOR_B_HIGH_REG 0x1B
#define COLOR_SENSOR_BYTE_LENGTH 2
#define I2C_CHANNEL 1234
#define FLOOR_TAPE_R_LOW 1234//these are found experimentally, unfortunately. TODO
#define FLOOR_TAPE_R_HIGH 1234 //and they will vary TODO
#define FLOOR_TAPE_G_LOW 1234//TODO
#define FLOOR_TAPE_G_HIGH 1234//TODO
#define FLOOR_TAPE_B_LOW 1234//TODO
#define FLOOR_TAPE_B_HIGH 1234//TODO

//SONAR
//this definitely has a datasheet somewhere
#define R_SONAR_I2C_CHANNEL 0x1234 //TODO
#define L_SONAR_I2C_CHANNEL 0x1234 //TODO
#define SONAR_BYTE_LENGTH 1
#define SONAR_AN_REG 0x1234 //Pin 3. I think this will be the same on both? TODO

//SPECIFICALLY GEAR PLACEMENT THINGS

#define DISTANCE_BETWEEN_SONAR (22/12) //inches to feet TODO-I asked Davin and he said that the two front facing ones were the width of the drivebase apart, plus 2 inch. Is this right? Idk.
#define angleWallTapePivotPoint 1.1576 //rads (66.32 degrees) Keep in mind that the pivot point is an arbitrary point. All numbers that have to do with it are subject to change.
#define DISTANCE_FROM_TAPE_TO_PIVOT_POINT (10.5/12) //inches to feet
#define angleGoalPivotPointTape .4131 //rads (23.67 degrees)
#define DISTANCE_FROM_PIVOT_POINT_TO_GOAL 2 //feet. This is to give some safe space to turn

//END AUTONOMOUS THINGS

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
