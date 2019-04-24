void deleteRouteFromDatabase(char* startDestination, char* endDestination){
	char deleteQuery[255];
	snprintf(deleteQuery, sizeof deleteQuery, "DELETE FROM ROUTES WHERE startDestination='%s' AND endDestination='%s'", startDestination, endDestination);
	if((mysql_query(mysql_connection, deleteQuery))){
		printf("%s\n", mysql_error(mysql_connection));
	}	
}

void deleteRouteFromRoutesList(char* startDestination, char* endDestination){
	RoutesList* current = head;
	RoutesList* previous = current;	
	RoutesList* nodeToDelete = NULL;
	while( current != NULL){
		if( strcmp(current->route.startDestination, startDestination) == 0 
		 && strcmp(current->route.endDestination, endDestination) == 0 ){
			nodeToDelete = current;	
			break;	
		}
		previous = current;
		current = current -> next;	
	}

	if(nodeToDelete == head){
		head = nodeToDelete -> next;	
	}else{			
		previous->next = nodeToDelete->next;
	}

	if( nodeToDelete != NULL){
		free(nodeToDelete);
		nodeToDelete = NULL;	
	}
}

void deleteRoute(){
	char startDestination[DESTINATION_NAME_LENGTH];
	char endDestination[DESTINATION_NAME_LENGTH];
	
	printf("\nEnter information about the route you want to delete");
	printf("\nEnter start destination:");
	fgets(startDestination, sizeof(startDestination), stdin);
	startDestination[strcspn(startDestination,"\n")]='\0';
	printf("\nEnter end destination:");
	fgets(endDestination, sizeof(endDestination), stdin);
	endDestination[strcspn(endDestination,"\n")]='\0';
	
	deleteRouteFromDatabase(startDestination, endDestination);	
	deleteRouteFromRoutesList(startDestination, endDestination);
}
