#pragma once

#include <PIDOutput.h>

class cPIDOutputContainer : public frc::PIDOutput {
public:
	cPIDOutputContainer();
	~cPIDOutputContainer();
	void PIDWrite(double);
	double getVal();
private:
	double m_value;
};
