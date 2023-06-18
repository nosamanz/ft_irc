#include "../inc/Server.hpp"


int main(int ac, char *av[]){
	
	if (ac == 3){
		Server server(av);
		server.loop();
	}
	else
		std::cerr << "Error! the parameters should be like this: ./ircserver <server ip> <port>" << std::endl;
}  