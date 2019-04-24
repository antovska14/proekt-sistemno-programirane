#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <mysql/mysql.h>
#include <sys/socket.h> 
#include <netinet/in.h> 
#include <unistd.h> 
#include <netdb.h> 
#include <arpa/inet.h>

#define PORT 8080

#include "client_tcp_socket_implementation.h"

int main(){
	int socket_fd = createSocket();
	connectToServer(socket_fd);  
    
	sendToServer(socket_fd); 
  
	close(socket_fd); 
	return 0;
}
