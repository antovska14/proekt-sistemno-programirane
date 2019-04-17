void getFastestRoute(){
	MYSQL_RES* result;
	MYSQL_ROW fastestRouteRow;
	char findFastestRouteQuery[255];
	char printFastestRouteQuery[255];
	float fastestRoute;

	snprintf(findFastestRouteQuery, sizeof findFastestRouteQuery, "SELECT MIN(duration) FROM ROUTES");
		
	if((mysql_query(connection, findFastestRouteQuery))){
		printf("%s\n", mysql_error(connection));
	}
	result = mysql_use_result(connection);
	fastestRouteRow = mysql_fetch_row(result);
	fastestRoute = atoi(fastestRouteRow[0]);
	mysql_free_result(result);
	
	snprintf(printFastestRouteQuery, sizeof printFastestRouteQuery, "SELECT * FROM ROUTES WHERE 			duration='%g';",fastestRoute);
	if((mysql_query(connection, printFastestRouteQuery))){
		printf("%s\n", mysql_error(connection));
	}
	result = mysql_use_result(connection);
	fastestRouteRow = mysql_fetch_row(result);
	printf("\nFastest route:");
	printf("\n%s -> %s %skm %smin\n\n",fastestRouteRow[1],fastestRouteRow[2],fastestRouteRow[3],fastestRouteRow[4]);
	mysql_free_result(result);
}
