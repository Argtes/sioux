#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>

struct sockaddr_in 
{
sa_family_t sin_family;
in_port_t sin_port;
struct in_addr;
};

struct in_addr 
{
	unint32_t s_addr;
};



int CreerServeur()
{
	int socket_serveur;
	socket_serveur = socket(AF_INET, SDCK_STREAM, 0);
	
	if (socket_serveur == -1)
	{

	perror("socket_serveur";)

	}

	bind(socket_serveur, const struct sockaddr *addr, socklen_t addlen)
	



	return 0;
}



