#ifndef ROBOTMAP_H
#define ROBOTMAP_H

#include "WPILib.h"
#include <Services/cLogger.h>
#include <math.h>

#define ROBOT_NAME "tim scoot"
#define LOGFILE_NAME "/U/robotLog"

// // MESSENGER // //

#define BOILER_PI_IP "10.19.83.7"
#define BOILER_PI_PORT "5802"

const int BOILER_PI_ID = 1;

#define GEAR_PI_IP "10.19.83.6"
#define GEAR_PI_PORT "5800"

const int GEAR_PI_ID = 0;

const int MSG_LEN = 1024;

const float MESSENGER_TIMEOUT_SECS = 1;


const int DRIVEBASE_LEFT_DIRECTION = 1;
const int DRIVEBASE_RIGHT_DIRECTION = -1;

const float DRIVEBASE_FOOT_PER_TICK = 0.0025;

//LEFT: R and F are switched
//RIGHT:

//11 climber: backwards is forwards
const int DRIVEBASE_LEFTMOTOR_1_PORT = 0; //Rear
const int DRIVEBASE_LEFTMOTOR_2_PORT = 1; //Middle
const int DRIVEBASE_LEFTMOTOR_3_PORT = 12;//Front
const int DRIVEBASE_RIGHTMOTOR_1_PORT = 13;//Read
const int DRIVEBASE_RIGHTMOTOR_2_PORT = 14;//Middle
const int DRIVEBASE_RIGHTMOTOR_3_PORT = 15;//Front

const float SIMPLEDRIVEFORWARD_PID_P = 1./3000;
const float SIMPLEDRIVEFORWARD_PID_I = 0;
const float SIMPLEDRIVEFORWARD_PID_D = 0;
const float SIMPLEDRIVEFORWARD_PID_F = 0.1/3000;

const float TURNDEGREE_PID_P = 1;
const float TURNDEGREE_PID_I = 1;
const float TURNDEGREE_PID_D = 1;

const float TURNANGLE_TARGET_ANGLE = 71;
const float TURNANGLE_ABSTOLERANCE_ANGLE = .01;

// // OI // //

const int OI_JOYSTICK_LEFT_PORT = 1;
const int OI_JOYSTICK_RIGHT_PORT = 0;

const int OI_JOYSTICK_OPERATOR_PORT = 2;

const int OI_JOYSTICK_ACQUIREBALL_BUTTON = 1;
const int OI_JOYSTICK_COLLECTORPOS = 2;
const int OI_JOYSTICK_ACQUIREGEAR_BUTTON = 3;
//const int OI_JOYSTICK_ASSIGNTARGETBOILER = 3; not yet used
const int OI_JOYSTICK_INDEXER_BUTTON = 4;
//const int OI_JOYSTICK_ASSIGNTARGETGOAL = 4;   not yet used
//const int OI_JOYSTICK_SHOOTHIGH = 5;          not yet used
const int OI_JOYSTICK_CONVEYOR_BUTTON = 5;
const int OI_JOYSTICK_CLIMBROPE = 6;
const int OI_JOYSTICK_TURRET_CONTROL = 7;
const int OI_JOYSTICK_SPINUPSHOOTER = 8;
const int OI_JOYSTICK_LOADBALL = 10;

const int OI_JOYSTICK_SWITCHBACKFRONT = 10;
const int OI_JOYSTICK_SHOOTER_CONTROL = 10000;

const int MANUAL_TURRET_CONTROL_SCALAR = 0.5;
const int OI_TURRET_SLIDER_RANGE = 100;

const int MANUAL_SHOOTER_CONTROL_SCALAR = 1;
const int OI_SHOOTER_SLIDER_RANGE = 100;

// // CLIMBER // //

const int CLIMBER_MOTOR1_PORT = 10;
const int CLIMBER_MOTOR2_PORT = 11;

const float CLIMBER_MOTOR_DIRECTION = 1;

