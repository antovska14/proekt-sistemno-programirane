void getShortestRoute(){
	MYSQL_RES* result;
	MYSQL_ROW shortestDistanceRow;
	char findShortestRouteQuery[255];
	char printShortestRouteQuery[255];
	float shortestDistance;

	snprintf(findShortestRouteQuery, sizeof findShortestRouteQuery, "SELECT MIN(distance) FROM ROUTES");
		
	if((mysql_query(connection, findShortestRouteQuery))){
		printf("%s\n", mysql_error(connection));
	}
	result = mysql_use_result(connection);
	shortestDistanceRow = mysql_fetch_row(result);
	shortestDistance = atoi(shortestDistanceRow[0]);
	mysql_free_result(result);
	
	snprintf(printShortestRouteQuery, sizeof printShortestRouteQuery, "SELECT * FROM ROUTES WHERE distance='%g';",shortestDistance);
	if((mysql_query(connection, printShortestRouteQuery))){
		printf("%s\n", mysql_error(connection));
	}
	result = mysql_use_result(connection);
	shortestDistanceRow = mysql_fetch_row(result);
	printf("\nShortest route:");
	printf("\n%s -> %s %skm %smin\n\n",shortestDistanceRow[1],shortestDistanceRow[2],shortestDistanceRow[3],shortestDistanceRow[4]);
	mysql_free_result(result);
}
