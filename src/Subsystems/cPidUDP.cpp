#include "./cPidUDP.h"
#include <string>
#include "../Services/cMessenger.h"
#include <CommandBase.h>

cPidUDP::cPidUDP()
{
	messenger = CommandBase::s_messenger;
}

double cPidUDP::PIDGet()
{
	cMessage* message;
	message = messenger->ReceiveMessage();
	return std::stod(message->GetMessage());
}

void cPidUDP::SetPIDSourceType(frc::PIDSourceType sourceType) {

}