const float ROPECLIMB_COMMAND_TIME_ON = 30;
const float ROPECLIMB_COMMAND_TIME_OFF = 1;
const int FUELCOLLECTOR_COLLECTOR_PORT = 6;
const int FUELCOLLECTOR_ANGLE_PORT = 8;

const int FUELCOLLECTOR_MIN_ENC_ANGLE = 10;
const int FUELCOLLECTOR_MAX_ENC_ANGLE = 247;

// // FUEL INDEXER // //
const int FUELLOADER_MOTOR1_PORT = 6;

const int FUELINDEXER_MOTOR1_PORT = 5;
const float FUELINDEXER_MOTOR1_SPEED = 1;

// // FUEL CONVEYOR // //

const int FUELCONVEYOR_MOTOR1_PORT = 4;
const float FUELCONVEYOR_MOTOR1_SPEED = 1;

// // TURRET // //

const int TURRET_MOTOR1_PORT = 7;
const int TURRET_MOTOR1_GEARING = 40;
const int TURRET_MOTOR1_TICKS_PER_ROT = 280;

const int TURRET_SEARCH_HEADING = -45; // for red

const int TURRET_SWEEP_RANGE = 180; // angle

const int TURRET_MOTOR1_P = 1;
const int TURRET_MOTOR1_I = 0;
const int TURRET_MOTOR1_D = 0;

const int TURRET_GEAR1_TEETH = 10; // small sprocket
const int TURRET_GEAR2_TEETH = 200; // large lazy susan

const int TURRET_MIN_ENC = -2500;
const int TURRET_MAX_ENC = 2500;

const float CROTATETURRET_LEFT_SPEED = .5;
const float CROTATETURRET_RIGHT_SPEED = -.5;

const float TURRET_SETPOINT_RANGE = 2500; // middle to far side (doesn't matter which)
const float TURRET_ANGLE_TOLERANCE = 0.05; // percent of setpoint

// // SHOOTER // //

const int SHOOTER_MOTOR1_PORT = 2;
const int SHOOTER_MOTOR2_PORT = 3;

const double SHOOTER_TARGET_SPEED = -165; //based on GetSpeed()

const double SHOOTER_P = 1;
const double SHOOTER_I = 0;
const double SHOOTER_D = 0;
const double SHOOTER_F = 0;

const int RAMPING_CONSTANT = 2;

const float SHOOTER_SPEED_TOLERANCE = 0.1; // percent of setpoint

const int AUTO_TOGGLE_POS = 6; //or 7
const int AUTO_TOGGLE_ALLIANCE = 7; //or 6

// // GEAR COLLECTOR // //

const int GEARCOLLECTOR_SERVO1_PORT = 0;
const int GEARCOLLECTOR_SERVO2_PORT = 1;

const int GEARCOLLECTOR_SERVO_MIN = 0;
const int GEARCOLLECTOR_SERVO_MAX = 170;

const int GEARCOLLECTOR_OPEN_ANGLE = 170; // ANGLE OF THE SERVOS! NOT FLAP!
const int GEARCOLLECTOR_CLOSE_ANGLE = 85; //0.5 * (GEARCOLLECTOR_SERVO_MIN + GEARCOLLECTOR_SERVO_MAX);

const float BANEBOTS775_STALLING_CURRENT = 130;
const float NEVEREST40_STALLING_CURRENT = 11.5;
const float CIM_STALLING_CURRENT = 133;

// // RASPBERRY PI // //

const int BOILER_PI_CAMERA_FOV = 53.5;

// // // // // AUTO // // // // //

enum eAlliance
{
    Red, Blue
};

enum eStartingPosition
{
    POS_1, POS_2, POS_3
};


const int START_POS_SELECTION_DIGITS = 3;
const int ALLIANCE_SELECTION_DIGITS = 1;

const bool USE_SHOOTER = true;
const bool USE_TURRET = true;
const bool USE_COLOR_SENSOR = true;
const bool USE_SONAR_SENSOR = true;
const bool USE_CAMERA = true;
const bool USE_GYRO = false; //TODO

