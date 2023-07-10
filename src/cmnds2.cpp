#include "../inc/Server.hpp"

void Server::privmsg(int index)
{
	std::cout << "PRIVMSG FONKSIYONU" << '\n';
	std::string dest = cmd[1];
	int i = 0;

	std::cout << dest << " " <<  clients[i]._nick << '\n';
	std::string msg = getprefix(clients[i].fd);
	msg += ' ' + cmd[0] + ' ' + cmd[1] + ' ' + clients[index]._nick + ' ';
	for (int l = 2; l < cmd.size(); l++){
		msg += cmd[l];
		msg += 32;
	}
	msg += "\r\n";
	std::cout << " prefix " << msg << '\n';
	if (cmd[1][0] == '#'){
		//std::cout << "girdim" << std::endl;
		for (int j = 0; j < channels.size(); j++)
		{
			std::string temp = channels[j]._chname;
			if (!strncmp(dest.c_str(), temp.c_str(), strlen(dest.c_str())))
			{
				std::cout << "ICINDEYIM!" << '\n';
				for (int k = 0; k < channels[j]._clientnum; k++)
				{
					std::cout << k << "\n";
					if (channels[j].chnclients[index]._nick != channels[j].chnclients[k]._nick)
						send(channels[j].chnclients[k].fd, msg.c_str(), msg.length(), 0);
				}
				return;
			}
		}
	}
	else{
		send(clients[i].fd, msg.c_str(), msg.length() + 1, 0);
		return;
	}
}

/*NOT WORKING!*/
void Server::join(int fd, int index)
{
	std::cout << "JOIN FONKSIYONU" << '\n';
	if (cmd.size() > 2)
	{
		std::cerr << "join ARG Error!" << std::endl;
		return;
	}
	std::string chn = getprefix(index);
	if (cmd[1][0] != '#')
		cmd[1] = '#' + cmd[1];
	for (int i = 0; i < channels.size(); i++)
	{
		if (cmd[1] == channels[i]._chname)
		{
			std::cout << "SELAM" << std::endl;
			channels[i].chnclients.push_back(clients[index]);
			channels[i]._clientnum++;
			std::cout << "CLNUM:" << channels[i]._clientnum << std::endl;
			chn += ' ' + cmd[0] + ' ' + cmd[1] + "\r\n";
			for (int j = 0; j < channels[i]._clientnum; j++)
			{
				std::cout << "#######" << j  << std::endl;
				send(channels[i].chnclients[j].fd, chn.c_str(), chn.length(), 0);
			}
			std::cout << "forciktim" << std::endl;
			return;
		}
	}
	Channel newch(cmd[1]);
	if (cmd.size() == 2)
		newch._chpasswd = cmd[2];
	newch.chnclients.push_back(clients[index]);
	newch._clientnum++;
	newch._admin = clients[index]._nick;
	channels.push_back(newch);
	_chnum++;
	chn += ' ' + cmd[0] + ' ' + cmd[1] + "\r\n";
	std::cout << "SENDIN USTU" << '\n';
	send(channels[index].chnclients[index].fd, chn.c_str(), chn.length(), 0);
}

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
		std::string newnick = ':' + clients[index]._nick;
		newnick = getprefix(index);
		newnick += ' ' + cmd[0] + ' ' + cmd[1] + "\r\n";
		send(fd, newnick.c_str(), newnick.length(), 0);
		clients[index]._nick = cmd[1];
	}
}

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
