/*
 * cSonar.cpp
 *
 *  Created on: Feb 26, 2017
 *      Author: s-2508657
 */
#include <Subsystems/Sensors/cSonar.h>
#include <unistd.h>

cSonar::cSonar(int input_port, int power_port) {
	m_index = 0;
	m_sonar_input = new AnalogInput(input_port);
	m_sonar_power = new DigitalOutput(power_port);
}

cSonar::~cSonar() {

}

double cSonar::getValue() {
	m_sonar_power->Set(true);
	usleep(20);
	m_index += 1;
	if(m_index >= MAX_STORED_POINTS) {
		m_index = 0;
	}
	double cur_voltage = m_sonar_input->GetVoltage();
	if(m_values.size() < MAX_STORED_POINTS) {
		m_values.push_back(cur_voltage);
	} else {
		m_values[m_index] = cur_voltage;
	}
	double total = 0;
	for(int i = 0; i < m_values.size(); i++) {
		total += m_values[i];
	}
	return total/m_values.size();
	m_sonar_power->Set(false);
}
