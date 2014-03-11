// An example on how to fork/clone a process: copy of a parent process, generating a child process

#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <unistd.h>

int main(){
	pid_t ChildProcess;

	printf("I'm the parent process\n");

	// forks its parent
	ChildProcess = fork();

	// only after the fork call, childProcess start executing
	// child process' code will be only what came after fork call, because it is created only after the command

	if ( ChildProcess == -1 ) {
		printf("No child process created yeat. I'm still the parent process\n");
		exit(1);
	} else if ( ChildProcess > 0 ) {
		printf("I'm still the parent process\n");
		while(1);
	}

	printf("Since now, I'm the child process\n");
	while(1);
}