void printShortestRoute(int socket_fd){

	Route* shortestRoute = (Route*)malloc(sizeof(Route));

	read(socket_fd, shortestRoute, sizeof(Route));

	printf("Shortest route: %f", shortestRoute->distance);
}
