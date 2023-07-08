#include "../inc/Server.hpp"

void Server::privmsg(int index){
	std::string dest = cmd[1];
	std::cout << "im dest :" << dest << std::endl;
	int i = 1;

	while (i < _clientnum)
	{
		std::cout << "nick->" << clients[i]._nick << std::endl;
		if (dest == clients[i]._nick)
		{
			std::cout << "bulundu" << std::endl;
			std::string msg = getprefix(clients[i].fd);
			// printf("%s\n", msg.c_str());
			msg += ' ' + cmd[0] + ' ' + cmd[1] + " :" + cmd[2] + '\n';
			send(clients[i].fd, msg.c_str(), msg.length(), 0);
			return;
		}
		i++;
	}
}

/*NOT WORKING!*/
void Server::join(int fd){

	std::string chn = getprefix(fd);
	chn += ' ' + cmd[0] + ' ' + cmd[1] + '\n';
	send(fd, chn.c_str(), chn.length(), 0);
}

/*working*/
void Server::nick(int fd, int index){
	std::string newnick = ':' + clients[index]._nick;
	newnick = getprefix(index);
	newnick += ' ' + cmd[0] + ' ' + cmd[1] + '\n';
	send(fd, newnick.c_str(), newnick.length(), 0);
	clients[index]._nick = cmd[1];
}

/*working*/
void Server::cap(int fd){
	// std::cout << "CAP FONKSIYONU CAGIRILDI" << std::endl;
	// for (int i =0; i < 8; i++){
	// 	std::cout << "CAP FONSKIYONU CMD[" << i << "] > " << cmd[i] << std::endl;
	// }
	clients[fd]._nick = cmd[3];
	//std::cout << "NICK [ " << clients[fd]._nick << " ]" << std::endl;
	clients[fd]._host = cmd[7];
	//std::cout << "HOST [ " << clients[fd]._host << " ]" << std::endl;
	clients[fd]._user = cmd[5];
	//std::cout << "USER [ " << clients[fd]._user << " ]" << std::endl;
}
