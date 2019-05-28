void addRouteToDatabase(Route newRoute){
	char addRouteQuery[255];
	//calls a procedure, which adds a route if it's not existant or updates if the new one is faster
	snprintf(addRouteQuery, sizeof addRouteQuery, "CALL ADD_ROUTE('%s', '%s', %f, %f);"
	         ,newRoute.startDestination, newRoute.endDestination, newRoute.distance, newRoute.duration);
	if((mysql_query(mysql_connection, addRouteQuery))) {
		printf("%s\n", mysql_error(mysql_connection));
	}
}

int compareRoutes(Route route1, Route route2){
	if(strcmp(route1.startDestination,route2.startDestination) == 0
	   && strcmp(route1.endDestination,route2.endDestination) == 0
	   && route1.distance == route2.distance
	   && route1.duration == route2.duration) {
		return 0;
	}

	return -1;
}

void addRouteToRoutesList(Route newRoute){
	RoutesList* current = head;
	//checks if route allready exists
	while( current != NULL) {
		//returns zero if routes are equal
		if( compareRoutes(current->route, newRoute) == 0 ) {
			if(current->route.duration > newRoute.duration) {
				current->route.duration = newRoute.duration;
			}
			//function exit, no need to add route to routes list as it allready exists
			return;
		}

		current = current->next;
	}

	RoutesList* newNode = (RoutesList*)malloc(sizeof(RoutesList));

	strcpy(newNode->route.startDestination, newRoute.startDestination);
	newNode->route.startDestination[strlen(newRoute.startDestination)] = '\0';

	strcpy(newNode->route.endDestination, newRoute.endDestination);
	newNode->route.endDestination[strlen(newRoute.endDestination)] = '\0';

	newNode->route.distance = newRoute.distance;
	newNode->route.duration = newRoute.duration;

	newNode->next = head;
	head = newNode;
}

void addNewRoute(int client_connection_fd){
	Route newRoute;
	read(client_connection_fd, &newRoute, sizeof(Route));
	addRouteToDatabase(newRoute);
	addRouteToRoutesList(newRoute);
}
