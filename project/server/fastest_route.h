void getFastestRoute(){
	MYSQL_RES* result;
	MYSQL_ROW fastestRouteRow;
	char findFastestRouteQuery[255];
	char printFastestRouteQuery[255];
	float fastestRoute;

	snprintf(findFastestRouteQuery, sizeof findFastestRouteQuery, "SELECT MIN(duration) FROM ROUTES");
		
	if((mysql_query(mysql_connection, findFastestRouteQuery))){
		printf("%s\n", mysql_error(mysql_connection));
	}

	result = mysql_use_result(mysql_connection);
	fastestRouteRow = mysql_fetch_row(result);
	fastestRoute = atof(fastestRouteRow[0]);
	mysql_free_result(result);
	
	snprintf(printFastestRouteQuery, sizeof printFastestRouteQuery, "SELECT * FROM ROUTES WHERE 			duration='%g';",fastestRoute);
	if((mysql_query(mysql_connection, printFastestRouteQuery))){
		printf("%s\n", mysql_error(mysql_connection));
	}
	result = mysql_use_result(mysql_connection);
	fastestRouteRow = mysql_fetch_row(result);
	printf("\nFastest route:");
	printf("\n%s -> %s %skm %smin\n\n",fastestRouteRow[1],fastestRouteRow[2],fastestRouteRow[3],fastestRouteRow[4]);
	mysql_free_result(result);
}
