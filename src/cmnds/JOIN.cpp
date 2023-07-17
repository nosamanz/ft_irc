#include "../../inc/Server.hpp"

/*WORKING*/
void Server::join(Client &client)
{
	std::cout << "JOIN FUNC" << '\n';
	std::cout << "JOIN FONKSIYONU" << '\n';
	if (cmd.size() > 3)
	{
		std::cerr << "join ARG Error!" << std::endl;
		return;
	}
	std::string chn = getprefix(client);
	if (cmd[1][0] != '#')
		cmd[1] = '#' + cmd[1];
	for (int i = 0; i < channels.size(); i++)
	{
		if (!strncmp(cmd[1].c_str(), channels[i]._chname.c_str(), cmd[1].length()))
		{
			if (channels[i].passprotected == 1){
				if (strncmp(cmd[2].c_str(), channels[i]._chpasswd.c_str(), channels[i]._chpasswd.length())){
					std::cout << "join if pass check!1\n"; 
					chn = "ERROR! PLEASE JOIN WITH CHANNEL PASSWORD!\n";
					send(client.fd, chn.c_str(), chn.length(), 0);
					chn.clear();
					return;
				}
			}
			if (channels[i].chmaxuser == channels[i]._clientnum){
				send(client.fd, "ERROR! YOU CANNOT JOIN THIS CHANNEL USER LIMIT REACHED", 55, 0);
				return;
			}
			channels[i].chnclients.push_back(client);
			channels[i]._clientnum++;
			std::cout << "CLNUM:" << channels[i]._clientnum << std::endl;
			chn += ' ' + cmd[0] + ' ' + cmd[1] + "\r\n";
			for (int j = 0; j < channels[i]._clientnum; j++){
				send(channels[i].chnclients[j].fd, chn.c_str(), chn.length(), 0);
			}
			return;
		}
	}
	Channel newch(cmd[1]);
	if (cmd.size() == 2)
		newch._chpasswd = cmd[2];
	newch.chnclients.push_back(client);
	newch._clientnum++;
	newch._admin = client._nick;
	channels.push_back(newch);
	_chnum++;
	chn += ' ' + cmd[0] + ' ' + cmd[1] + "\r\n";
	std::cout << "SENDIN USTU" << '\n';
	send(client.fd, chn.c_str(), chn.length(), 0);
	chn.clear();
}
