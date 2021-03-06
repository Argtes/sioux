#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "socket.h"
#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>
#include "string.h"
#include <arpa/inet.h>
#include <netinet/in.h>
#include <netinet/ip.h>

int socket_serveur;
int socket_client;
char message[1024]= "";
char strToken[1024]="";
int cptToken=0;
//http_request testGet = {HTTP_GET,0,0,NULL};

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
      
      //const char *message_bienvenue = "bonjour, bienvenue sur mon serveur\n";
      const char *message_BadRequest = "\nHTTP/1.1 400 Bad Request \nConnection: close \nContent-Length: 17 \n\n400 Bad request\n";
      //write(socket_client, message_bienvenue, strlen(message_bienvenue));
        
      FILE * f;
      f = fdopen(socket_client, "w+");

      if(fgets(message, sizeof(message), f)){
        strcpy(strToken, message);
        char * token = strtok(message, " ");;
        int err=0;
        while(token){
          
          cptToken++;
          if(!(cptToken == 1 && strcmp(token,"GET")==0 )){
            err = err -1;
            
          }else if(!((cptToken == 3) && ((strcmp(token, "HTTP/1.1\r\n")==0) || (strcmp(token, "HTTP/1.0\r\n")==0)))){
            err = err -1;
            
          }

          token = strtok(NULL, " ");

        }

        if(err < 0 ){
        write(socket_client, message_BadRequest, strlen(message_BadRequest));
        }else{
           write(socket_client, "ok", 2);
        }

      }else{
        close(socket_client);

      }
      exit(0);
    }  
  }
return 0; 
}