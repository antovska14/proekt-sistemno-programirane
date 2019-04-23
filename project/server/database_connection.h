void connectToDatabase(){
	char* SERVER = "localhost";
	char* USER = "root";
	char* PASSWORD = "melita1993";
	char* DATABASE = "routes_database"; 
	mysql_connection=mysql_init(NULL);
	if (!(mysql_real_connect(mysql_connection, SERVER, USER, PASSWORD, DATABASE, 0, NULL, 0))) {
		printf("%s\n", mysql_error(mysql_connection));
	}
}
