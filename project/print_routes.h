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
