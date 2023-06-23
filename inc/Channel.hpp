#ifndef CHANNEL_HPP
#define CHANNEL_HPP

#include "Client.hpp"

class Channel
{
private:
	std::string _channelName;

	Client *_chAdmin;
public:
	Channel(Client *admin, std::string chname, std::string chpasswd);
	~Channel();
};



#endif
