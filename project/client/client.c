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

void printMenu();

	int socket_fd = createSocket();
	connectToServer();  
    
	sendToServer(socket_fd); 
  
	close(socket_fd); 
	return 0;
}



void printMenu(){
	printf("\n");
	printf("1. Add new route\n");
	printf("2. Delete existing route\n");
	printf("3. Get fastest route\n");
	printf("4. Get shortest route\n");
	printf("5. Print all routes\n");
	printf("6. Exit\n");
	printf("\n");
}
