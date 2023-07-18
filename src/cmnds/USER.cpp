#include "../../inc/Server.hpp"

//USER <kullanıcı adı> <gerçek ad> <sunucu adı> :<kullanıcı hakkında diğer ayrıntılar>

void Server::user(Client &client){
	if (cmd.size() > 5){
		std::vector<std::string>::iterator it = cmd.begin();
		std::vector<std::string>::iterator it2;
		it2 = it;
		it++;

		while (it != cmd.end()){
			if (*it == "USER"){
				it++;
				it2++;
				client._user = *it;
			}
			else if ((*it)[0] == ':'){
				client._host = *it2;
				break;
			}
			else{
				it++;
				it2++;
			}
		}
		std::string msg = "Welcome to irc server that made by oozcan osarihan and ebattal!\n";
		send(client.fd, msg.c_str(), msg.length(), 0);
	}
	else {
		std::string msg = "ERROR! paramaters should be like this USER <kullanıcı adı> <gerçek ad> <sunucu adı> :<kullanıcı hakkında diğer ayrıntılar>\n";
		send(client.fd, msg.c_str(), msg.length(), 0);
		msg.clear();
	}
}
