#ifndef __SOCKET_H__
#define __SOCKET_H__




int creer_serveur(int port);
void initialiser_signaux(void);
void traitement_signal(int sig);
char *fgets_or_exit(char *buffer, int size, FILE *stream);
//int parse_http_request(const char *request_line, http_request *request);
char * rewrite_url(char *url);
void skip_headers(FILE *client);
void send_status(FILE *client ,int code ,const char *reason_phrase);
void send_response(FILE *client, int code, const char *reason_phrase, const char *message_body);

#endif
