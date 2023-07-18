#include "../../inc/Server.hpp"
//MODE #sohbet +k mypassword
void Server::mode(Client &client){
	std::cout << "MODE FONKSIYONU\n";
	if (cmd[0] == "MODE"){
		if (cmd[2] == "+k"){
			for (unsigned long int i=0; i < channels.size(); i++){
				if (!strncmp(channels[i]._chname.c_str(), cmd[1].c_str(), strlen("+k"))){
					channels[i]._chpasswd = cmd[3];
					channels[i].passprotected = 1;
				}
			}
		}
		else if (cmd[2] == "+l"){
			for (unsigned long int i=0; i < channels.size(); i++){
				if (!strncmp(channels[i]._chname.c_str(), cmd[1].c_str(), strlen("+l"))){
					int tempmax = ft_atoi(cmd[3].c_str());
					if (channels[i]._clientnum > tempmax){
						std::string msg = "ERROR! MAX USER CANNOT BE LOWER THAN EXIST USER COUNT\n";
						send(client.fd, msg.c_str(), msg.length(), 0);
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
		else if (!strncmp(cmd[2].c_str(), "+n", strlen("+n"))){
			for (unsigned long int i=0; i < channels.size(); i++){
				if (!strncmp(channels[i]._chname.c_str(), cmd[1].c_str(), cmd[1].length())){
						channels[i].ifn = 1;
				}
			}
		}
		else if (!strncmp(cmd[2].c_str(), "+p", strlen("+p"))){
			for (unsigned long int i=0; i < channels.size(); i++){
				if (!strncmp(channels[i]._chname.c_str(), cmd[1].c_str(), cmd[1].length())){
					channels[i].ifp = 1;
				}
			}
		}
	}
}