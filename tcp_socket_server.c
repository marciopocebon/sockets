// creates a socket to listen for connections on port 4040
// sends a default message for connected peers

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <time.h>

int main(){
	// Both local and remote addresses
	struct sockaddr_in LocalAddr, RemoteAddr;
	// server and client descriptors, its length and bind status
	int sockfd_server, lenServer, status;
	int sockfd_cliente, lenRemote;
	// exchanged message
	char *buffer;
	// allocate memory for the exchanged message
	buffer = malloc(sizeof(char)*100);
	buffer = "You have successfuly connected to the server at port: 4040\n";

	// opens the socket
	sockfd_server = socket(PF_INET, SOCK_STREAM, 0);

	// tamanho do endereco atribuido ao socket do server

	lenServer = sizeof(LocalAddr);
	// memory cleanup
	memset((struct sockaddr_in *)&(LocalAddr), 0, lenServer);
	// sets socket's domain/family
	LocalAddr.sin_family = PF_INET;
	// sets socket's port
	LocalAddr.sin_port = htons(4040);
	// sets an IP
	LocalAddr.sin_addr.s_addr = inet_addr("127.0.0.1");

	// assign an address to the socket
	status = bind(sockfd_server, (struct sockaddr*)&LocalAddr, lenServer);

	// if the assignment fails, exit
	if ( status == -1 ) exit(0);

	// escuta por conexoes
	// 5 -> tamanho max. fila espera por uma conexao
	// start listening for a maximum of 5 connections on the socket
	listen(sockfd_server, 5);

	printf("%s\n", "Socket listening on port: 4040" );

	while(1){
		// blocks the program execution until there's a client requesting for connection
		sockfd_cliente = accept( sockfd_server, (struct sockaddr *) &RemoteAddr, &lenRemote );

		printf("%s\n", "New client connected on port: 4040");
		// sends the buffered data to the client
		send(sockfd_cliente, buffer, strlen(buffer), 0);
		// closes the connection with the client
		close(sockfd_cliente);
	}
}