#include "../inc/Server.hpp"

void Server::ft_cmndhndlr(){
	int i = 0;
	char* str = strtok(buffer, " ");
	while (str != nullptr) {
	    command.push_back(str);
	    str = strtok(nullptr, " ");
	}
	std::vector<std::string>::iterator it = command.begin();
	while (i != command.size()){
		std::cout << *it; //<< std::endl;
		it++;
		i++;
	}
}
