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
	std::vector<Channel> channels;
	std::string _nick;
	std::string _user;
	std::string _host;
	bool _nickfirst;
	// Client(){};
	// ~Client(){};
};

#endif
