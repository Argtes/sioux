#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>
#include "socket.h"

int CreerClient()
{

	int socket_client;
	int socket_serveur;
	socket_client=accept(socket_serveur, NULL, NULL);
	if(socket_client == -1)
	{
		perror("accept");
	}
	const char *message_bienvenue = "bonjour, bienvenue sur mon serveur\n";
	write(socket_client, message_bienvenue, strlen(message_bienvenue));
	return 0;
}
