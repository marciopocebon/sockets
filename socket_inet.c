// creates a socket from PF_INET family

#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>

int main(){
	int sockfd, size_inet;
	// PF_INET address struct
	struct sockaddr_in end_ip;

	// file descriptor from open socket
	sockfd = socket( PF_INET, SOCK_STREAM, 0 );

	// cleanup / zero the struct
	memset( &end_ip, 0, sizeof end_ip );

	// sets socket's family/domain
	end_ip.sin_family 		= PF_INET;
	// sets port number
	end_ip.sin_port 		= htons(3000);
	// sets IP number
	end_ip.sin_addr.s_addr 	= inet_addr("127.0.0.1");
	
	// struct's length
	size_inet = sizeof( end_ip );

	// assign an address to a socket
	bind( sockfd, (struct sockaddr *) &end_ip, size_inet );
	
	while(1);
}