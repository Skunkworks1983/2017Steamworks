#ifndef ROBOTMAP_H
#define ROBOTMAP_H

#include "WPILib.h"
#include <Services/cLogger.h>
#include <math.h>

const std::string ROBOT_NAME = "tim_scoot";
const std::string LOGFILE_NAME = "robotLog";

// // ROBOT SETTINGS // //

//|||||||||||||||||||||||||||||||||||||||||||
//#define PRACTICE_BOT //COMMENT OUT IF ITS NOT PRACTICE BOT
//|||||||||||||||||||||||||||||||||||||||||||

// // MESSENGER // //

const char* const BOILER_PI_IP = "10.19.83.7";
const char* const BOILER_PI_PORT = "5802";

const int BOILER_PI_ID = 1;

const char* const GEAR_PI_IP = "10.19.83.6";
const char* const GEAR_PI_PORT = "5800";

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
const int DRIVEBASE_LEFTMOTOR_3_PORT = 12; //Front
const int DRIVEBASE_RIGHTMOTOR_1_PORT = 13; //Read
const int DRIVEBASE_RIGHTMOTOR_2_PORT = 14; //Middle
const int DRIVEBASE_RIGHTMOTOR_3_PORT = 15; //Front

const float SIMPLEDRIVEFORWARD_PID_P = 1. / 3000;
const float SIMPLEDRIVEFORWARD_PID_I = 0;
const float SIMPLEDRIVEFORWARD_PID_D = 0;
const float SIMPLEDRIVEFORWARD_PID_F = 0.1 / 3000;

const float TURNDEGREE_PID_P = 1;
const float TURNDEGREE_PID_I = 1;
const float TURNDEGREE_PID_D = 1;

const float TURNANGLE_ANGLE_OK_RANGE = 3; // +/- value
const float TURNANGLE_ANGLE_OK_TIMEOUT = 0.25; // cycles that we kill the command after if the gyro angle is in the range for this amount of time

const float TURNANGLE_TARGET_ANGLE = 71;
const float TURNANGLE_ABSTOLERANCE_ANGLE = .01;

// // OI // //

// // test

const int OI_UNJAM_BUTTON = 6;

// // test

const int OI_JOYSTICK_LEFT_PORT = 0;
const int OI_JOYSTICK_RIGHT_PORT = 1;

const int OI_JOYSTICK_OPERATOR_PORT = 2;

const int OI_JOYSTICK_ASSIGN_LIFT_MIDDLE = 2345;
const int OI_JOYSTICK_ASSIGN_LIFT_CLOSE = 15;
const int OI_JOYSTICK_ASSIGN_HOPPER_CLOSE = 100;

const int OI_JOYSTICK_ACQUIREBALL_BUTTON = 1;
const int OI_JOYSTICK_COLLECTORPOSUP = 2;
const int OI_JOYSTICK_COLLECTORPOSDOWN = 16;
const int OI_JOYSTICK_ACQUIREGEAR_BUTTON = 3;
//cont in *turtles*
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

const int FLOORCOLLECTOR_MIN_ENC_ANGLE = 100;
const int FLOORCOLLECTOR_MAX_ENC_ANGLE = -1500;

// // FUEL INDEXER // //
const int FUELLOADER_MOTOR1_PORT = 6;

const int FUELINDEXER_MOTOR1_PORT = 5;
const float FUELINDEXER_MOTOR1_SPEED = -1;

// // FUEL AGITATOR // //

const int FUELAGITATOR_MOTOR1_PORT = 9;
const float FUELAGITATOR_MOTOR1_SPEED = 1;

// // FUEL CONVEYOR // //

const int FUELCONVEYOR_MOTOR1_PORT = 4;
const float FUELCONVEYOR_MOTOR1_SPEED = 0.75;

// // TURRETLES  //  //

