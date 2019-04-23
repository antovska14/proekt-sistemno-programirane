void initializeRoute(Route* route){
	printf("Enter start destination\n");
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

void addNewRoute(){
	Route newRoute;	
	initializeRoute(&newRoute);
	
	char addRouteQuery[255];
	snprintf(addRouteQuery, sizeof addRouteQuery, "CALL ADD_ROUTE('%s', '%s', %f, %f);"
,newRoute.startDestination, newRoute.endDestination, newRoute.distance, newRoute.duration);
		
	if((mysql_query(mysql_connection, addRouteQuery))){
		printf("%s\n", mysql_error(mysql_connection));
	}
}

