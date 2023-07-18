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
	std::string msg;
	std::cout << "Execute fonk" << std::endl;
	cmd[0] = MakeUpper(cmd[0]);
	for (unsigned long int i = 0; i < cmd.size(); i++){
		if (cmd[i] == "PASS"){
			client.passchk = true;
			if (atoi(cmd[i + 1].c_str()) != _passwd){
				msg = "ERROR! Password incorrect\n";
				send(client.fd, msg.c_str(), msg.length(), 0);
				msg.clear();
				quit(client);
			}
		}
	}
	for(unsigned long int i = 0; i < cmd.size(); i++){
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
		if (cmd[i] == "USER")
			user(client);
		if (cmd[i] == "MODE")
			mode(client);
		if (cmd[i] == "INVITE")
			invite(client);
		if (cmd[i] == "NOTICE")
			notice(client);
	}
	cmd.clear();
}

void Server::ft_cmndhndlr(void){
	int i = 0;

	std::cout << "\n--------------------------------------------------" << std::endl;
	std::cout << "buffer before parse: " << buffer << std::endl;
	std::cout << "\n--------------------------------------------------" << std::endl;

	char* str = strtok(buffer, " \n");
	while (str != NULL) {  
		cmd.push_back(str);
	    i++;
	    str = strtok(NULL, " \n");
	}
}
