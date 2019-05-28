void printShortestRoute(int socket_fd){
	Route shortestRoute;
	read(socket_fd, &shortestRoute, sizeof(Route));

	printf("Shortest route:\n");
	printf("%s -> %s %gkm %gmin\n", shortestRoute.startDestination, shortestRoute.endDestination, shortestRoute.distance, shortestRoute.duration);
}
