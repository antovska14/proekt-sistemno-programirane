void printFastestRoute(int socket_fd){
	Route fastestRoute;

	read(socket_fd, &fastestRoute, sizeof(Route));

	printf("Fastest route: %f\n", fastestRoute.duration);
}
