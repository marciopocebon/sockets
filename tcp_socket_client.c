// se conecta a um server
// e recebe mensagens

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <time.h>

int main(){
	// endereco
	struct sockaddr_in EndLocal;
	// descritor, tamanho e retorno do connect
	int sockfd, len, retorno;
	// armazenarara o conteudo retornado
	char buffer[1000];

	// abre o socket
	sockfd = socket(PF_INET, SOCK_STREAM, 0);

	// tamanho do endereco atribuido ao socket
	len = sizeof(EndLocal);
	// cleanup
	memset((struct sockaddr_in *)&(EndLocal), 0, len);
	// dominio do socket
	EndLocal.sin_family = PF_INET;
	// porta
	EndLocal.sin_port = htons(4040);
	// endereco IP
	EndLocal.sin_addr.s_addr = inet_addr("127.0.0.1");

	// tenta se conectar ao server
	retorno = connect(sockfd, (struct sockaddr*)&EndLocal, len);

	if ( retorno != 0 ) {
		perror( "Não foi possível se conectar" );
		exit(1);
	}

	// recebe a mensagem do server
	recv(sockfd, &buffer, sizeof(buffer), 0);

	// loga a mensagem recebida
	printf("%s\n", buffer);

	// fim do programa
	exit(0);
}