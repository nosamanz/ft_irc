#include "../../inc/Server.hpp"

/*WORKING*/
void Server::quit(Client &client){
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
	for (int i = 0; i < client.channels.size(); i++)
	{
		if (client.channels.size() - 1 == 0)
			client.channels.erase(channels.begin() + i);
		else
			client.channels[i].chnclients.erase(client.channels[i].chnclients.begin() + i);
	}
	clients.erase(clients.begin() + client.num);
	std::cout << "quitting the quit " << '\n';

	return;
}
