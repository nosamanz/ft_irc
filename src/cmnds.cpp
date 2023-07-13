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
	// for (int i = 0; i < cmd.size(); i++){
	// 	if (cmd[i] == "PASS"){
	// 		if (atoi(cmd[i + 1].c_str()) != _passwd)
	// 			quit(index);
	// 	}
	// }
	if (cmd[0] == "CAP")
		cap(client);
	if (cmd[0] == "NICK")
		nick(client);
	if (cmd[0] == "JOIN")
		join(client);
	if (cmd[0] == "PRIVMSG")
		privmsg(client);
	if (cmd[0] == "QUIT")
		quit(client);
	// if (cmd[0] == "PASS")
	// 	pass(index);
	if (cmd[0] == "PING")
		ping(client);
	// if (cmd[0] == "KICK")
		//kick(args, fd);
	// if (cmd[0] == "MODE")
		//mode(args, fd);
	// if (cmd[0] == "KILL")
		//kill(args, fd);
	// if (cmd[0] == "BOT")
		// bot(args, fd);
	// if (cmd[0] == "USER")
		//user(args, fd);
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
