//database
//database_conection.c
void connectToDatabase();
//load_routes.c
void loadRoutesFromDatabase();

//service
//add_route.c
void addRouteToDatabase(Route newRoute);
int compareRoutes(Route route1, Route route2);
void addRouteToRoutesList(Route newRoute);
void addNewRoute(int client_connection_fd);
//delete_route.c
void deleteRouteFromDatabase(char* startDestination, char* endDestination);
void deleteRouteFromRoutesList(char* startDestination, char* endDestination);
void deleteRoute();
//fastest_route.c
void getFastestRoute(int client_connection_fd);
//shortest_route.c
void getShortestRoute(int client_connection_fd);

//comunication
//server_tcp_socket_implementation.c
int connectToClient(int socket_fd);
void makeServerListen(int socket_fd);
struct sockaddr_in initializeServer();
void bindServerToLocalHost(int socket_fd, struct sockaddr_in serverAddress);
int createSocket();
void clientComunicationService(int client_connection_fd);
