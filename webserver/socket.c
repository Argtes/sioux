#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>



//int socket(int domain, int type, int protocol);
int main(int argc, char **argv)
{
	int socket_serveur;
	socket_serveur = socket(AF_INET, SDCK_STREAM, 0);
	
	if (socket_serveur == -1)
	{

	perror("socket_serveur";)

	}

	int bind(int sockfd, const struct sockaddr *addr, socklen_t addlen)
	{
		/* data */
	}



	return 0;
}



