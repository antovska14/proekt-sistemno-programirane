#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <mysql/mysql.h>

#define DESTINATION_NAME_LENGTH 50
MYSQL* connection;

#include "route.h"
#include "add_route.h"
#include "delete_route.h"
#include "shortest_route.h"


char* server = "localhost";
char* user = "root";
char* password = "melita1993";
char* database = "routes_database"; 



void runProgram();
void printMenu();

int main(){
	connection=mysql_init(NULL);
	if (!(mysql_real_connect(connection, server, user, password, database, 0, NULL, 0))) {
	printf("%s\n", mysql_error(connection));
	}

	runProgram();
	mysql_close(connection);
	return 0;
}

void printRoutes(){
	MYSQL_RES* result;
	MYSQL_ROW row;

	char* selectAllQuery = "SELECT * FROM ROUTES";
	if((mysql_query(connection, selectAllQuery))){
		printf("%s\n", mysql_error(connection));
	}
	result = mysql_use_result(connection);

	printf("\nRoutes:\n");
	while ((row = mysql_fetch_row(result))){
      		printf("%s %s -> %s %skm %smin \n",row[0], row[1], row[2], row[3], row[4]);
	}
	printf("\n");
	mysql_free_result(result);
}

void runProgram(){
	int option;
	do{
		printf("Enter one of the following options:\n");

		printMenu();

		scanf("%d", &option);
		switch(option)
		{
			case 1: addNewRoute();break;
			case 2: deleteRoute();break;
			case 3: break;
			case 4:	getShortestRoute();break;
			case 5: printRoutes();break;
			case 6: printf("Program closed\n");break;	
			default: printf("Option does not exist\n");break;	
		}
	}while(option!=6);
}

void printMenu(){
	printf("\n");
	printf("1. Add new route\n");
	printf("2. Delete existing route\n");
	printf("3. Get fastest route\n");
	printf("4. Get shortest route\n");
	printf("5. Print all routes\n");
	printf("6. Exit\n");
	printf("\n");
}
