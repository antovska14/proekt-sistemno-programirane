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

#include "../structures/route.h"
#include "../structures/delete_route_data.h"

#include "client_prototypes.h"

#include "client_functions/print_routes.c"
#include "client_functions/fastest_route_print.c"
#include "client_functions/shortest_route_print.c"
#include "client_functions/add_route_implementation.c"
#include "client_functions/delete_route_implementation.c"
#include "client_functions/client_tcp_socket_implementation.c"

int main(){
	int socket_fd = createSocket();
	connectToServer(socket_fd);

	serverComunicationService(socket_fd);

	close(socket_fd);
	return 0;
}
