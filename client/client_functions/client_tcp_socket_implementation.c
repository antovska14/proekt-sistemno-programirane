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

int createSocket(){
	int socket_fd = socket(AF_INET, SOCK_STREAM, 0);
	if (socket_fd == -1) {
		printf("socket creation failed...\n");
		exit(0);
	} else{
		printf("Socket successfully created..\n");
	}
	return socket_fd;
}

void connectToServer(int socket_fd){
	struct sockaddr_in serverAddress;
	bzero(&serverAddress, sizeof(serverAddress));

	serverAddress.sin_family = AF_INET;
	serverAddress.sin_addr.s_addr = inet_addr("127.0.0.1");
	serverAddress.sin_port = htons(PORT);

	if (connect(socket_fd, (struct sockaddr*)&serverAddress, sizeof(serverAddress)) != 0) {
		printf("connection with the server failed...\n");
		exit(0);
	}       else{
		printf("connected to the server..\n");
	}
}

void serverComunicationService(int socket_fd){
	int n;
	int option;
	char optionString[20];
	while(1) {
		printf("Enter one of the following options:\n");
		printMenu();
		fgets(optionString, sizeof(optionString), stdin);
		option = atoi(optionString);
		write(socket_fd, &option, sizeof(int));
		switch (option) {
		case 1: addNewRoute(socket_fd); break;
		case 2: deleteRoute(socket_fd); break;
		case 3: printFastestRoute(socket_fd); break;
		case 4: printShortestRoute(socket_fd); break;
		case 5: printRoutes(socket_fd); break;
		case 6: printf("Program exit"); break;
		default: printf("Option does not exist"); break;
		}
		if( option == 6) {
			printf("Client exit");
			break;
		}
	}
}
