void printRoutes(){
	RoutesList* current = head;
	while(current != NULL) {
		printf("%s -> %s %gkm %gmin \n", current->route->startDestination, current->route->endDestination, current->route->distance, current->route->duration);
		current = current->next;
	}
}
