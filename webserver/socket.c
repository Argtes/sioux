#include <stdio.h>
#include <string.h>
#include "socket.h"
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <signal.h>
#include <sys/wait.h>

int creer_serveur(int port){

	int socket_serveur;
	int optval =1;

	socket_serveur = socket(AF_INET, SOCK_STREAM, 0);
	
	if (socket_serveur == -1){
	perror("socket_serveur");

	}

	struct sockaddr_in saddr;
	saddr.sin_family = AF_INET;
	saddr.sin_port = htons(port);
	saddr.sin_addr.s_addr = INADDR_ANY;


	if (setsockopt(socket_serveur, SOL_SOCKET, SO_REUSEADDR, &optval, sizeof(int)) == -1){
		perror("Can not set SO_REUSEADDR option");
	}
	if (bind(socket_serveur, (struct sockaddr *)&saddr, sizeof(saddr)) == -1){
		perror("bind socket_serveur");
	}	

	if (listen(socket_serveur, 10) == -1){
		perror("listen socket_serveur");
	}
	return socket_serveur;

}

void traitement_signal(int sig){
	printf("Signal %d reçu\n", sig);
	int status;
	waitpid(-1, &status, WNOHANG);
}

void initialiser_signaux(void){
	struct sigaction sa;
	sa.sa_handler = traitement_signal;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_RESTART;
	if (sigaction(SIGCHLD , &sa, NULL) == -1)
	{
		perror("sigaction(SIGCHLD)");
	}


//--------------------------------------------------------------------------------------------------------------//

	enum http_method{
		HTTP_GET,
 		HTTP_UNSUPPORTED,
	};

	/*typedef struct{
  		enum http_method method;
  		int major_version;
  		int minor_version;
  		char *url;
	} http_request;*/

	char *fgets_or_exit(char *buffer, int size, FILE *stream) {
  		if( fgets(buffer, size, stream) == NULL){ 
    		printf("Erreur!\n");
    		//exit(1); 
  		}
  		return "";
	}


	// a finir
	/*void parse_http_request (const char *request_line, http_request *request){
		strcpy(strToken, message);
        char * token = strtok(message, " ");;
        
        while(token){
          
          cptToken++;
          if(!(cptToken == 1 && strcmp(token,"GET")==0 )){
            write(socket_client, message_BadRequest, strlen(message_BadRequest));
            
          }else if(!((cptToken == 3) && ((strcmp(token, "HTTP/1.1\r\n")==0) || (strcmp(token, "HTTP/1.0\r\n")==0)))){
            write(socket_client, message_BadRequest, strlen(message_BadRequest));
          }

          token = strtok(NULL, " ");

        }
    }*/


	void skip_headers(FILE *client){
	  char token[1024];
	  while(fgets(token,1024,client)!=NULL && token[0] != '\r' && token[0]!= '\n' );
	}

	void send_status(FILE *client, int code, const char *reason_phrase){
 	 char *tmp=" ";
 	 tmp =strdup(reason_phrase);
 	 fprintf(client,"%d : %s",code, tmp);
 	 fflush(client);
	}

	void send_response(FILE *client, int code, const char *reason_phrase, const char *message_body){
  		send_status(client,code,reason_phrase);
 		fprintf(client,"%d \n %s\n",(int)strlen(message_body),message_body);
 		fflush(client);
 		/* a ajouter dans le main.c
 		if (bad_request)
			send_response(client, 400, "Bad Request" ,"Bad request\r\n" );
		else if(request.method == HTTP_UNSUPPORTED)
			send_response(client, 405, "Method Not Allowed" ,"Method Not Allowed\r\n");
		else if(strcmp(request.url, "/") == 0)
			send_response(client, 200, "OK" ,motd );
		else
			send_response(client, 404, "Not Found", "Not Found\r\n");
*/
	}


    //chap 7 fail pdf
  	/*char *rewrite_url(char *url){
  		return strtok(url,"?");
    }*/

}

