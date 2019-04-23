int connectToClient(int socket_fd){
	struct sockaddr_in clientAddress;
	int clientAddressSize = sizeof(clientAddress);
	int client_connection_fd = accept(socket_fd, (struct sockaddr*)&clientAddress, &clientAddressSize);

	if(client_connection_fd<0){
		printf("Server accept failed\n");
		exit(3);
	}else{
		printf("Server accepted the client\n");
	}
}

void makeServerListening(int socket_fd){
	if ((listen(socket_fd, 5)) != 0) { 
        	printf("Listen failed...\n"); 
        	exit(0); 
    	} 
    	else{
        	printf("Server listening..\n"); 
	}
}

struct sockaddr_in initializeServer(){
	struct sockaddr_in serverAddress;
	bzero(&serverAddress, sizeof(serverAddress));
	
	serverAddress.sin_family = AF_INET;
	serverAddress.sin_addr.s_addr = htonl(INADDR_ANY);
	serverAddress.sin_port = htons(PORT);

	return serverAddress;
}

void bindServerToLocalHost(int socket_fd, struct sockaddr_in serverAddress){
	if ((bind(socket_fd, (struct sockaddr*)&serverAddress, sizeof(serverAddress))) != 0) { 
		printf("Socket bind failed...\n"); 
		exit(1); 
    	} 
    	else{
    		printf("Socket successfully binded..\n"); 
  	}
}

int createSocket(){
	int socket_fd = socket(AF_INET, SOCK_STREAM, 0);
	if(socket_fd == -1){
		printf("Socket creation failed...\n");
		exit(0);	
	}
	else{
		printf("Socket successfully created\n");
	}

	return socket_fd;
}

void respondToClient(int socket_fd){
	char buffer[30];
	int n;

	int option;

	while(1){
		read(socket_fd, &option, sizeof(int)); 

		bzero(buffer, 30); 
		switch(option)
		{
			case 1: addNewRoute();break;
			case 2: deleteRoute();break;
			case 3: getFastestRoute();break;
			case 4:	getShortestRoute();break;
			case 5: printRoutes();break;
			case 6: printf("Program closed\n");break;	
			default: printf("Option does not exist\n");break;	
		}

		write(socket_fd, buffer, sizeof(buffer)); 	
		
		if( option == 6){
			printf("Server exit");	
			break;
		}
	}
}
