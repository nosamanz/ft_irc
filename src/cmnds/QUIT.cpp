#include "../../inc/Server.hpp"

void Server::quit(Client &client){
	std::cout << "QUIT FUNC" << '\n';
	for (int i = 0; i < channels.size(); i++)
	{
		std::cout << "quit for number 1" << '\n';
		std::cout << "if  ustu" << channels[i].chnclients.size() << '\n';
		if (channels[i].chnclients.size() == 1){
			std::cout << "if  " << channels[i].chnclients.size() << '\n';
			channels.erase(channels.begin() + i);
		}
		else{
			std::cout << "else" << '\n';
			channels[i].chnclients.erase(channels[i].chnclients.begin() + i);
		}
		channels[i]._clientnum--;
	}

	for (int i = 0; i < _svclientnum; i++)
	{
		if (clients[i]._nick == client._nick)
			clients.erase(clients.begin() + i);
	}
	_svclientnum--;

	for (size_t i = 0 ; i < fds.size() ; i++)
	{
		if (client.fd == fds[i].fd)
		{
			std::string msg = ":" + getprefix(client) + " QUIT :Leaving " + cmd[cmd.size() - 1];
			send(client.fd, msg.c_str(), msg.length(), 0);
			close(fds[i].fd);
			fds.erase(fds.begin() + i);
		}
	}
	std::cout << "quitting the quit " << '\n';

	return;
}
