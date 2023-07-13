#include "../../inc/Server.hpp"

/*working*/
void Server::cap(Client &client){
	std::vector<std::string>::iterator it = cmd.begin();
	std::vector<std::string>::iterator it2;
	it2 = it;
	it++;

	while (it != cmd.end())
	{
		if (*it == "NICK"){
			it++;
			it2++;
			client._nick = *it;
			std::cout << "ben nick im" << client._nick << std::endl;
		}
		else if (*it == "USER")
		{
			it++;
			it2++;
			client._user = *it;
		}
		else if ((*it)[0] == ':')
		{
			client._host = *it2;
			break;
		}
		else
		{
			it++;
			it2++;
		}
	}
}
