#include "../../inc/Server.hpp"

void Server::kick(Client &client){
	std::cout << "KICK FUNC" << '\n';
	for (int i = 0; i < client.channels.size(); i++){
		std::string msg;
		msg = getprefix(client);
		msg += ' ' + cmd[0] + ' ' + cmd[1] + ' ' + cmd[2] + " :" + cmd[3] + '\n';
		std::cout << "KICK" << '\n';
		std::cout << "if  ustu" << client.channels[i].chnclients.size() << '\n';
		std::cout << client.channels[i]._chname << '\n';
		std::cout << cmd[1] << '\n';
		if (strncmp(client.channels[i]._chname.c_str(), cmd[1].c_str(), client.channels[i]._chname.length())){
			std::cout << "ilk if" << '\n';
			if (client.channels[i]._admin == client._nick){
				std::cout << "iki if" << '\n';
				for (int a = 0; a < client.channels[i].chnclients.size(); a++)
					send(client.channels[i].chnclients[a].fd, msg.c_str(), msg.length(), 0);
				for (int j = 0; j < client.channels[i].chnclients.size(); j++){
						std::cout << "ilk for" << '\n';
					if (strncmp(client.channels[i].chnclients[j]._nick.c_str(), cmd[2].c_str(), client.channels[i].chnclients[j]._nick.length())){
						std::cout << "uc if" << '\n';
						std::cout << client.channels[i].chnclients[j + 1]._nick << '\n';
						client.channels[i].chnclients.erase(client.channels[i].chnclients.begin() + j);
						std::cout << client.channels[i].chnclients[j + 1]._nick << '\n';
					}
				}
			}
		}
	}
}
