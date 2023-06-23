#include "../inc/Server.hpp"

void Server::join(int fd){
	std::cout << "JOIN FONKSIYONU CAGIRILDI" << std::endl;
	
	//send(fd, "MERHABALARAQ\n", 14, 0);
}

void Server::nick(int fd){
	std::cout << "NICK FONKSIYONU CAGIRILDI" << std::endl;
	std::cout << "CMD SIZE > " << cmd.size() << std::endl;
	for (int i =0; i < 8; i++){
		std::cout << "NICK FONSKIYONU CMD[" << i << "] > " << cmd[i] << std::endl;
	}
	clients[fd]._nick = cmd[1];
	send(fd, "nickiniz degisti\n", 18, 0);
}

void Server::cap(int fd){
	std::cout << "CAP FONKSIYONU CAGIRILDI" << std::endl;
	std::cout << "CMD SIZE > " << cmd.size() << std::endl;
	for (int i =0; i < 8; i++){
		std::cout << "CAP FONSKIYONU CMD[" << i << "] > " << cmd[i] << std::endl;
	}
	std::cout << "cmd[3] = " << cmd[3] << std::endl;
	clients[fd]._nick = cmd[2];
	clients[fd]._realname = cmd[3];
	std::cout << "clients[fd]._name = " << clients[fd]._realname << std::endl;
}
