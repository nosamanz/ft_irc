#ifndef CLIENT_HPP
#define CLIENT_HPP

#include "Server.hpp"

class Client{
private:
public:
	int 		fd;
	std::string _nick;
	std::string _user;
	std::string _host;
	Client(){};
	~Client(){};
	
};

#endif