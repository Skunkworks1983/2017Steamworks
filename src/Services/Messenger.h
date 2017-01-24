#ifndef MESSENGER_H
#define MESSENGER_H

#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <string.h>

#define IP "10.76.5.17"
#define PORT "8888"

class Messenger {
	private:
		int sock;
		addrinfo* info;

	public:
		Messenger(char* server, char* port);
		~Messenger();

		void SendMessage(std::string message);
};

#endif
