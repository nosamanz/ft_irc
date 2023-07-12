#include "../../inc/Server.hpp"

void Server::privmsg(int index)
{
	std::cout << "PRIVMSG FONKSIYONU" << '\n';
	std::string dest = cmd[1];
	int i = 0;

	// std::cout << dest << " " <<  clients[i]._nick << '\n';
	std::string msg = getprefix(index);
	msg += ' ' + cmd[0] + ' ' + cmd[1] + ' ';
	for (int l = 2; l < cmd.size(); l++){
		msg = msg + cmd[l];
		msg = msg + ' ';
	}
	msg += '\n';
	std::cout << msg << '\n';
	if (cmd[1][0] == '#'){
		for (int j = 0; j < channels.size(); j++)
		{
			std::string temp = channels[j]._chname;
			if (!strncmp(dest.c_str(), temp.c_str(), strlen(dest.c_str())))
			{
				for (int k = 0; k < channels[j]._clientnum; k++)
				{
					if (channels[j].chnclients[index]._nick != channels[j].chnclients[k]._nick)
						send(channels[j].chnclients[k].fd, msg.c_str(), msg.length(), 0);
				}
				return;
			}
		}
	}
	else{
		send(clients[i].fd, msg.c_str(), msg.length() + 1, 0);
		return;
	}
}