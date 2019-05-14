Route* initializeRoute(){
	Route* route = (Route*)malloc(sizeof(Route));
	char destination[50];
	fflush(stdin);
	printf("Enter start destination\n");
	fgets(destination, sizeof(destination),stdin);
	route->startDestination = (char*)malloc(strlen(destination)+1);
	strcpy(route->startDestination, destination);
	route->startDestination[strlen(destination)] = '\0';
	(route->startDestination)[strcspn(route->startDestination,"\n")]='\0';
	printf("Enter end destination\n");
	fgets(destination, sizeof(destination),stdin);
	route->endDestination = (char*)malloc(strlen(destination)+1);
	strcpy(route->endDestination, destination);
	route->endDestination[strlen(destination)] = '\0';
	(route->endDestination)[strcspn(route->endDestination,"\n")]='\0';
	printf("Enter distance\n");
	scanf("%f", &route->distance);
	printf("Enter duration\n");
	scanf("%f", &route->duration);
	printf("\n");
	return route;
}

void addNewRoute(int socket_fd){
	Route* newRoute = initializeRoute();
	write(socket_fd, &newRoute, sizeof(newRoute));
}
