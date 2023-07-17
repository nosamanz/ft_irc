#include "../../inc/Server.hpp"

void Server::kick(Client &client){
    std::cout << "KICK FUNC" << '\n';
    for (int i = 0; i < channels.size(); i++){
        std::string msg;
        msg = getprefix(client);
        msg += ' ' + cmd[0] + ' ' + cmd[1] + ' ' + cmd[2] + " :" + cmd[3] + '\n';
        std::cout << cmd[1] << '\n';
        if (!strncmp(channels[i]._chname.c_str(), cmd[1].c_str(), cmd[1].length())){
            if (channels[i]._admin == client._nick){
                for (int a = 0; a < channels[i].chnclients.size(); a++)
                    send(channels[i].chnclients[a].fd, msg.c_str(), msg.length(), 0);
                for (int j = 0; j < channels[i].chnclients.size(); j++){
                    if (!strncmp(channels[i].chnclients[j]._nick.c_str(), cmd[2].c_str(), cmd[2].length()))
                    // {
                        // std::cout << channels[i].chnclients[j]._nick << '\n';
                        channels[i].chnclients.erase(channels[i].chnclients.begin() + j);
                        // std::cout << channels[i].chnclients[j]._nick << '\n';
                    // }
                }
            }
        }
    }
}
