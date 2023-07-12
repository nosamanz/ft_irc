#include "../../inc/Server.hpp"

/*working*/
void Server::cap(int fd){
	std::vector<std::string>::iterator it = cmd.begin();
	std::vector<std::string>::iterator it2;
	it2 = it;
	it++;

	while (it != cmd.end())
	{
		if (*it == "NICK"){
			it++;
			it2++;
			clients[fd]._nick = *it;
		}
		else if (*it == "USER")
		{
			it++;
			it2++;
			clients[fd]._user = *it;
		}
		else if ((*it)[0] == ':')
		{
			clients[fd]._host = *it2;
			break;
		}
		else
		{
			it++;
			it2++;
		}
	}
}
