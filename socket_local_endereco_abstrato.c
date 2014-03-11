// open a local socket, within a abstract address, in an infinite loop

#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/un.h>

int main(){
	int sockfd, size_local;
	// socket's local address
	char file_path[] = "X-ABSTRACT-";
	// socket's address struct
	struct sockaddr_un LocalAddr;

	// file descriptor
	sockfd = socket( PF_LOCAL, SOCK_STREAM, 0 );

	// prints socket's file descriptor
	printf( "Socket descriptor: %d\n", sockfd );

	// zero the struct
	memset( &LocalAddr, 0, sizeof LocalAddr );

	// assigns a socket family to the address struct
	LocalAddr.sun_family = AF_LOCAL;
	// assigns the file path to the address struct
	strcpy( LocalAddr.sun_path, file_path );
	// calculates struct length
	size_local = sizeof( LocalAddr );
	// replace X character by 0
	LocalAddr.sun_path[0] = 0;

	// assign an address to a socket
	bind( sockfd, (struct sockaddr *) & LocalAddr, size_local );
	
	while(1);
}