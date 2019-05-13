void printFastestRoute(int socket_fd){

	Route* fastestRoute = (Route*)malloc(sizeof(Route));

	read(socket_fd, fastestRoute, sizeof(Route));

	printf("Fastest route: %f", fastestRoute->duration);
}
