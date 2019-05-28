void printShortestRoute(int socket_fd){
	Route shortestRoute;
	read(socket_fd, &shortestRoute, sizeof(Route));

	printf("\nShortest route:\n");
	printf("%s -> %s %gkm %gmin\n\n", shortestRoute.startDestination, shortestRoute.endDestination, shortestRoute.distance, shortestRoute.duration);
}
