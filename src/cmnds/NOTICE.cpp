#include "../../inc/Server.hpp"

void Server::notice(Client &client){
	std::cout << "NOTICE FONKSIYONU\n";
	std::string msg = getprefix(client);
	std::string dest = cmd[1];
	msg += ' ' + cmd[0] + ' ' + cmd[1] + ' ';
	for (unsigned long int l = 2; l < cmd.size(); l++){
		msg = msg + cmd[l];
		msg = msg + ' ';
	}
	msg += '\n';
	for (unsigned long int k = 0; k < clients.size() ; k++){
		if (!strncmp(dest.c_str(), (clients[k]._nick).c_str(), strlen(dest.c_str()))){
			send(clients[k].fd , msg.c_str(), msg.length(), 0);
			return;
		}
	}
}
