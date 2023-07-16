#include "../inc/Server.hpp"

std::string MakeUpper(std::string asd){
	int i = 0;
	while (asd[i] != '\0'){
		asd[i] = toupper(asd[i]);
		i++;
	}
	return (asd);
}

void Server::ft_execute(Client &client){
	std::cout << "Execute fonk" << std::endl;
	cmd[0] = MakeUpper(cmd[0]);
	for (int i = 0; i < cmd.size(); i++){
		if (cmd[i] == "PASS"){
			client.passchk = true;
			if (atoi(cmd[i + 1].c_str()) != _passwd)
				quit(client);
		}
	}
	for(int i = 0; i < cmd.size(); i++){
		if (cmd[i] == "CAP")
			cap(client);
		if (cmd[i] == "NICK")
			nick(client);
		if (cmd[i] == "JOIN")
			join(client);
		if (cmd[i] == "PRIVMSG")
			privmsg(client);
		if (cmd[i] == "QUIT")
			quit(client);
		if (cmd[i] == "PING")
			ping(client);
		if (cmd[i] == "PASS")
			pass(client);
		if (cmd[i] == "KICK")
			kick(client);
	}
	// if (cmd[i] == "USER")
	// 	user(args, fd);
	// if (cmd[i] == "MODE")
		//mode(args, fd);
	// if (cmd[i] == "KILL")
		//kill(args, fd);
	cmd.clear();
}

void Server::ft_cmndhndlr(int index){
	int i = 0;

	std::cout << "--------------------------------------------------" << std::endl;
	std::cout << "buffer before parse: " << buffer << std::endl;
	std::cout << "--------------------------------------------------" << std::endl;

	char* str = strtok(buffer, " \n");
	while (str != nullptr) {
		cmd.push_back(str);
	    i++;
	    str = strtok(nullptr, " \n");
	}
}