const int TURRET_SWEEP_RANGE = -5050; // ticks. also 180 degrees
//top kek
const int TURRET_SETPOINT_LIFT_MIDDLE = -860; // angle our turret needs to be to aim at the boiler from the middle lift
const int TURRET_SETPOINT_LIFT_CLOSE = -2880; // angle our turret needs to be to aim at the boiler from the lift closest to the boiler
const int TURRET_SETPOINT_HOPPER_CLOSE = (TURRET_SWEEP_RANGE / 2) - 100; // angle our turret needs to be to aim at the boiler from the hopper position

const int TURRET_MOTOR1_PORT = 7;

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

const float TURRET_MOTOR1_TICKS_PER_ROT = 12;
const float TURRET_MOTOR1_GEARING = 40;

// // SHOOTER // //

const int SHOOTER_MOTOR1_PORT = 2;
const int SHOOTER_MOTOR2_PORT = 3;

const double SHOOTER_TARGET_SPEED = -165; //based on GetSpeed()

const double SHOOTER_P = 500;
const double SHOOTER_I = 0;
const double SHOOTER_D = 0;
const double SHOOTER_F = 0;

const int RAMPING_CONSTANT = 5;

const float SHOOTER_SPEED_TOLERANCE = 0.1; // percent of setpoint

const int AUTO_TOGGLE_POS = 6; //or 7
const int AUTO_TOGGLE_ALLIANCE = 7; //or 6

const float SHOOTER_MOTOR_GEAR_TEETH = 24.0;
const float SHOOTER_WHEEL_GEAR_TEETH = 18.0;
const float SHOOTER_MOTOR_GEARING = 3.0;

const float SHOOTER_ENCODER_TICKS_PER_REVOLUTION = 256.0 / 4.0;

const float TICKS_TO_WHEEL_REVOLUTIONS = (SHOOTER_MOTOR_GEAR_TEETH / SHOOTER_WHEEL_GEAR_TEETH) * SHOOTER_ENCODER_TICKS_PER_REVOLUTION; // (G2/G1) * E

// // GEAR COLLECTOR // //

const int GEARCOLLECTOR_SERVO1_PORT = 0;
const int GEARCOLLECTOR_SERVO2_PORT = 1;

const int GEARCOLLECTOR_SERVO_MIN = 0;
const int GEARCOLLECTOR_SERVO_MAX = 170;

const int GEARCOLLECTOR_OPEN_ANGLE = 170; // ANGLE OF THE SERVOS! NOT FLAP!
const int GEARCOLLECTOR_CLOSE_ANGLE = 85; //0.5 * (GEARCOLLECTOR_SERVO_MIN + GEARCOLLECTOR_SERVO_MAX);

const float BANEBOTS775_STALLING_CURRENT = 80;
const float NEVEREST40_STALLING_CURRENT = 11.5;
const float CIM_STALLING_CURRENT = 80;

// // RASPBERRY PI // //

const int BOILER_PI_CAMERA_FOV = 53.5;

// // // // // AUTO // // // // //

enum eAlliance
{
    RED, BLUE, INVALID
};

enum eStartingPosition
{
    POS_BOILER, POS_CENTER, POS_RETRIEVAL, POS_HOPPER
};

// close/middle refers to the distance to the boiler, not the loading station
enum eShootingPosition
{
    LIFT_MIDDLE, LIFT_CLOSE, HOPPER_CLOSE
};

const int POS_SELECTION_PORT1 = 6;
const int POS_SELECTION_PORT2 = 7;

const bool USE_SHOOTER = false;
const bool USE_TURRET = true;
const bool USE_COLOR_SENSOR = true;
const bool USE_SONAR_SENSOR = true;
const bool USE_CAMERA = true;
const bool USE_GYRO = true;

const int AUTO_MOVE_FORWARD_FEET = 3; //lmao what
const int AUTO_TURN_DEGREES = 45; //assuming we are at lift 1

