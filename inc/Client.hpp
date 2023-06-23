#ifndef CLIENT_HPP
#define CLIENT_HPP

#include "Server.hpp"
#include "Channels.hpp"

class Client{
private:
	int	_port;
	int	_fd;
public:
	std::string _nick;
	std::string _realname;

	std::vector<Channel *> _channels;

	Client(int fd, int port);
	~Client(){};

};

#endif
