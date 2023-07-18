#include "../../inc/Server.hpp"

void Server::quit(Client &client){
	std::vector<Client>::iterator it;

	std::cout << "QUIT FUNC" << '\n';
	for (unsigned long int i = 0; i < channels.size(); i++)
	{
		for (unsigned long int j = 0 ; j < channels[i].chnclients.size(); j++)
		{
			if (channels[i].chnclients[j]._nick == client._nick)
			{
				if (channels[i]._admin == client._nick)
				{
					std::cout << channels[i]._admin << '\n';
					it = channels[i].chnclients.begin() + i;
					it++;
					channels[i]._admin = it->_nick;
					std::cout << channels[i]._admin << '\n';
				}
				channels[i].chnclients.erase(channels[i].chnclients.begin() + i);
				channels[i]._clientnum--;
				if (channels[i].chnclients.size() == 0)
					channels.erase(channels.begin() + i);
			}
		}
	}

	for (unsigned long int i = 0 ; i < fds.size() ; i++)
	{
		if (client.fd == fds[i].fd)
		{
			std::string msg = ":" + getprefix(client) + " QUIT :Leaving " + cmd[cmd.size() - 1] + "\n";
			send(client.fd, msg.c_str(), msg.length(), 0);
			close(fds[i].fd);
			fds.erase(fds.begin() + i);
			break;
		}
	}

	for (int i = 0; i < _svclientnum; i++)
	{
		if (clients[i]._nick == client._nick){
			std::vector<Client>::iterator it;
			it = clients.begin() + i;
			std::cout << it->_nick << '\n';
			clients.erase(clients.begin() + i);
			_svclientnum--;
		}
	}
	return;
}
