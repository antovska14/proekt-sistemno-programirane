void printRoutes(int client_connection_fd){
	RoutesList* current = head;
	while(current != NULL) {
		write(client_connection_fd, &(current->route), sizeof(Route));
		current = current->next;
	}

	char endString[10];
	strcpy(endString, "end");
	write(client_connection_fd, &endString, sizeof(endString));
}
