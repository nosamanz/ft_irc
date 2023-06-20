#include "../inc/Server.hpp"

void Server::cap(){
	std::cout << "CAP FONKSIYONU CAGIRILDI" << std::endl;
	std::cout << "CMD SIZE > " << cmd.size() << std::endl;
	for (int i =0; i < 8; i++){
		std::cout << "CAP FONSKIYONU CMD[" << i << "] > " << cmd[i] << std::endl; 
	}
	std::vector<Client>::iterator it;

	it = clients.begin();
	it->_name = cmd[3];
	it->_nick = cmd[2];
}