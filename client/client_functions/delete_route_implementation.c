void deleteRoute(int socket_fd){
	char destination[50];
	printf("\n");

	DeleteRouteData routeToDelete;
	printf("Enter start destination\n");
	fgets(destination, sizeof(destination),stdin);
	strcpy(routeToDelete.startDestination, destination);
	routeToDelete.startDestination[strlen(destination)] = '\0';
	(routeToDelete.startDestination)[strcspn(routeToDelete.startDestination,"\n")]='\0';

	printf("Enter end destination\n");
	fgets(destination, sizeof(destination),stdin);
	strcpy(routeToDelete.endDestination, destination);
	routeToDelete.endDestination[strlen(destination)] = '\0';
	(routeToDelete.endDestination)[strcspn(routeToDelete.endDestination,"\n")]='\0';

	printf("\n");
	write(socket_fd, &routeToDelete, sizeof(DeleteRouteData));
}
