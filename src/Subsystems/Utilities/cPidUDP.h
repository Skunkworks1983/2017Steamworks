#pragma once

#include <PIDSource.h>
#include <Services/cMessenger.h>

class cPidUDP : public frc::PIDSource
{
public:
	cPidUDP();
	double PIDGet();
	void SetPIDSourceType(frc::PIDSourceType);
private:
	iMessenger* messenger;
};
