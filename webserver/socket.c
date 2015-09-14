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

	perror("socket_serveur");

	}

	struct sockaddr_in saddr;
	saddr.sin_family = AF_INET;
	saddr.sin_port = htons(8080);
	saddr.sin_addr.s_addr = INADDR8ANY;

	if (bind(socket_serveur, (struct sockaddr *)&saddr, sizeof(saddr)) == -1)
	{
		perror("bind socket_serveur");
	}	
	

	
	if (listen(socket_serveur, 10) == -1){
		perror("listen socket_serveur");
	}




	return 0;
}



