#include "../../inc/Server.hpp"

std::string msg;
/*working*/
void Server::nick(Client &client){
	std::cout << "NICK FUNC" << '\n';
	int nindex = 0;
	if (client.passchk == false){
		std::cout << "ft_ex" << '\n';
		msg = "ERROR! passcheck failed!\n";
		send(client.fd, msg.c_str(), strlen(msg.c_str()), 0);
		msg.clear();
		quit(client);
	}
	if (_svclientnum == 1 && client.passchk == false)
		return;
	if (!client._nickfirst)
	{
		unsigned long int i = 0;
		while (i < cmd.size())
		{
			if (cmd[i] == "NICK"){
				nindex = i + 1;
				//ilk defa nick alan icin ayni nick kontrolu
				for (unsigned long int j = 0; j < clients.size(); j++){
					if (cmd[nindex] == clients[j]._nick){
						std::cout << "nick in use" << '\n';
							quit(client);
					}
				}
				client._nick = cmd[i + 1];
			}
			if (cmd[i] == "USER")
				client._user = cmd[i + 1];
			else if (cmd[i][0] == ':')
				client._host = cmd[i - 1];
			i++;
		}
		//ikinci nick komutunda yeniden buraya gelmesin diye
		client._nickfirst = true;
	}
	else
	{
		//ayni nick kontrolu
		for (unsigned long int i = 0; i < clients.size(); i++){
			std::cout << "SPINN" << '\n';
			if (!strncmp(cmd[1].c_str(), clients[i]._nick.c_str(), strlen(cmd[1].c_str()))){
				std::cout << "nick in use" << '\n';
				msg = "ERROR! nick in use!\n";
				send(client.fd, msg.c_str(), msg.length(), 0);
				msg.clear();
				if (!client._nick.empty())
					return;
				else
					quit(client);
			}
		}
		// var olan kisinin nickinin degistigi kisim
		std::cout << "nickfunc." << client._nick << '\n';
		std::string newnick = ':' + client._nick;
		newnick = getprefix(client);
		newnick += ' ' + cmd[0] + ' ' + cmd[1] + "\r\n";
		send(client.fd, newnick.c_str(), newnick.length(), 0);
		client._nick = cmd[1];
	}
}
