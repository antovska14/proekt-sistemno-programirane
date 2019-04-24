Route initializeRoute(){
	Route route;
	printf("Enter start destination\n");
	fgets(route.startDestination, sizeof(route.startDestination),stdin);
	(route.startDestination)[strcspn(route.startDestination,"\n")]='\0';
	printf("Enter end destination\n");	
	fgets(route.endDestination, sizeof(route.endDestination),stdin);
	(route.endDestination)[strcspn(route.endDestination,"\n")]='\0';
	printf("Enter distance\n");
	scanf("%f", &route.distance);
	printf("Enter duration\n");
	scanf("%f", &route.duration);
	printf("\n");
	return route;
}

void addRouteToDatabase(Route newRoute){
	char addRouteQuery[255];
	snprintf(addRouteQuery, sizeof addRouteQuery, "CALL ADD_ROUTE('%s', '%s', %f, %f);"
,newRoute.startDestination, newRoute.endDestination, newRoute.distance, newRoute.duration);
	if((mysql_query(mysql_connection, addRouteQuery))){
		printf("%s\n", mysql_error(mysql_connection));
	}
}

int compareRoutes(Route route1, Route route2){
	if(strcmp(route1.startDestination,route2.startDestination) == 0
	&& strcmp(route1.endDestination,route2.endDestination) == 0
	&& route1.distance == route2.distance
	&& route1.duration == route2.duration){
		return 0;	
	}
	return -1;
}

void addRouteToRoutesList(Route newRoute){
	RoutesList* current = head;
	while( current != NULL){ 
		//returns zero if routes are equal
		if( compareRoutes(current->route, newRoute) == 0 ){
			if(current->route.duration > newRoute.duration){
				current->route.duration = newRoute.duration;			
			}
			return;		
		}
		current = current -> next;
	}

	RoutesList* newNode = (RoutesList*)malloc(sizeof(RoutesList));
	strcpy(newNode->route.startDestination, newRoute.startDestination);
	strcpy(newNode->route.endDestination, newRoute.endDestination);
	newNode->route.distance = newRoute.distance;
	newNode->route.duration = newRoute.duration;
	
	newNode->next = head;
	head = newNode;
}

void addNewRoute(){
	Route newRoute = initializeRoute();
	addRouteToDatabase(newRoute);
	addRouteToRoutesList(newRoute);
}

