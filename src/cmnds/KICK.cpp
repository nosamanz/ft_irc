#include "../../inc/Server.hpp"

void Server::kick(Client &client){
	std::cout << "KICK FUNC" << '\n';
	for (unsigned long int i = 0; i < channels.size(); i++){
		std::string msg;
		msg = getprefix(client);
		msg += ' ' + cmd[0] + ' ' + cmd[1] + ' ' + cmd[2] + " :" + cmd[3] + '\n';
		if (!strncmp(channels[i]._chname.c_str(), cmd[1].c_str(), cmd[1].length())){
			if (channels[i]._admin == client._nick){
				for (unsigned long int a = 0; a < channels[i].chnclients.size(); a++)
					send(channels[i].chnclients[a].fd, msg.c_str(), msg.length(), 0);
				for (unsigned long int j = 0; j < channels[i].chnclients.size(); j++){
					if (!strncmp(channels[i].chnclients[j]._nick.c_str(), cmd[2].c_str(), cmd[2].length())){
						channels[i].chnclients.erase(channels[i].chnclients.begin() + j);
						channels[i]._clientnum--;
					}
				}
			}
		}
	}
}
