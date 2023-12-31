#include "../inc/Server.hpp"

Server::Server(char *av[]){
	_port = ft_atoi(av[1]);
	_passwd = ft_atoi(av[2]);
    _sockfd = socket(AF_INET, SOCK_STREAM, 0);
	_svclientnum = 0;
	_chnum = 0;
	if (_sockfd == -1)
		std::cerr << "Error! socket could not be created!" << std::endl;
	else
		std::cout << "socket created successfully" << std::endl;
};

int Server::ft_pollRead(){
	int result = poll(fds.data(), fds.size(), -1);
	if (result == -1) {
	    std::cerr << "Error in poll" << std::endl;
	    return 0;
	}
	for (size_t i = 0; i < fds.size(); ++i) {
		if (fds[i].revents & POLLHUP)
		{
			quit(clients[i - 1]);
			break;
		}
		// Olay meydana gelmişse
		if (fds[i].revents & POLLIN) {
 			// Ana soket üzerinde olay meydana geldiyse yeni bir istemci bağlantısını kabul et
			if (fds[i].fd == _sockfd) {
			    // İstemci bağlantısını kabul etme ve fds dizisine eklemek
			    int clientsockfd = accept(_sockfd, NULL, NULL);
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
				clients[_svclientnum].fd = clientsockfd;
				clients[_svclientnum]._nickfirst = false;
				clients[_svclientnum].passchk = false;
				clients[_svclientnum].status = 2;
				_svclientnum++;
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
					quit(clients[i - 1]);
					return 1;
			    }
			    else {
			        buffer[bytesRead] = '\0';
					clients[i - 1].num = i - 1;
					ft_cmndhndlr();
					ft_execute(clients[i - 1]);
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
