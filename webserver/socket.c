#include <stdio.h>
#include <string.h>
#include "socket.h"
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <signal.h>

int creer_serveur(int port)
{
	port = 8080;
	int socket_serveur;
	int optval =1;
	//int setsockopt(int socket, int level, int option_name, const void *option_value, socklen_t option_len);

	socket_serveur = socket(AF_INET, SOCK_STREAM, 0);
	
	if (socket_serveur == -1)
	{

	perror("socket_serveur");

	}

	struct sockaddr_in saddr;
	saddr.sin_family = AF_INET;
	saddr.sin_port = htons(port);
	saddr.sin_addr.s_addr = INADDR_ANY;


	if (setsockopt(socket_serveur, SOL_SOCKET, SO_REUSEADDR, &optval, sizeof(int)) == -1)
		perror("Can not set SO_REUSEADDR option");


	if (bind(socket_serveur, (struct sockaddr *)&saddr, sizeof(saddr)) == -1)
	{
		perror("bind socket_serveur");
	}	
	

	
	if (listen(socket_serveur, 10) == -1){
		perror("listen socket_serveur");
	}




	return socket_serveur;
}


void initialiser_signaux(void){

	if (signal(SIGPIPE , SIG_IGN) == SIG_ERR)
	{
	perror("sigfkejhz");
	}

}