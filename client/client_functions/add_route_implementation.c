Route initializeRoute(){
	Route route;
	char destination[50];
	char floatNumber[20];

	printf("Enter start destination\n");
	fgets(destination, sizeof(destination),stdin);
	strcpy(route.startDestination, destination);
	route.startDestination[strlen(destination)] = '\0';
	(route.startDestination)[strcspn(route.startDestination,"\n")]='\0';

	printf("Enter end destination\n");
	fgets(destination, sizeof(destination),stdin);
	strcpy(route.endDestination, destination);
	route.endDestination[strlen(destination)] = '\0';
	(route.endDestination)[strcspn(route.endDestination,"\n")]='\0';

	printf("Enter distance\n");
	fgets(floatNumber, sizeof(floatNumber), stdin);
	route.distance = atof(floatNumber);

	printf("Enter duration\n");
	fgets(floatNumber, sizeof(floatNumber), stdin);
	route.duration = atof(floatNumber);
	fflush(stdin);
	return route;
}

void addNewRoute(int socket_fd){
	Route newRoute = initializeRoute();
	write(socket_fd, &newRoute, sizeof(Route));
}
