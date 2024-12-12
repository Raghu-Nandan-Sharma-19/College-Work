#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
int main() {
	pid_t pid;
	int n;
	printf("Enter no of child processes you want to create: ");
	scanf("%d", &n);
	pid = fork();
	for(int i = 1; i <= n; i++) {
	if(pid < 0) {
		perror("fork failed\n");
		exit(EXIT_FAILURE);
	}
	else if(pid == 0) {
		printf("child processes created. PID: %d\n", getpid());
		sleep(6);
		exit(EXIT_SUCCESS);
	}
	else {
		printf("Parent process. PID: %d\n", getpid());
		printf("Waiting for child process (PID: %d) to terminate...\n", pid);
	}
	int status;
	pid_t terminated_pid = waitpid(pid, &status, 0);
	if(terminated_pid == -1) {
		perror("Error while waiting for child process\n");
	}
	else {
		printf("Child process. (PID: %d) terminated. Status: %d\n", terminated_pid, WEXITSTATUS(status));
	}
	}
	return 0;
}
