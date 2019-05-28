void printFastestRoute(int socket_fd){
	Route fastestRoute;
	read(socket_fd, &fastestRoute, sizeof(Route));

	printf("\nFastest route:\n");
	printf("%s -> %s %gkm %gmin\n\n", fastestRoute.startDestination, fastestRoute.endDestination, fastestRoute.distance, fastestRoute.duration);
}
