#include "../../inc/Server.hpp"
//MODE #sohbet +k mypassword
void Server::mode(Client &client){
	std::cout << "MODE FONKSIYONU\n";
	if (cmd[0] == "MODE"){
		if (cmd[2] == "+k"){
			for (int i=0; i < channels.size(); i++){
				if (!strncmp(channels[i]._chname.c_str(), cmd[1].c_str(), cmd[1].length())){
					channels[i]._chpasswd = cmd[3];
					channels[i].passprotected = 1;
				}
			}
		}
		else if (cmd[2] == "+l"){
			for (int i=0; i < channels.size(); i++){
				if (!strncmp(channels[i]._chname.c_str(), cmd[1].c_str(), cmd[1].length())){
					int tempmax = ft_atoi(cmd[3].c_str());
					if (channels[i]._clientnum > tempmax){
						send(client.fd, "ERROR! MAX USER CANNOT BE LOWER THAN EXIST USER COUNT\n", 55, 0);
						return;
					}
					else{
						channels[i].chmaxuser = tempmax;
						return;
					}
				}
			}
			return;
		}
		else if (cmd[2] == "+n"){
			return;
		}
	}
}