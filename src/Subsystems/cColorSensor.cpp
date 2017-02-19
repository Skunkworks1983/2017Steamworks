#include "cColorSensor.h"
#include "../RobotMap.h"

cColorSensor::cColorSensor() {
	colorSensor = new I2C(I2C::kOnboard, DEVICE_ADDR);
}

double cColorSensor::get() {
	std::cout << "Whoop" << std::endl;
	bool worked;
	byte buff[TO_READ];
	unsigned char sendBuffer[] = {1, 2, 3, 4, 5, 6};
	//colorSensor->WriteBulk(&sendBuffer, 6);
	worked = colorSensor->ReadOnly(TO_READ, buff);
	printf("Buff: %x, worked: %d", buff, worked);
}
