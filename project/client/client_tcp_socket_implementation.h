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

void connectToServer(){
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

int main(){

void sendToServer(int socket_fd){
	int option;
	char buffer[30];
	while(1){
		printf("Enter one of the following options:\n");
		printMenu();
		scanf("%d", &option);

		write(socket_fd, &option, sizeof(int));

		bzero(buffer, 30);
		read(socket_fd, buffer, sizeof(buffer));  

		printf("From server: %s", buffer); 

		if( option == 6){
			printf("Client exit");	
			break;
		}
	}
}
