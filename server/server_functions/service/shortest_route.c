void getShortestRoute(int client_connection_fd){
	RoutesList* shortestRoute = head;
	RoutesList* currentRoute = head->next;

	while( currentRoute != NULL) {
		if(currentRoute->route.distance < shortestRoute->route.distance) {
			shortestRoute = currentRoute;
		}
		currentRoute = currentRoute->next;
	}
	write(client_connection_fd, &(shortestRoute->route), sizeof(shortestRoute->route));
}
