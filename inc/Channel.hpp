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
	std::vector<std::string> _whitelist;
	std::vector<Client> chnclients;
	int chmaxuser;
	int passprotected;
	int	_clientnum;
	bool ifn;
	bool ifp;
	Channel(std::string name) : _chname(name) {_clientnum = 0; passprotected = 0; chmaxuser = 0; ifn = 0; ifp = 0;};
	// ~Channel();
};



#endif
