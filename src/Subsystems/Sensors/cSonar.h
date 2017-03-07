/*
 * cSonar.h
 *
 *  Created on: Feb 26, 2017
 *      Author: s-2508657
 */

#ifndef SRC_SUBSYSTEMS_SENSORS_CSONAR_H_
#define SRC_SUBSYSTEMS_SENSORS_CSONAR_H_

#include <vector>
#include <AnalogInput.h>
#include <DigitalOutput.h>
#include <RobotMap.h>

class cSonar {
private:
	const int MAX_STORED_POINTS = 10;
	std::vector<double> m_values;
	int m_index = 0;

	AnalogInput* m_sonar_input;
	DigitalOutput* m_sonar_power;
public:
	cSonar(int input_port, int power_port);
	virtual ~cSonar();
	double getValue();
};

#endif /* SRC_SUBSYSTEMS_SENSORS_CSONAR_H_ */
