#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
	int n = 10;
    	pid_t pid;

    	pid = fork();

    	for(int  i = 0; i < 3; i++) {
		pid = fork();
		if(pid < 0) {
			perror("Fork failed\n");
			exit(1);
		} else if(pid == 0) {
			// child process
			printf("Child process ID: %d, Address of variable 'n': %p\n", getpid(), (void*)&n);
			while(1) {
				sleep(1);
			}
		}
	}
	printf("Parent process ID: %d, Address of variable 'n': %p\n", getpid(), (void*)&n);
	while(1) {
		sleep(1);
	}

	return 0;
}
