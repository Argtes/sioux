#include <stdio.h>
#include <string.h>
#include "socket.h"
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>
#include "string.h"

int socket_serveur;
int socket_client;
char message[1024]= "";
char strToken[1024]="";
int cptToken=0; 
int curlOK= 1;


//en 8.2 git tag stats => 20
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
		

<<<<<<< HEAD
    int pid = fork();
    if (pid == 0){
      
      const char *message_bienvenue = "bonjour, bienvenue sur mon serveur\n";

      write(socket_client, message_bienvenue, strlen(message_bienvenue));
			
      FILE * f;
      f = fdopen(socket_client, "w+");
				
      if(fgets(message, /*sizeof(message)*/100, f)){
	strcpy(strToken, message);
	char * token = strtok(message, " ");;
	while(token){
	  cptToken++;
	  if(!(cptToken == 1 && strcmp(token,"GET")==0 )){
	    curlOK= 0;
	    printf("%s bonjour\n", token);

	  }

	  if(!((cptToken == 3) && ((strcmp(token, "HTTP/1.1\r\n")==0) || (strcmp(token, "HTTP/1.0\r\n")==0)))){
	    curlOK= 0;

	  }

	  token = strtok(NULL, " ");

	}

      }
      /*

=======
		int pid = fork();
		if (pid == 0){


			const char *message_bienvenue = "bonjour, bienvenue sur mon serveur\n";


			write(socket_client, message_bienvenue, strlen(message_bienvenue));
			
			FILE * f;
			f = fdopen(socket_client, "w+");
				
			if(fgets(message, sizeof(message), f)){
				strcpy(strToken, message);
				char * token= strtok(message, " ");
				while(token){
					cptToken++;
					if(!(cptToken == 1 && strcmp(token,"GET")==0 )){
						curlOK= 0;
					}

					if(!((cptToken == 3) && ((strcmp(token, "HTTP/1.1\r\n")==0) || (strcmp(token, "HTTP/1.0\r\n")==0)))){
						curlOK= 0;
					}
					strtok(NULL, " ");
				}

			}
/*
				while(fgets(message, sizeof(message), f) != NULL){
>>>>>>> 37d135048bb1e5d10f5fa06e03e303bd64007cdf

	while(fgets(message, sizeof(message), f) != NULL){

	printf("<Sioux> %s", message);

	if(strncmp(message,"GET ",4) == 0){
	printf("ok ma guele c'est ok\n");
	}else{
	printf("pas ok ma gueule c'est pas ok\n");

<<<<<<< HEAD
	}
=======
				}*/
			else{
				close(socket_client);
			}
		}
>>>>>>> 37d135048bb1e5d10f5fa06e03e303bd64007cdf

	}*/
			
      else{
	close(socket_client);
      }
      //utiliser str [strtok]
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
	
	


<<<<<<< HEAD
  }
}
=======
	}
}
>>>>>>> 37d135048bb1e5d10f5fa06e03e303bd64007cdf
