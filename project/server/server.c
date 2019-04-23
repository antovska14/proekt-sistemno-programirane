#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <mysql/mysql.h>
#include <sys/socket.h> 
#include <netinet/in.h> 
#include <unistd.h> 

#define PORT 8080
#define DESTINATION_NAME_LENGTH 50
MYSQL* mysql_connection;

#include "../structures/route.h"
#include "../structures/route_list.h"

#include "add_route.h"
#include "delete_route.h"
#include "shortest_route.h"
#include "fastest_route.h"
#include "print_routes.h"

#include "database_connection.h"
#include "server_tcp_socket_implementation.h"


int main(){
	connectToDatabase();
	
	int socket_fd = createSocket();

	struct sockaddr_in serverAddress = initializeServer();	
	bindServerToLocalHost(socket_fd, serverAddress);
	makeServerListening(socket_fd);

	int client_connection_fd = connectToClient(socket_fd);
	respondToClient(client_connection_fd);

	close(socket_fd);
	mysql_close(mysql_connection);
	return 0;
}


