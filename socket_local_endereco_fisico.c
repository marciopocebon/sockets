// open a local socket, within a physical address, in an infinite loop

#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/un.h>

int main(){
	int sockfd, size_local;
	char file_path[] = "/tmp/socket_local";
	struct sockaddr_un LocalAddr;

	sockfd = socket( PF_LOCAL, SOCK_STREAM, 0 );

	printf( "Socket descriptor: %d\n", sockfd );

	memset( &LocalAddr, 0, sizeof LocalAddr );

	LocalAddr.sun_family = PF_LOCAL;
	strcpy( LocalAddr.sun_path, file_path );
	size_local = sizeof( LocalAddr );

	bind( sockfd, (struct sockaddr *) & LocalAddr, size_local );
	while(1);
}