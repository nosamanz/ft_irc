#ifndef SERVER_HPP
#define SERVER_HPP

#include <iostream> //cout, cin, cerr
#include <sys/socket.h> // socket, setsockopt, getsockname, bind, connect, listen, accept, send, recv
#include <unistd.h> // close
#include <netdb.h> // getprotobyname, gethostbyname, freeaddrinfo, getaddrinfo
#include <arpa/inet.h> // htonl, htons, ntohs, ntohl, inet_addr, inet_ntoa, 
#include <signal.h> // signal
#include <fcntl.h> // lseek, fstat, fcntl
#include <poll.h> // poll
#include <netinet/in.h> // struct sockaddr_in
/*containers*/
#include <algorithm>
#include <vector>
#include <map>
#include "Client.hpp"

/*
1. `socket`: Creates a socket and returns a file descriptor used for network communication.
2. `close`: Closes the specified file descriptor.
3. `setsockopt`: Sets socket options.
4. `getsockname`: Retrieves the address of a socket and returns it in a struct sockaddr data structure.
5. `getprotobyname`: Gets the protocol number based on the protocol name.
6. `gethostbyname`: Gets the IP address based on the host name.
7. `getaddrinfo`: Used to obtain information about a host and service based on host name and service name.
8. `freeaddrinfo`: Frees the memory allocated for the addrinfo structure created by getaddrinfo.
9. `bind`: Associates a socket with an address and port.
10. `connect`: Establishes a connection to a server using a socket.
11. `listen`: Marks the socket as a passive socket and starts listening for incoming connections.
12. `accept`: Accepts an incoming connection and returns a new socket descriptor for communication.
13. `htons`: Converts a 16-bit value to network byte order.
14. `htonl`: Converts a 32-bit value to network byte order.
15. `ntohs`: Converts a 16-bit value to host byte order.
16. `ntohl`: Converts a 32-bit value to host byte order.
17. `inet_addr`: Converts an IPv4 address from a string to an integer.
18. `inet_ntoa`: Converts an IPv4 address from an integer to a string.
19. `send`: Sends data from a socket.
20. `recv`: Receives data from a socket.
21. `signal`: Sets a signal handler function.
22. `lseek`: Changes the file offset of an open file.
23. `fstat`: Retrieves information about a file.
24. `fcntl`: Performs various operations on a file descriptor.
25. `poll`: Monitors multiple file descriptors to determine which ones are ready for I/O operations.
*/

/*
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
	domain (AF_INET): Soketin kullanacağı adres ailesini belirtir. AF_INET, IPv4 adres ailesini temsil eder.

	type (SOCK_STREAM): Soketin türünü belirtir. SOCK_STREAM, güvenilir, bağlantı tabanlı bir soketin oluşturulacağını belirtir. Bu tip soket, TCP protokolünü kullanır. Diğer bir seçenek olarak SOCK_DGRAM kullanılabilir, bu da UDP protokolünü kullanır.

	protocol (0): Protokolü belirtir. 0 olarak atanması, soketin kullanılan adres ailesi ve türüne göre doğru protokolün otomatik olarak seçilmesini sağlar. Örneğin, AF_INET için SOCK_STREAM türünde bir soket oluşturulacaksa, protocol parametresi otomatik olarak IPPROTO_TCP olarak seçilir.

*/

class Server
{
private:
	int _port;
	int _ip;
	int _sockfd;
	int _clientnum;
	char buffer[1024];

	std::map<int, std::string> cmd;
	std::vector<pollfd> fds;
	std::map<int, Client> clients;

	//std::vector<std::string> command;
	// std::map<int, std::string> cap_ls;
public:
	Server(char *av[]);

	void loop();
	int ft_binder();
	int ft_listen();
	int ft_poll();
	int ft_pollRead();
	void ft_execute(int fd);
	void execute(int fd);
	void ft_cmndhndlr(int fd);

	/*commands*/
	void cap(int fd);
	void nick(int fd);
	void join(int fd);
};

int	ft_atoi(const char *str);

#endif