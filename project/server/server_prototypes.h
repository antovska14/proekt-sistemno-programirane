void connectToDatabase();

void loadRoutesFromDatabase();

void addRouteToDatabase(Route newRoute);
int compareRoutes(Route route1, Route route2);
void addRouteToRoutesList(Route newRoute);
void addNewRoute(int client_connection_fd);

void deleteRouteFromDatabase(char* startDestination, char* endDestination);
void deleteRouteFromRoutesList(char* startDestination, char* endDestination);
void deleteRoute();

void getFastestRoute(int client_connection_fd);

void getShortestRoute(int client_connection_fd);

int connectToClient(int socket_fd);
void makeServerListening(int socket_fd);
struct sockaddr_in initializeServer();
void bindServerToLocalHost(int socket_fd, struct sockaddr_in serverAddress);
int createSocket();
void clientComunicationService(int client_connection_fd);
