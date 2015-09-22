#include <stdio.h>
#include <string.h>
#include "socket.h"
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>

int main()
{
	int socket_serveur;
	int socket_client;

	socket_serveur = creer_serveur(8080);
	

	

	socket_client=accept(socket_serveur, NULL, NULL);
	if(socket_client == -1)
	
	{
		perror("accept");
	}
	
	const char *message_bienvenue = "bonjour, bienvenue sur mon serveur\n";
	write(socket_client, message_bienvenue, strlen(message_bienvenue));
	

	return 0;
	
	


}
