#include <stdio.h>
#include <string.h>
#include "socket.h"
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>
//#include <sys/wait.h>

int main()
{
	int socket_serveur;
	int socket_client;
	char message[1024]= "";
	socket_serveur = creer_serveur(8080);
	

	

	socket_client=accept(socket_serveur, NULL, NULL);
	if(socket_client == -1)
	
	{
		perror("accept");
	}
	
	const char *message_bienvenue = "bonjour, bienvenue sur mon serveur\n";

	sleep(3);

	write(socket_client, message_bienvenue, strlen(message_bienvenue));
	
	while(1){

		int i= read(socket_client, message, 1023);
		if(i != -1){
			write(socket_client, message, i);
		}
		else{
			write(socket_client, message, strlen(message));
		}
		
	}
	return 0;
	
	


}
		