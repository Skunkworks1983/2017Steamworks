/*
 * cPidSonars.h
 *
 *  Created on: Feb 28, 2017
 *      Author: s-2508657
 */

#ifndef SRC_SUBSYSTEMS_UTILITIES_CPIDSONARS_H_
#define SRC_SUBSYSTEMS_UTILITIES_CPIDSONARS_H_

#include <WPILib.h>
#include <PIDSource.h>
#include <CommandBase.h>

class cPidSonars: public frc::PIDSource {
private:
	double m_storedLeft;
	double m_storedRight;

	bool turn; //who's line is it anyways? arbitrary
public:
	cPidSonars();
	virtual ~cPidSonars();

	double PIDGet();

};

#endif /* SRC_SUBSYSTEMS_UTILITIES_CPIDSONARS_H_ */
