// connects to a server and receive messages

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <time.h>

int main(){
	// socket's address
	struct sockaddr_in LocalAddr;
	// descriptor, socket's length and bind status
	int sockfd, len, status;
	// storages the received message from the server
	char buffer[1000];

	// opens the socket
	sockfd = socket(PF_INET, SOCK_STREAM, 0);

	len = sizeof(LocalAddr);
	// memory cleanup
	memset((struct sockaddr_in *)&(LocalAddr), 0, len);
	// sets socket's domain/family
	LocalAddr.sin_family = PF_INET;
	// sets socket's port
	LocalAddr.sin_port = htons(4040);
	// sets an IP
	LocalAddr.sin_addr.s_addr = inet_addr("127.0.0.1");

	// try to connect to the server
	status = connect(sockfd, (struct sockaddr*)&LocalAddr, len);

	// if the connection fails, exit
	if ( status != 0 ) {
		perror( "Could not connect to the server" );
		exit(1);
	}

	// receives a message from the server
	recv(sockfd, &buffer, sizeof(buffer), 0);

	// prints the received message
	printf("%s\n", buffer);

	// the end
	exit(0);
}