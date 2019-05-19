void printShortestRoute(int socket_fd){
	Route shortestRoute;

	read(socket_fd, &shortestRoute, sizeof(Route));

	printf("Shortest route: %f\n", shortestRoute.distance);
}
