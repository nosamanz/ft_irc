#include "../../inc/Server.hpp"

void Server::ping(Client &client)
{
	std::string msg = getprefix(client);
	msg = msg + " PONG :" + cmd[1] + '\n';
	send(client.fd, msg.c_str(), msg.length(), 0);
}
