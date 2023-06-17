#include "../inc/Server.hpp"

Server::Server(){};

Server::Server(char *av[]){
	_ip = ft_atoi(av[1]);
	_port = ft_atoi(av[2]);
    _sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if (_sockfd == -1)
		std::cerr << "Error! socket could not be created!" << std::endl;
	else
		std::cout << "socket created successfully" << std::endl;
};

Server::~Server(){};

void Server::loop(){
		struct sockaddr_in serveradress; 
		serveradress.sin_family = AF_INET;//IPV4 adres ailesi 
		serveradress.sin_addr.s_addr = INADDR_ANY; // tum yerel arayuz baglantisini kabul et
		serveradress.sin_port = htons(_port); // port numarasi
		
		//Adres ve portu sokete baglamak
		int bindres = bind(_sockfd, (struct  sockaddr*)&serveradress, sizeof(serveradress));
		if (bindres == -1){
			std::cerr << "Error! could not connect to socket address." << std::endl;
			close (_sockfd);
			return ;
		}
		
		//Soketi dinlemeye baslamak
		int listenres = listen(_sockfd, 100); // en fazla 100 baglanti kabul eder
		if (listenres == -1){
			std::cerr << "Error! socket could not be listened." << std::endl;
			return ;
		}

		std::cout << "Socket now listening and waiting for connections" << std::endl;

		while (1){
			struct sockaddr_in clientaddr;
			socklen_t clientaddrsize = sizeof(clientaddr);
			int clientsockfd = accept(_sockfd, (struct sockaddr*)&clientaddr, &clientaddrsize);
			if (clientsockfd == -1){
				std::cerr << "Error! client request could not be accepted.";
				continue;
			}			
			char clientIP[INET_ADDRSTRLEN];
			inet_ntop(AF_INET, &(clientaddr.sin_port), clientIP, INET_ADDRSTRLEN);
			int clientPort = ntohs(clientaddr.sin_port);
			std::cout << "New connection: IP " << clientIP << ", Port" << clientPort << std::endl;

			//clientdan okuma yapmayi deniyorum
			while (1){
				char buffer[1024];
				int bytesRead = recv(_sockfd, buffer, sizeof(buffer), 0);
				if (bytesRead == -1){
					continue;
				}
					//std::cerr << "Error! could not read from the client." << std::endl;
				else if (bytesRead == 0)
					std::cerr << "Error! connection lost." << std::endl;
				else{
					buffer[bytesRead] = '\0';
					std::cout << "clienttan alinan veri: " << buffer << std::endl;
				}
			}
			//close(clientsockfd);
		}
		close (_sockfd);
}
