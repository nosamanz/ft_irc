#include "../../inc/Server.hpp"

/*working*/
void Server::nick(int fd, int index){
	if (clients[index]._nickfirst)
	{
		int i = 0;
		while (i < cmd.size())
		{
			if (cmd[i] == "NICK")
				clients[index]._nick = cmd[i + 1];
			else if (cmd[i] == "USER")
				clients[index]._user = cmd[i + 1];
			else if (cmd[i][0] == ':')
				clients[index]._host = cmd[i - 1];
			i++;
		}
		clients[index]._nickfirst = true;
	}
	else
	{
		//ayni nick kontrolu
		for (int i = 0; i < clients.size(); i++){
			std::cout << "SPINN" << '\n';
			if (cmd[1] == clients[i]._nick){
				std::cout << "nick in use" << '\n';
				quit(index);
			}
		}
		std::string newnick = ':' + clients[index]._nick;
		newnick = getprefix(index);
		newnick += ' ' + cmd[0] + ' ' + cmd[1] + "\r\n";
		send(fd, newnick.c_str(), newnick.length(), 0);
		clients[index]._nick = cmd[1];
	}
}
