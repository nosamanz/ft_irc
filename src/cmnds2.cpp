#include "../inc/Server.hpp"

void Server::join(int fd){
	std::cout << "JOIN FONKSIYONU CAGIRILDI" << std::endl;	

	//send(fd, "MERHABALARAQ\n", 14, 0);
}

void Server::nick(int fd){
	
	std::string newnick = ':' + clients[fd]._nick;
	std::cout << "nick iste bu2:" << newnick << std::endl;
	newnick += '!' + clients[fd]._user + '@' + "localhost" + ' ' + cmd[0] + ' ' + cmd[1] + '\n';

	send(fd, newnick.c_str(), newnick.length(), 0);
	clients[fd]._nick = cmd[1];
	send(fd, "nickiniz degisti\n", 18, 0);
}

void Server::cap(int fd){
	// std::cout << "CAP FONKSIYONU CAGIRILDI" << std::endl;
	//for (int i =0; i < 8; i++){
	//	std::cout << "CAP FONSKIYONU CMD[" << i << "] > " << cmd[i] << std::endl; 
	//}
	clients[fd]._nick = cmd[3];
	std::cout << "nick iste bu:" << clients[fd]._nick << std::endl;
	clients[fd]._user = cmd[6];
}