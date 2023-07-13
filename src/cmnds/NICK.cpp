#include "../../inc/Server.hpp"

/*working*/
void Server::nick(Client &client){
	if (client._nickfirst)
	{
		int i = 0;
		while (i < cmd.size())
		{
			if (cmd[i] == "NICK")
				client._nick = cmd[i + 1];
			else if (cmd[i] == "USER")
				client._user = cmd[i + 1];
			else if (cmd[i][0] == ':')
				client._host = cmd[i - 1];
			i++;
		}
		client._nickfirst = true;
	}
	else
	{
		//ayni nick kontrolu
		for (int i = 0; i < clients.size(); i++){
			std::cout << "SPINN" << '\n';
			if (cmd[1] == clients[i]._nick){
				std::cout << "nick in use" << '\n';
				// quit(index);
			}
		}
		std::cout << "nickfunc." << client._nick;
		std::string newnick = ':' + client._nick;
		newnick = getprefix(client);
		newnick += ' ' + cmd[0] + ' ' + cmd[1] + "\r\n";
		send(client.fd, newnick.c_str(), newnick.length(), 0);
		client._nick = cmd[1];
	}
}
