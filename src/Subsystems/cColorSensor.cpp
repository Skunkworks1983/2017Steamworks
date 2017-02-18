#include "cColorSensor.h"
#include "../RobotMap.h"

cColorSensor::cColorSensor() {
	colorSensor = new I2C(I2C::kOnboard, DEVICE_ADDR);
	//colorSensor->Write(0x00, 3);
	colorSensor->Write(0x80, 4);
}

double cColorSensor::get() {
	bool worked;
	byte buff[TO_READ];
	std::cout << "Before Read" << std::endl;
	worked = colorSensor->Read(0x12, TO_READ, buff);
	std::cout << "After Read" << std::endl;
	std::cout << "Buff: " << buff << ", worked: " << worked << std::endl;
	printf("Buff: %x, worked: %d", buff[0], worked);
}
