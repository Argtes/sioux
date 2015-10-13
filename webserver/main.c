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
int main(){

  socket_serveur = creer_serveur(8080);
  initialiser_signaux();
  
  while (1){
  
    socket_client=accept(socket_serveur, NULL, NULL);
  
    if(socket_client == -1){
      perror("accept");
      
    }
    

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
    else{
      close(socket_client);
    }
  }  
  return 0;
  }
}