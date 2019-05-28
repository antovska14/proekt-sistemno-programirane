void printRoutes(int socket_fd){
	Route route;
	printf("\nAll routes:\n");
	while(1) {
		read(socket_fd, &route, sizeof(Route));
		if(strcmp(route.startDestination, "end") == 0) {
			break;
		}

		printf("%s -> %s %gkm %gmin\n", route.startDestination, route.endDestination, route.distance, route.duration);
		memset(&route, 0, sizeof(Route));
	}
	printf("\n");
}