//COLOR SENSOR
//datasheet: https://cdn-shop.adafruit.com/datasheets/TCS34725.pdf
const u_int8_t COLOR_SENSOR_I2C_SLAVE_ADR = 0x29;
const u_int8_t COLOR_SENSOR_C_HIGH_REG = 0x15; //apparently the high value of each registry is the accurate one.
const u_int8_t COLOR_SENSOR_R_HIGH_REG = 0x17;
const u_int8_t COLOR_SENSOR_G_HIGH_REG = 0x19;
const u_int8_t COLOR_SENSOR_B_HIGH_REG = 0x1B;
const int COLOR_SENSOR_BYTE_LENGTH = 2;
const int I2C_CHANNEL = 1234;
const int FLOOR_TAPE_R_LOW = 1234; //these are found experimentally, unfortunately. TODO
const int FLOOR_TAPE_R_HIGH = 1234; //and they will vary TODO
const int FLOOR_TAPE_G_LOW = 1234; //TODO
const int FLOOR_TAPE_G_HIGH = 1234; //TODO
const int FLOOR_TAPE_B_LOW = 1234; //TODO
const int FLOOR_TAPE_B_HIGH = 1234; //TODO

//SONAR
//datasheet: http://www.maxbotix.com/documents/LV-MaxSonar-EZ_Datasheet.pdf
//you know what's annoying? eclipse literally does not allow you to save files that have emoji in them
//insert hammer and sickle emoji here
const int SONAR_INPUT_RIGHT = 0;
const int SONAR_INPUT_LEFT = 1;
const int SONAR_POWER_LEFT = 8;
const int SONAR_POWER_RIGHT = 9;
const float RATIO_OUTPUT_TO_FEET = .11; //this is kinda sketchy; i want better/more data

//SPECIFICALLY GEAR PLACEMENT THINGS

const float DISTANCE_BETWEEN_SONAR = (21 / 12); //inches to feet
const float angleWallTapePivotPoint = 1.1576; //rads (66.32 degrees) Keep in mind that the pivot point is an arbitrary point. All numbers that have to do with it are subject to change.
const float DISTANCE_FROM_TAPE_TO_PIVOT_POINT = (10.5 / 12); //inches to feet
const float angleGoalPivotPointTape = .4131; //rads (23.67 degrees)
const float DISTANCE_FROM_PIVOT_POINT_TO_GOAL = 2; //feet. This is to give some safe space to turn

const double TICK_INCH_RATIO = (7250 / 114);
const double BOILER_START_FIRST_ANGLE = 60; //deg
const double BOILER_START_DRIVE_DISTANCE = 7225 + (7250. / 114 * 4); //feet
const double RETRIEVAL_START_FIRST_ANGLE = 6; //deg
const double RETRIEVAL_START_SECOND_ANGLE = 54; //deg
const double RETRIEVAL_START_DRIVE_DISTANCE = -106.5 * TICK_INCH_RATIO; //115 inches, converted to feet, converted to ticks
const double DISTANCE_WALL_TO_BASE_LINE = 114 * TICK_INCH_RATIO; // 114 inches
const double DISTANCE_BASE_LINE_TO_PEG = 36 * TICK_INCH_RATIO; // ever so slightly less than 3 feet
const double angleInfinityBaseLinePeg = 60; //we're turning relative to a hexagon. having a good time.

const float ANGLE_OK_ERROR = 0.5; //Offset from finalangle that currentangle that it will end the command
const int ENCODER_OK_ERROR = 25; //Encoder offset from ^^

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

/*
 * this function takes in a number of ticks
 * and spits out an rpm for the flywheel.
 * we're expecting ticks per one tenth of a second
 */

inline float shooter_ticks_to_rpm(float ticks)
{
    // setspeed is based on 10ms.
    // getspeed is based on 100ms.
    // thanks, whoever made the talon libraries.
    return ((ticks * 10) * 60) / TICKS_TO_WHEEL_REVOLUTIONS; //getspeed() on talon will return ticks per tenth of a second. multiply by 10 to get rots per sec, multiply by 60 to get rots per min
}

/*
 * this function takes in a rpm
 * and spits out a value for ticks for the flywheel.
 * we're expecting ticks per one tenth of a second
 */

inline float shooter_rpm_to_ticks(float rpm)
{
    return ((rpm * TICKS_TO_WHEEL_REVOLUTIONS) / 60);
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
