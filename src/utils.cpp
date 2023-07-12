#include "../inc/Server.hpp"

// std::string Server::getprefix(int index){
// 	std::string asd;
// 	asd = ':' + clients[index]._nick + '!' + clients[index]._user + '@' + clients[index]._host;
// 	return (asd);
// }
std::string Server::getprefix(int index){
	std::string asd;
	asd = ':' + clients[index]._nick + '!' + clients[index]._user;
	if (!clients[index]._host.empty())
		asd += '@' + clients[index]._host;
	return (asd);
}
//:ali!osarihan@localhost KOMUT ARGUMAN

int Server::ft_binder(){
	//Adres ve portu sokete baglamak
	struct sockaddr_in serveradress;
	serveradress.sin_family = AF_INET;//IPV4 adres ailesi
	serveradress.sin_addr.s_addr = INADDR_ANY; // tum yerel arayuz baglantisini kabul et
	serveradress.sin_port = htons(_port); // port numarasi

	int bindres = bind(_sockfd, (struct  sockaddr*)&serveradress, sizeof(serveradress));
	if (bindres == -1){
		std::cerr << "Error! could not connect to socket address." << std::endl;
		close (_sockfd);
		return 0;
	}
	return 1;
}

int Server::ft_listen(){
	int listenres = listen(_sockfd, 100); // en fazla 100 baglanti kabul eder
	if (listenres == -1){
		std::cerr << "Error! socket could not be listened." << std::endl;
		return 0;
	}
	return 1;
}

int Server::ft_poll(){
    pollfd mainSocket;
    mainSocket.fd = _sockfd;
    mainSocket.events = POLLIN;
    fds.push_back(mainSocket);
	return 1;
}


int	ft_atoi(const char *str)
{
	int				i;
	int				s;
	unsigned int	res;

	i = 0;
	s = 1;
	res = 0;
	while ((str[i] >= '\t' && str[i] <= '\r') || str[i] == ' ')
		i++;
	if (str[i] == '-')
		s = -1;
	if (str[i] == '-' || str[i] == '+')
	{
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + (str[i] - '0');
		i++;
	}
	return (res * s);
}
