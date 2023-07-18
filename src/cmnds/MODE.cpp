#include "../../inc/Server.hpp"
//MODE #sohbet +k mypassword
void Server::mode(Client &client){
	std::cout << "MODE FONKSIYONU\n";
	int cindex = 0;
	for (unsigned long int i=0; i < channels.size(); i++){
		if (!strncmp(channels[i]._chname.c_str(), cmd[1].c_str(), cmd[1].length()))
			cindex = i;
	}
	if (cmd[0] == "MODE"){
		if (channels[cindex]._admin == client._nick){
			if (cmd[2] == "+k"){
				if (!strncmp(channels[cindex]._chname.c_str(), cmd[1].c_str(), cmd[1].length())){
					channels[cindex]._chpasswd = cmd[3];
					channels[cindex].passprotected = 1;
				}
			}
			else if (cmd[2] == "+l"){
				if (!strncmp(channels[cindex]._chname.c_str(), cmd[1].c_str(), cmd[1].length())){
					int tempmax = ft_atoi(cmd[3].c_str());
					if (channels[cindex]._clientnum > tempmax){
						std::string msg = "ERROR! MAX USER CANNOT BE LOWER THAN EXIST USER COUNT\n";
						send(client.fd, msg.c_str(), msg.length(), 0);
						return;
					}
					else{
						channels[cindex].chmaxuser = tempmax;
						return;
					}
				}
				return;
			}
			else if (!strncmp(cmd[2].c_str(), "+n", strlen("+n"))){
				if (!strncmp(channels[cindex]._chname.c_str(), cmd[1].c_str(), cmd[1].length())){
						channels[cindex].ifn = 1;
				}
			}
			else if (!strncmp(cmd[2].c_str(), "+p", strlen("+p"))){
				if (!strncmp(channels[cindex]._chname.c_str(), cmd[1].c_str(), cmd[1].length())){
					channels[cindex].ifp = 1;
				}
			}
		}
	}
}
