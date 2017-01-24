#include "Messenger.h"

Messenger::Messenger(char *server, char *port) {
	struct addrinfo hints;
	int addrinfo_stat;

	memset((char*) &hints, 0, sizeof(hints));
	hints.ai_socktype = SOCK_DGRAM;
	hints.ai_family = AF_UNSPEC;
	hints.ai_flags = AI_NUMERICSERV;
	hints.ai_protocol = 0;

	if((addrinfo_stat = getaddrinfo(server, port, &hints, &info)) != 0) {
	    std::cout << "couldn't get address info\n";
	    return;
	}

	if((sock = socket(info->ai_family, info->ai_socktype, info->ai_protocol)) == -1) {
		std::cout << "couldn't open socket\n";
	    return;
	}
}


Messenger::~Messenger() {
	delete &sock;
	delete info;
}


void Messenger::SendMessage(std::string message) {
    if(sendto(sock, message.c_str(), message.size(), 0, info->ai_addr, info->ai_addrlen) == -1) {
    	std::cout << "sendto failed\n";
    }
}
