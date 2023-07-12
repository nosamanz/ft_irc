#include "../inc/Server.hpp"

Server::Server(char *av[]){
	_port = ft_atoi(av[1]);
	_passwd = ft_atoi(av[2]);
    _sockfd = socket(AF_INET, SOCK_STREAM, 0);
	_clientnum = 0;
	_chnum = 0;
	if (_sockfd == -1)
		std::cerr << "Error! socket could not be created!" << std::endl;
	else
		std::cout << "socket created successfully" << std::endl;

	// cap_ls[0] = "NICK";
	// cap_ls[1] = "JOIN";
	// cap_ls[2] = "QUIT";
	// cap_ls[3] = "CAP";
	// cap_ls[4] = "KICK";
	// cap_ls[5] = "PING";
	// cap_ls[6] = "PASS";
	// cap_ls[7] = "BOT";
	// cap_ls[8] = "MODE";
	// cap_ls[9] = "KILL";
	// cap_ls[10] = "USER";

};

int Server::ft_pollRead(){
	int result = poll(fds.data(), fds.size(), -1);
	if (result == -1) {
	    std::cerr << "Error in poll" << std::endl;
	    return 0;
	}
	for (size_t i = 0; i < fds.size(); ++i) {
		// Olay meydana gelmişse
		if (fds[i].revents & POLLIN) {
 			// Ana soket üzerinde olay meydana geldiyse yeni bir istemci bağlantısını kabul et
			if (fds[i].fd == _sockfd) {
			    // İstemci bağlantısını kabul etme ve fds dizisine eklemek
			    int clientsockfd = accept(_sockfd, nullptr, nullptr);

			    if (clientsockfd == -1) {
			        std::cerr << "Error accepting client connection" << std::endl;
					return 1;
			    }
				pollfd pfd;
				pfd.fd = clientsockfd;
				pfd.events = POLLIN;
				pfd.revents = 0;
				fds.push_back(pfd);
				Client client;
				clients.push_back(client);
				clients[_clientnum].fd = clientsockfd;
				clients[_clientnum]._nickfirst = false;
				clients[_clientnum].status = 2;
				_clientnum++;
			    std::cout << "New client connected" << std::endl;
			}
			// Diğer soketler üzerinde olay meydana geldiyse veriyi okuma veya işlem yapma
			else {
			    int bytesRead = recv(fds[i].fd, buffer, sizeof(buffer), 0);
			    if (bytesRead == -1) {
					std::cerr << "Error! Could not read from the client." << std::endl;
					return 1;
				}
	    	    else if (bytesRead == 0) {
	    	        std::cerr << "Client connection closed." << std::endl;
			        //close(fds[i].fd);
			        //fds.erase(fds.begin() + i);
					//quit()
					return 1;
			    }
			    else {
			        buffer[bytesRead] = '\0';
					ft_cmndhndlr(i - 1);
					ft_execute(i - 1);
			        //std::cout << "Received data from client: " << buffer << std::endl;
			    }
			}
		}
	}
	return 1;
}

void Server::loop(){
		if (ft_binder() == 0) return;
		if (ft_listen() == 0) return;
		std::cout << "Socket now listening and waiting for connections" << std::endl;
		ft_poll();
		while (true) {
		    if (ft_pollRead() == 0) break; else continue;
		}
	close (_sockfd);
}
