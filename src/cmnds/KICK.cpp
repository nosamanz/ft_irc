#include "../../inc/Server.hpp"

void Server::kick(Client &client){
	std::cout << "KICK FUNC" << '\n';
	for (int i = 0; i < client.channels.size(); i++){
			std::string msg;

			msg = getprefix(client);
			msg += ' ' + cmd[0] + ' ' + cmd[1] + ' ' + cmd[2] + " :" + cmd[3] + '\n';
			std::cout << "KICK" << '\n';
			std::cout << "if  ustu" << client.channels[i].chnclients.size() << '\n';
			if (client.channels[i]._chname == cmd[1]){
				if (client.channels[i]._admin == client._nick){
					send(client.fd, msg.c_str(), msg.length(), 0);
					for (int j = 0; j < client.channels[i].chnclients.size(); j++){
						if (client.channels[i].chnclients[j]._nick == cmd[2]){
							client.channels.erase(client.channels.begin() + j);
						}
					}
				}
			}
		}
}
