#include "./cPidUDP.h"
#include <string>
#include "../Services/cMessenger.h"

#define RPI_IP "10.19.83.217"
#define RPI_PORT "8888"

cPidUDP::cPidUDP()
{
	messenger = new cMessenger(RPI_IP, RPI_PORT);
}

double cPidUDP::PIDGet()
{
	cMessage* message;
	message = messenger->ReceiveMessage();
	return std::stod(message->GetMessage());
}

void cPidUDP::SetPIDSourceType(frc::PIDSourceType sourceType) {

}
