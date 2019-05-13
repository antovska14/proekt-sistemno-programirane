void getFastestRoute(int client_connection_fd){
	RoutesList* fastestRoute = head;
	RoutesList* currentRoute = head->next;
	while( currentRoute != NULL) {
		if(currentRoute->route.duration < fastestRoute->route.duration) {
			fastestRoute = currentRoute;
		}
		currentRoute = currentRoute->next;
	}
	write(client_connection_fd, &(fastestRoute->route), sizeof(fastestRoute->route));
}
