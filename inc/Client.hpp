#ifndef CLIENT_HPP
#define CLIENT_HPP

#include "Server.hpp"

class Client{
private:
public:
	std::string _name;
	std::string _nick;
	std::string _realname;
	
	int _clientsockfd;
	Client(){};
	~Client(){};
	
};

#endif