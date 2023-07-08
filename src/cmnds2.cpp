#include "../inc/Server.hpp"

void Server::privmsg(int fd){
	std::string dest = cmd[1];
	int i = 0;
	std::cout << "DEST ======= " << dest << std::endl;
	std::map<int, Client>::iterator mapi = clients.begin();

	while (mapi != clients.end()){
		// std::cout << "SPINIIINNNNGGG!!!1 " << clients[i]._nick << std::endl;
		if (dest == clients[i]._nick)
			break;
		i++;
		//std::cout << mapi->second._nick << std::endl;
		mapi++;
	}
	std::cout << std::endl << i << std::endl;
	std::string msg = getprefix(clients[i].fd);
	msg += ' ' + cmd[0] + ' ' + cmd[1] + '\n';
	send(clients[i].fd, msg.c_str(), msg.length(), 0);
}

/*NOT WORKING!*/
void Server::join(int fd){

	std::string chn = getprefix(fd);
	chn += ' ' + cmd[0] + ' ' + cmd[1] + '\n';
	send(fd, chn.c_str(), chn.length(), 0);
}

/*working*/
void Server::nick(int fd){
	
	std::string newnick = ':' + clients[fd]._nick;
	newnick = getprefix(fd);
	newnick += ' ' + cmd[0] + ' ' + cmd[1] + '\n';
	send(fd, newnick.c_str(), newnick.length(), 0);
	clients[fd]._nick = cmd[1];
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