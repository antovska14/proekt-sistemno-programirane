Route initializeRoute(){
	Route route;
	char destination[50];
	char floatNumber[20];

	printf("\nEnter start destination\n");
	fgets(destination, sizeof(destination),stdin);
	strcpy(route.startDestination, destination);
	route.startDestination[strlen(destination)] = '\0';
	(route.startDestination)[strcspn(route.startDestination,"\n")]='\0';

	printf("\nEnter end destination\n");
	fgets(destination, sizeof(destination),stdin);
	strcpy(route.endDestination, destination);
	route.endDestination[strlen(destination)] = '\0';
	(route.endDestination)[strcspn(route.endDestination,"\n")]='\0';

	printf("\nEnter distance\n");
	fgets(floatNumber, sizeof(floatNumber), stdin);
	route.distance = atof(floatNumber);

	printf("\nEnter duration\n");
	fgets(floatNumber, sizeof(floatNumber), stdin);
	route.duration = atof(floatNumber);
	fflush(stdin);

	printf("\n");
	return route;
}

void addNewRoute(int socket_fd){
	Route newRoute = initializeRoute();
	write(socket_fd, &newRoute, sizeof(Route));
}
