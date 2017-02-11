#include "./cPidUDP.h"
#include <string>
#include "../Services/cMessenger.h"
#include <CommandBase.h>
#include <string>

cPidUDP::cPidUDP()
{
	messenger = CommandBase::s_messenger;
}

double cPidUDP::PIDGet()
{
	cBoilerData* message = messenger->receiveBoilerData();

	double targetPos = message->getX();
	std::cout << targetPos << "\n";
	return targetPos;
}

void cPidUDP::SetPIDSourceType(frc::PIDSourceType sourceType) {

}
