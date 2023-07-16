#ifndef CHANNEL_HPP
#define CHANNEL_HPP

#include <iostream>
#include "Server.hpp"
// #include "Client.hpp"

class Client;

class Channel
{
private:
public:
	std::string			_chname;
	std::string			_chpasswd;
	std::string			_admin;
	std::vector<Client> chnclients;
	int	_clientnum;
	Channel(std::string name) : _chname(name) {_clientnum = 0;};
	// ~Channel();
};



#endif
