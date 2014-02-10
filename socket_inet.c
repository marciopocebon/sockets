// cria um socket INET

#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>

int main(){
	int sockfd, size_inet;
	// estrutura de endereco p/ dominio PF_INET
	struct sockaddr_in end_ip;

	// descritor de arquivo ref. socket aberto
	sockfd = socket( PF_INET, SOCK_STREAM, 0 );

	// cleanup
	memset( &end_ip, 0, sizeof end_ip );

	// config struct
	end_ip.sin_family 		= PF_INET;
	end_ip.sin_port 		= htons(3000);
	end_ip.sin_addr.s_addr 	= inet_addr("127.0.0.1");
	
	// tamanho da estrutura de endereco
	size_inet = sizeof( end_ip );

	bind( sockfd, (struct sockaddr *) &end_ip, size_inet );
	while(1);
}