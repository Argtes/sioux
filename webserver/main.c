#include <stdio.h>
#include <string.h>
#include "socket.h"
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>


int socket_serveur;
int socket_client;
char message[1024]= ""; 

int main()
{
	socket_serveur = creer_serveur(8080);
	initialiser_signaux();

	while (1){
		socket_client=accept(socket_serveur, NULL, NULL);
		if(socket_client == -1)
		
		{
			perror("accept");
		}
		

		int pid = fork();
			if (pid == 0){


				const char *message_bienvenue = "bonjour, bienvenue sur mon serveur\n";


				write(socket_client, message_bienvenue, strlen(message_bienvenue));
			
				FILE * f;
				f = fdopen(socket_client, "w+");
				while(fgets(message, sizeof(message), f) != NULL){
					printf("<Sioux> %s", message);
				}
			}
			else{
				close(socket_client);
			}
	}
/*	
	while(1){

		int i= read(socket_client, message, 1023);
		if(i != -1){
			write(socket_client, message, i);
		}
		else{
			write(socket_client, message, strlen(message));
		}
		
	}
*/	
	return 0;
	
	


}
		