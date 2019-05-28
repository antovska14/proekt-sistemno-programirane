void deleteRouteFromDatabase(char* startDestination, char* endDestination){
	char deleteQuery[255];
	snprintf(deleteQuery, sizeof deleteQuery, "DELETE FROM ROUTES WHERE startDestination='%s' AND endDestination='%s'", startDestination, endDestination);
	if((mysql_query(mysql_connection, deleteQuery))) {
		printf("%s\n", mysql_error(mysql_connection));
	}
}

void deleteRouteFromRoutesList(char* startDestination, char* endDestination){
	RoutesList* current = head;
	RoutesList* previous = current;
	RoutesList* nodeToDelete = NULL;
	while( current != NULL) {
		if( strcmp(current->route.startDestination, startDestination) == 0
		    && strcmp(current->route.endDestination, endDestination) == 0 ) {
			nodeToDelete = current;
			break;
		}

		previous = current;
		current = current->next;
	}

	if(nodeToDelete == head) {
		head = nodeToDelete->next;
	}else{
		previous->next = nodeToDelete->next;
	}

	if( nodeToDelete != NULL) {
		free(nodeToDelete);
	}
}

void deleteRoute(int client_connection_fd){
	DeleteRouteData route;
	read(client_connection_fd, &route, sizeof(DeleteRouteData));
	deleteRouteFromDatabase(route.startDestination, route.endDestination);
	deleteRouteFromRoutesList(route.startDestination, route.endDestination);
}
