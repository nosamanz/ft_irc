#include "../inc/Server.hpp"

void Server::execute(){
	std::cout << "Execute fonk" << std::endl;
	std::cout << "CMD[0] > " << cmd[0] << std::endl;
	
	// if (cmd[0] == "JOIN")
	// 	//join(args, fd);
	// if (cmd[0] == "QUIT")
	// 	//quit(args, fd);
	if (cmd[0] == "CAP")
		cap();
	// if (cmd[0] == "PRIVMSG")
	// 	//privmsg(args, fd);
	// if (cmd[0] == "PING")
	// 	//ping(args, fd);
	// if (cmd[0] == "PASS")
	// 	//pass(args, fd);
	// if (cmd[0] == "KICK")
	// 	//kick(args, fd);
	// if (cmd[0] == "MODE")
	// 	//mode(args, fd);
	// if (cmd[0] == "KILL")
	// 	//kill(args, fd);
	// if (cmd[0] == "BOT")
	// 	//bot(args, fd);
	// if (cmd[0] == "USER")
	// 	//user(args, fd);
}

void Server::ft_execute(){
	int i = 0;
	while (cap_ls[i] != cmd[0]){
		i++;
	}
	std::cout << "GELEN KOMUT > " << cmd[0] << std::endl;
	execute();
	cmd.clear();
}

void Server::ft_cmndhndlr(){
	int i = 0;

	char* str = strtok(buffer, " ");
	while (str != nullptr) {
	    cmd.insert(std::make_pair(i, str));
		i++;
	    str = strtok(nullptr, " ");
	}
}
