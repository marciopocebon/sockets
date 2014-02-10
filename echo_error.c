// captura erros

#include <stdio.h>
#include <sys/socket.h>
#include <errno.h>

int main(){
	int SocketFD;
	SocketFD = socket( AF_UNIX, SOCK_RAW, 0 );
	// SOCK_RAW -> soh pode ser executado pelo root
	if ( SocketFD == -1 )
		perror("Erro");
}