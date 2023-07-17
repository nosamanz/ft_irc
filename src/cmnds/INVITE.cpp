#include "../../inc/Server.hpp"

void Server::invite(Client &Client){
    std::cout << "INVITE FONKSIYONU\n";
    for (int i = 0; i < channels.size(); i++){
        if (!strncmp(cmd[2].c_str(), channels[i]._chname.c_str(), cmd[2].length())){
            if (!strncmp(Client._nick.c_str(), channels[i]._admin.c_str(), channels[i]._admin.length())){
                channels[i]._whitelist.push_back(cmd[1]);
                for (int j = 0; j < clients.size(); j++){
                    if (!strncmp(cmd[1].c_str(),clients[j]._nick.c_str(), cmd[1].length())){
                        std::cout << "mesaj gonderildi\n";
                        std::string msg = "you have been invited to channel " + cmd[2] + " you can type /join to join that channel\n";
                        send(clients[j].fd, msg.c_str(), msg.length(), 0);
                    }
                }
            }
        }
    }
}