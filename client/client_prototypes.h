//add_route_implemetation.c
Route initializeRoute();
void addNewRoute(int socket_fd);

//delete_route_implementation.c
void deleteRoute(int socket_fd);

//fastest_route_print.c
void printFastestRoute(int socket_fd);

//shortest_route_print.c
void printShortestRoute(int socket_fd);

//print_routes.case
void printRoutes(int socket_fd);

//client_ctp_socket_implementation.c
void printMenu();
int createSocket();
void connectToServer(int socket_fd);
void serverComunicationService(int socket_fd);
