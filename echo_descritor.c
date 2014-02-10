// imprimi o descritor do socket criado

#include <stdio.h>
#include <sys/socket.h>

int main(){
	int SocketFD;
	SocketFD = socket( PF_UNIX, SOCK_STREAM, 0 );
	printf( "Socket: %d\n", SocketFD );
}

// assinatura do metodo
// socket( int domain, int type, int protocol )