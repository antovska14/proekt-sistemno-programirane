#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <mysql/mysql.h>
#include <sys/socket.h> 
#include <netinet/in.h> 
#include <unistd.h> 

#define PORT 8080
#define DESTINATION_NAME_LENGTH 50
MYSQL* connection;

#include "route.h"
#include "add_route.h"
#include "delete_route.h"
#include "shortest_route.h"
#include "fastest_route.h"
#include "print_routes.h"

char* server = "localhost";
char* user = "root";
char* password = "melita1993";
char* database = "routes_database"; 

void connectToDatabase();
void respondToClient(int socket_fd);

int main(){
	connectToDatabase();

	int socket_fd, connection_fd, len;
	struct sockaddr_in serverAddress, clientAddress;

	socket_fd = socket(AF_INET, SOCK_STREAM, 0);
	if(socket_fd == -1){
		printf("Socket creation failed...\n");
		exit(0);	
	}else{
		printf("Socket successfully created\n");
	}

	bzero(&serverAddress, sizeof(serverAddress));
	
	serverAddress.sin_family = AF_INET;
	serverAddress.sin_addr.s_addr = htonl(INADDR_ANY);
	serverAddress.sin_port = htons(PORT);

	if ((bind(socket_fd, (struct sockaddr*)&serverAddress, sizeof(serverAddress))) != 0) { 
        printf("Socket bind failed...\n"); 
        exit(1); 
    } 
    else{
        printf("Socket successfully binded..\n"); 
  	}

	if ((listen(socket_fd, 5)) != 0) { 
        printf("Listen failed...\n"); 
        exit(0); 
    } 
    else{
        printf("Server listening..\n"); 
	}	

	len = sizeof(clientAddress);

	connection_fd = accept(socket_fd, (struct sockaddr*)&clientAddress, &len);
	if(connection_fd<0){
		printf("Server accept failed\n");
		exit(3);
	}else{
		printf("Server accepted the client\n");
	}

	respondToClient(connection_fd);

	close(socket_fd);
	mysql_close(connection);
	return 0;
}

void respondToClient(int socket_fd){
	char buffer[30];
	int n;

	int option;

	while(1){
		read(socket_fd, &option, sizeof(int)); 

		bzero(buffer, 30); 
		switch(option)
		{
			case 1: addNewRoute();break;
			case 2: deleteRoute();break;
			case 3: getFastestRoute();break;
			case 4:	getShortestRoute();break;
			case 5: printRoutes();break;
			case 6: printf("Program closed\n");break;	
			default: printf("Option does not exist\n");break;	
		}

		write(socket_fd, buffer, sizeof(buffer)); 	
		
		if( option == 6){
			printf("Server exit");	
			break;
		}
	}
}

void connectToDatabase(){
	connection=mysql_init(NULL);
	if (!(mysql_real_connect(connection, server, user, password, database, 0, NULL, 0))) {
	printf("%s\n", mysql_error(connection));
	}
}


