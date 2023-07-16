#include "../../inc/Server.hpp"

void Server::quit(Client &client){
	std::cout << "QUIT FUNC" << '\n';
	for (int i = 0; i < client.channels.size(); i++)
	{
		std::cout << "quit for number 1" << '\n';
		std::cout << "if  ustu" << client.channels[i].chnclients.size() << '\n';
		if (client.channels[i].chnclients.size() == 1){
			std::cout << "if  " << client.channels[i].chnclients.size() << '\n';
			client.channels.erase(client.channels.begin() + i);
		}
		else{
			std::cout << "else" << '\n';
			client.channels[i].chnclients.erase(client.channels[i].chnclients.begin() + i);
		}
		client.channels[i]._clientnum--;
		//std::cout << client.channels[i]._clientnum << '\n';
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
