// sobe um server na porta 4040
// responde uma mensagem estatica

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <time.h>

int main(){
	// enderecos
	struct sockaddr_in EndLocal, EndRemoto;
	// descritores, retorno e lens
	int sockfd_server, len, retorno;
	int sockfd_cliente, lenRemoto;
	// mensagem
	char *buffer;

	buffer = malloc(sizeof(char)*100);

	// abre um socket
	sockfd_server = socket(PF_INET, SOCK_STREAM, 0);

	// tamanho do endereco atribuido ao socket do server
	len = sizeof(EndLocal);
	// cleanup
	memset((struct sockaddr_in *)&(EndLocal), 0, len);
	// seta a familia/dominio/escopo do socket
	EndLocal.sin_family = PF_INET;
	// seta a porta que ficara escutando por conexoes
	EndLocal.sin_port = htons(4040);
	// seta o endereco IP
	// EndLocal.sin_addr.s_addr = INADDR_ANY; // escuta qualquer IP/placa rede
	EndLocal.sin_addr.s_addr = inet_addr("127.0.0.1");

	// atribui o endereco ao socket
	retorno = bind(sockfd_server, (struct sockaddr*)&EndLocal, len);

	// caso erro, retorna
	if ( retorno == -1 ) exit(0);

	// escuta por conexoes
	// 5 -> tamanho max. fila espera por uma conexao
	listen(sockfd_server, 5);

	// loga uma mensagem antes de comecar a processar conexoes
	printf("%s\n", "Aguardando conexoes na porta:4040" );

	// loop infinito
	while(1){
		// bloqueia a execucao do programa, ate que exista um pedido de conexao por parte do cliente
		sockfd_cliente = accept( sockfd_server, (struct sockaddr *) &EndRemoto, &lenRemoto );

		// armazena uma string para ser enviada ao cliente
		buffer = "Cliente se conectou no servidor!\n";
		// envia para o cliente os dados, seguido do tamanho total de dados sendo enviados
		// 0 -> opcional, flags
		send(sockfd_cliente, buffer, strlen(buffer), 0);
		// fecha a conexao com o cliente
		close(sockfd_cliente);
	}
}