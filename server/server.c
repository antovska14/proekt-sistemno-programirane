#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <mysql/mysql.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>

#define PORT 8080
#define DESTINATION_NAME_LENGTH 50

#include "../structures/route.h"
#include "../structures/routes_list.h"
#include "../structures/delete_route_data.h"
RoutesList* head;

#include "server_prototypes.h"
MYSQL* mysql_connection;

#include "server_functions/database/load_routes.c"
#include "server_functions/service/add_route.c"
#include "server_functions/service/delete_route.c"
#include "server_functions/service/shortest_route.c"
#include "server_functions/service/fastest_route.c"
#include "server_functions/service/print_routes.c"

#include "server_functions/database/database_connection.c"
#include "server_functions/comunication/server_tcp_socket_implementation.c"

int main(){
	connectToDatabase();

	int socket_fd = createSocket();

	struct sockaddr_in serverAddress = initializeServer();
	bindServerToLocalHost(socket_fd, serverAddress);
	makeServerListen(socket_fd);

	int client_connection_fd = connectToClient(socket_fd);
	clientComunicationService(client_connection_fd);

	close(socket_fd);
	mysql_close(mysql_connection);
	return 0;
}
