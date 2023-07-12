#include "../../inc/Server.hpp"

/*WORKING*/
void Server::quit(int index){
	for (size_t i = 0 ; i < fds.size() ; i++)
	{
		if (clients[index].fd == fds[i].fd)
		{
			std::string msg = ":" + getprefix(clients[index].fd) + " QUIT :Leaving " + cmd[cmd.size() - 1];
			send(clients[index].fd, msg.c_str(), msg.length(), 0);
			close(fds[i].fd);
			fds.erase(fds.begin() + i);
		}
	}
	std::cout << "INDEX " << index << '\n';
	clients.erase(clients.begin() + index);
	std::cout << "quitting the quit " << '\n';
	return;
}