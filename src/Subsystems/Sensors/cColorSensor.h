#ifndef cColorSensor_H
#define cColorSensor_H

#include <I2C.h>
#include <stdio.h>

#define DEVICE_ADDR 0x08

#define READ_ADDR 0x80
#define TO_READ 6
#define REGISTER 0x12

#define COMMAND READ_ADDR | REGISTER

typedef unsigned char byte;

class cColorSensor {
private:
	I2C* colorSensor;

public:
	cColorSensor();

	double get();
};

#endif  // cColorSensor_H
