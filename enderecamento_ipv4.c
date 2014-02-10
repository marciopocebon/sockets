// estrutura sockaddr_in utilizada no enderecamento de IPv4

#include <netinet/in.h>

struct sockaddr_in {
	// dominio
	sa_family_t 	sin_family;
	// porta TCP ou UDP
	uint16_t		sin_port;
	// endereco IPv4
	struct in_adddr	sin_addr;
	// nao eh iniciado, nem utilizado
	unsigned char 	sin_zero[8];
};

// tipo/estrutura do campo sin_addr
struct in_adddr{
	uint32_t 		s_addr;
};

// como recuperar o endereco IP:
// inicia o socket
// struct sockaddrr_in end_ip;
// // acessa o endereco, like json
// end.ip.sin_addr.s_addr = "ENDERECO IP"