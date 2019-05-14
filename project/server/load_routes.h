void loadRoutesFromDatabase(){
	MYSQL_RES* result;
	MYSQL_ROW row;

	char* selectAllQuery = "SELECT * FROM ROUTES";
	head = NULL;


	if((mysql_query(mysql_connection, selectAllQuery))) {
		printf("%s\n", mysql_error(mysql_connection));
	}
	result = mysql_use_result(mysql_connection);

	printf("\nRoutes:\n");
	while ((row = mysql_fetch_row(result))) {

		RoutesList* newNode = (RoutesList*)malloc(sizeof(RoutesList));
		newNode->route = (Route*)malloc(sizeof(Route));

		newNode->route->startDestination = malloc(strlen(row[1]+1));
		strcpy(newNode->route->startDestination, row[1]);
		newNode->route->startDestination[strlen(row[1])]='\0';

		newNode->route->endDestination = malloc(strlen(row[2]+1));
		strcpy(newNode->route->endDestination, row[2]);
		newNode->route->endDestination[strlen(row[2])]='\0';

		newNode->route->distance = atof(row[3]);
		newNode->route->duration = atof(row[4]);

		newNode->next = head;
		head = newNode;

		printf("%s -> %s %gkm %gmin \n", newNode->route->startDestination, newNode->route->endDestination, newNode->route->distance, newNode->route->duration);
		printf("\n");
	}

	mysql_free_result(result);
}
