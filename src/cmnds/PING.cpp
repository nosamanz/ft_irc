#include "../../inc/Server.hpp"

void Server::ping(int fd, int index)
{
	std::string msg = getprefix(index);
	msg = msg + " PONG :" + cmd[1] + '\n';
	for (int i = 0 ; i < 5 ; i++)
		send(fd, msg.c_str(), msg.length(), 0);
}
