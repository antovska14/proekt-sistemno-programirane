Route initializeRoute();
void addNewRoute(int socket_fd);

void deleteRoute(int socket_fd);

void printFastestRoute(int socket_fd);

void printShortestRoute(int socket_fd);

void printMenu();
int createSocket();
void connectToServer(int socket_fd);
void serverComunicationService(int socket_fd);
