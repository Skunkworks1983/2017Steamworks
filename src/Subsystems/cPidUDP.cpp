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
	cMessage* message;
	message = messenger->receiveMessage();

	double targetPos = 0;
	std::string messageContent = message->GetMessage();
	try {
		targetPos = std::stod(messageContent);
		std::cout << messageContent << std::endl;
	} catch(...) {
		std::cout << "Yea nope" << std::endl;
	}
	return targetPos;
}

void cPidUDP::SetPIDSourceType(frc::PIDSourceType sourceType) {

}
