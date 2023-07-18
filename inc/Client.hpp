#ifndef CLIENT_HPP
#define CLIENT_HPP

#include "Server.hpp"
#include "Channel.hpp"

class Client{
private:
public:
	int 		fd;
	int			num;
	int 		status;
	int 		c_pass;
	bool 		_nickfirst;
	bool 		passchk; 

	std::string _nick;
	std::string _user;
	std::string _host;
};

#endif
