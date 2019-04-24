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
    	} 
    	else{
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
    } 
    else{
        printf("connected to the server..\n"); 
    }  
}


void sendToServer(int socket_fd){
	int n;
	int option;
	char buffer[30];
	while(1){
		bzero(buffer, 30);
		printf("Enter one of the following options:\n");
		printMenu();
		scanf("%d", &option);

		write(socket_fd, &option, sizeof(int));

		read(socket_fd, buffer, sizeof(buffer)); 
		buffer[strlen(buffer)]='\0';
		printf("From server: %s", buffer); 

		if( option == 6){
			printf("Client exit");	
			break;
		}
	}
}
