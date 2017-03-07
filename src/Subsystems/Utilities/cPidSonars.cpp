/*
 * cPidSonars.cpp
 *
 *  Created on: Feb 28, 2017
 *      Author: s-2508657
 */

#include <Subsystems/Utilities/cPidSonars.h>
#include <utility.h>

cPidSonars::cPidSonars() {
	m_storedLeft = 0;
	m_storedRight = 0;

	turn = false;
}

cPidSonars::~cPidSonars() {

}

double cPidSonars::PIDGet() {
	if(turn) {
		m_storedLeft = CommandBase::s_drivebase->GetLeftDistance();
	} else {
		m_storedRight = CommandBase::s_drivebase->GetRightDistance();
	}

	turn = !turn;

	std::cout << m_storedLeft - m_storedRight << std::endl;

	return m_storedLeft - m_storedRight;
}
