#include "../../inc/Server.hpp"

void Server::privmsg(Client &client)
{
	std::cout << "PRIVMSG FONKSIYONU" << '\n';
	std::string dest = cmd[1];
	std::string msg = getprefix(client);
	msg += ' ' + cmd[0] + ' ' + cmd[1] + ' ';
	for (unsigned long int l = 2; l < cmd.size(); l++){
		msg = msg + cmd[l];
		msg = msg + ' ';
	}
	msg += '\n';
	std::cout << msg << '\n';
	bool inch = 0;
	if (cmd[1][0] == '#'){
		for (unsigned long int j = 0; j < channels.size(); j++){
			std::string temp = channels[j]._chname;
			if (!strncmp(dest.c_str(), temp.c_str(), strlen(dest.c_str()))){
				if (channels[j].ifn){
					for(unsigned long int l = 0; l < channels[j].chnclients.size(); l++){
						if (channels[j].chnclients[l]._nick == client._nick)
							inch = 1;
					}
					if (inch){
						for (int k = 0; k < channels[j]._clientnum; k++){
							if (channels[j].chnclients[k]._nick != client._nick)
								send(channels[j].chnclients[k].fd, msg.c_str(), msg.length(), 0);
						}
					}
					else{
						std::cout << "CLIENT NOT IN THE SERVER CLIENT LIST !!!!!!" << '\n';
						msg.clear();
						msg = "ERROR! You're not on that channel\n";
						send(client.fd, msg.c_str(), msg.length(), 0);
						msg.clear();
					}
					return;
				}
				else{
					for (int k = 0; k < channels[j]._clientnum; k++){
						if (channels[j].chnclients[k]._nick != client._nick)
							send(channels[j].chnclients[k].fd, msg.c_str(), msg.length(), 0);
					}
				}
			}
		}
	}
	else{
		for (unsigned long int k = 0; k < clients.size() ; k++){
			std::cout << msg << '\n';
			if (!strncmp(dest.c_str(), (clients[k]._nick).c_str(), strlen(dest.c_str()))){
				send(clients[k].fd , msg.c_str(), msg.length(), 0);
				return;
			}
		}
		return;
	}
}
