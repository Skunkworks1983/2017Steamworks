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

#define RPI_IP "10.19.83.100"
#define RPI_PORT "8888"

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

const int DRIVEBASE_FOOT_PER_TICK = 0.0025;

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
