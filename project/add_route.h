void initializeRoute(Route* route){
	printf("Enter start destination\n");
	getchar();
	fgets(route->startDestination, sizeof route->startDestination,stdin);
	(route->startDestination)[strcspn(route->startDestination,"\n")]='\0';
	printf("Enter end destination\n");	
	fgets(route->endDestination, sizeof route->endDestination,stdin);
	(route->endDestination)[strcspn(route->endDestination,"\n")]='\0';
	printf("Enter distance\n");
	scanf("%f", &route->distance);
	printf("Enter duration\n");
	scanf("%f", &route->duration);
	printf("\n");
}

void printRoute(Route route){
	printf("\n");
	printf("Start destination: %s\n",route.startDestination);
	printf("End destination: %s\n",route.endDestination);
	printf("Distance: %fkm\n", route.distance);
	printf("Duration: %fmin\n", route.duration);
	printf("\n");
}

void addNewRoute(){
	Route newRoute;	
	initializeRoute(&newRoute);
	
	char addRouteQuery[255];
	snprintf(addRouteQuery, sizeof addRouteQuery, "INSERT INTO ROUTES(startDestination, endDestination, distance, duration) VALUES('%s','%s',%f,%f);",newRoute.startDestination, newRoute.endDestination, newRoute.distance, newRoute.duration);
		
	if((mysql_query(connection, addRouteQuery))){
		printf("%s\n", mysql_error(connection));
	}
}

