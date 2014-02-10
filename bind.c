// atribui endereco ao socket

#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <linux/x25.h>

int main(){
	int 	sock_x25;
	int 	size_x25;
	char 	x25[] = "58974287";
	struct 	sockaddr_x25 meu_end_x25;

	sock_x25 = socket( PF_X25, SOCK_SEQPACKET, 0 );
	meu_end_x25.sx25_family = AF_X25;
	strcpy( meu_end_x25.sx25_family.x25_addr, x25 );

	size_x25 = sizeof( meu_end_x25 );
	bind( sock_x25, (struct sockaddr *) &meu_end_x25, size_x25 );
}

// assinatura da funcao bind
int bind( int descritor, struct sockaddr *endereco_memoria, int tamanho_bytes )