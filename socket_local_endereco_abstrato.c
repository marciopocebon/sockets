// cria um socket local em loop infinito

#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/un.h>

int main(){
	int sockfd, size_local;
	// caminho do socket / endereco do socket local
	// seta o 1o byte como nulo e diz ao kernel que eh um endereco abstrato
	char caminho_do_arquivo[] = "X-ABSTRATO-";
	// estrutura que abriga o endereco para realizar a juncao com o socket atraves do bind
	struct sockaddr_un EndLocal;

	// armazena o descritor do arquivo
	sockfd = socket( PF_LOCAL, SOCK_STREAM, 0 );

	printf( "Socket descriptor: %d\n", sockfd );

	// zera a estrutura de endereco, para nao ficar sujeira
	memset( &EndLocal, 0, sizeof EndLocal );

	EndLocal.sun_family = AF_LOCAL;
	strcpy( EndLocal.sun_path, caminho_do_arquivo );
	size_local = sizeof( EndLocal );
	// substitui o caractere X por 0, tornando-o nulo e mantendo o endereco somente -ABSTRATO-
	EndLocal.sun_path[0] = 0;

	bind( sockfd, (struct sockaddr *) & EndLocal, size_local );
	while(1);
}