const int AUTO_MOVE_FORWARD_FEET = 3;
const int AUTO_TURN_DEGREES = 45; //assuming we are at lift 1

//COLOR SENSOR
//datasheet: https://cdn-shop.adafruit.com/datasheets/TCS34725.pdf
#define COLOR_SENSOR_I2C_SLAVE_ADR 0x29
#define COLOR_SENSOR_C_HIGH_REG 0x15//apparently the high value of each registry is the accurate one.
#define COLOR_SENSOR_R_HIGH_REG 0x17
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
//datasheet: http://www.maxbotix.com/documents/LV-MaxSonar-EZ_Datasheet.pdf
//you know what's annoying? eclipse literally does not allow you to save files that have emoji in them
//insert hammer and sickle emoji here
const int SONAR_INPUT_RIGHT =  0;
const int SONAR_INPUT_LEFT = 1;
const int SONAR_POWER_LEFT = 8;
const int SONAR_POWER_RIGHT = 9;
#define RATIO_OUTPUT_TO_FEET .11 //this is kinda sketchy; i want better/more data

//SPECIFICALLY GEAR PLACEMENT THINGS

#define DISTANCE_BETWEEN_SONAR (21/12) //inches to feet
#define angleWallTapePivotPoint 1.1576 //rads (66.32 degrees) Keep in mind that the pivot point is an arbitrary point. All numbers that have to do with it are subject to change.
#define DISTANCE_FROM_TAPE_TO_PIVOT_POINT (10.5/12) //inches to feet
#define angleGoalPivotPointTape .4131 //rads (23.67 degrees)
#define DISTANCE_FROM_PIVOT_POINT_TO_GOAL 2 //feet. This is to give some safe space to turn

// positions start from the top of the field moving down

/*
 * red________________blue
 *   |1               |
 *   |      1 /       |
 *   |2    2 |        |
 *   |      3 \       |
 *   |3_______________|
 *
 *   boiler         boiler
 */

const float ARM_ANGLE = ((70 * 3.14) / 180); // Angle of the arms surrounding the hook from the wall. Radians. Placeholder.
const float DISTANCE_TO_RECOVERY_POINT = 5; //placeholder! In feet, apparently (though that's super dumb)

const float ANGLE_OK_ERROR = 0.5; //Offset from finalangle that currentangle that it will end the command
const int   ENCODER_OK_ERROR = 25; //Encoder offset from ^^

// // // // // UTILITIES // // // // //

/*
 * this function keeps a value within range,
 * given value, minimum, and maximum. if the
 * value is above maximum, the value will be
 * the maximum.
 */

inline float clamp(float value, float minimum, float maximum)
{
    return std::min(maximum, std::max(minimum, value));
}

/*
 * this function takes in a desired angle for the
 * entire turret. give this function an angle you
 * want the turret to face (-90 to 90), and it will
 * give you the number of rotations the turret motor needs
 * to turn.
 */

inline float turret_angle_to_ticks(float angle)
{
    float final = (angle / 360) * TURRET_MOTOR1_TICKS_PER_ROT;
    final *= TURRET_MOTOR1_GEARING;
    final *= TURRET_GEAR2_TEETH / TURRET_GEAR1_TEETH;
    return final;
}

/*
 * this function takes in a number of rotations of the
 * turret motor, and gives back the change in angle of
 * the entire turret.
 */

inline float turret_ticks_to_angle(float rots)
{
    float final = rots;
    final /= TURRET_GEAR2_TEETH / TURRET_GEAR1_TEETH;
    final /= TURRET_MOTOR1_GEARING;
    final /= TURRET_MOTOR1_TICKS_PER_ROT;
    final *= 360;
    return final;
}

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

const float WHEEL_CIRCUMFERENCE = (4 * M_PI) / 12; //Feet
const int TICKS_PER_REVOLUTION = 4020;

#endif
