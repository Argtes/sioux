#include <stdio.h>
#include <string.h>


int CreerClient()
{

	int socket_client;
	socket_client=accept(socket_serveur, NULL, NULL);
	if(socket_client == -1)
	{
		perror("accept");
	}
	const char *message_bienvenue = "bonjour, bienvenue sur mon serveur\n";
	write(socket_client, message_bienvenue, strlen(message_bienvenue));