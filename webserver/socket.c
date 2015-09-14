#include <stdio.h>
#include <string.h>
#include "socket.h"
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>

int CreerServeur(int port)
{
	port = 8080;
	int socket_serveur;
	socket_serveur = socket(AF_INET, SOCK_STREAM, 0);
	
	if (socket_serveur == -1)
	{

	perror("socket_serveur");

	}

	struct sockaddr_in saddr;
	saddr.sin_family = AF_INET;
	saddr.sin_port = htons(port);
	saddr.sin_addr.s_addr = INADDR_ANY;

	if (bind(socket_serveur, (struct sockaddr *)&saddr, sizeof(saddr)) == -1)
	{
		perror("bind socket_serveur");
	}	
	

	
	if (listen(socket_serveur, 10) == -1){
		perror("listen socket_serveur");
	}




	return 0;
}



