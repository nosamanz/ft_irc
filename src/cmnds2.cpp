#include "../inc/Server.hpp"

void Server::privmsg(int index){

	std::string dest = cmd[1];
	int i = 0;
	while (i < _clientnum)
	{
		if (!strncmp(dest.c_str(), clients[i]._nick.c_str(), strlen(dest.c_str())))
		{
			std::cout << "bulundu" << std::endl;
			std::string msg = getprefix(clients[i].fd);
			msg += ' ' + cmd[0] + ' ' + cmd[1] + " :" + cmd[2] + '\n';
			send(clients[i].fd, msg.c_str(), msg.length() + 1, 0);
			return;
		}
		i++;
	}
}

/*NOT WORKING!*/
void Server::join(int fd, int index){

	std::string chn = getprefix(index);
	if (cmd[1][0] != '#')
		cmd[1] = '#' + cmd[1];
	chn += ' ' + cmd[0] + ' ' + cmd[1] + '\n';
	send(fd, chn.c_str(), chn.length(), 0);


}

/*working*/
void Server::nick(int fd, int index){
	if (!_nickfirst)
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
		_nickfirst = true;
	}
	else
	{
		std::string newnick = ':' + clients[index]._nick;
		newnick = getprefix(index);
		newnick += ' ' + cmd[0] + ' ' + cmd[1] + '\n';
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
