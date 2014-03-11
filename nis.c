// make a SO call to get both host and domain name
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>

int main(){
	char *HostName;
	char *DomainName;
	int returned;

	HostName = malloc(sizeof(char)*100);
	DomainName = malloc(sizeof(char)*100);

	returned  = gethostname(HostName, 100);
	if ( returned == -1 ) {
		printf("Error getting hostname!\n");
		exit(1);
	}

	returned = getdomainname(DomainName, 100);
	if ( returned == -1 ) {
		// NIS - Network Information Service
		printf("Error getting domain name NIS!\n");
		exit(1);
	}

	printf("Hostname: %s\n", HostName);
	printf("Domainname: %s\n", DomainName);

	exit(0);
}