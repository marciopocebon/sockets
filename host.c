#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>

int main(){
	char *NomeHost;
	char *NomeDominio;
	int retorno;

	NomeHost = malloc(sizeof(char)*100);
	NomeDominio = malloc(sizeof(char)*100);

	retorno  = gethostname(NomeHost, 100);
	if ( retorno == -1 ) {
		printf("Erro ao obter nome do host!\n");
		exit(1);
	}

	// NIS - Network Information Service
	retorno = getdomainname(NomeDominio, 100);
	if ( retorno == -1 ) {
		printf("Erro ao obter nome do dominio NIS!\n");
		exit(1);
	}

	printf("Nome do Host: %s\n", NomeHost);
	printf("Nome do Dominio: %s\n", NomeDominio);

	exit(0);
}