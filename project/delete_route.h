void deleteRoute(){

	char startDestination[DESTINATION_NAME_LENGTH];
	char endDestination[DESTINATION_NAME_LENGTH];
	
	printf("\nEnter information about the route you want to delete");
	printf("\nEnter start destination:");
	getchar();
	fgets(startDestination, sizeof startDestination, stdin);
	startDestination[strcspn(startDestination,"\n")]='\0';
	printf("\nEnter end destination:");
	fgets(endDestination, sizeof endDestination, stdin);
	endDestination[strcspn(endDestination,"\n")]='\0';
	
	char deleteQuery[255];

	snprintf(deleteQuery, sizeof deleteQuery, "DELETE FROM ROUTES WHERE startDestination='%s' AND endDestination='%s'", startDestination, endDestination);
	
	if((mysql_query(connection, deleteQuery))){
		printf("%s\n", mysql_error(connection));
	}
}
