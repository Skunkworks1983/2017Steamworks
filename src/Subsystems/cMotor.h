/*
 * cMotor.h
 *
 *  Created on: Jan 17, 2017
 *      Author: s-4036956
 */

#ifndef SRC_SUBSYSTEMS_CMOTOR_H_
#define SRC_SUBSYSTEMS_CMOTOR_H_      //in general use more new lines and remove extraneous ones
#include <CANTalon.h>
class cMotor: public PIDSource, public PIDOutput {
private:
	CANTalon m_motor;
public:
	cMotor(int port);
	virtual ~cMotor();
	bool setBrakeMode(bool brake);
	void setOutput(float output);
	void PIDWrite(float output) override;
	double PIDGet() override;

//too much white space

};


#endif /* SRC_SUBSYSTEMS_CMOTOR_H_ */
