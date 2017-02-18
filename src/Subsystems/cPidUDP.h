#pragma once

#include <PIDSource.h>
class cMessenger;

class cPidUDP : public frc::PIDSource
{
public:
	cPidUDP();
	double PIDGet();
	void SetPIDSourceType(frc::PIDSourceType);
private:
	cMessenger* messenger;
};
