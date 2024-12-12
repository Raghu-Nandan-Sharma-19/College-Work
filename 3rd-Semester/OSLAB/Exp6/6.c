#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
int main() {
	int mb;
	printf("Memory allocation program\n");
	printf("Enter the size of megabytes : ");
	if(scanf("%d", &mb) != 1 || mb <= 0)
	{
		fprintf(stderr, "Enter a valid positive number\n");
		return 1;
	}
	size_t bytes = (size_t)mb*1024*1024;
	printf("\nAttempting to allocate %d of memory.....\n", mb);
	char *memory = malloc(bytes);
	if(memory == NULL) {
		fprintf(stderr, "Memory allocation failed\n");
		return 1;
	}
	memset(memory, 0, bytes);
	printf("Successfully allocated %d MB of memory\n", mb);
	printf("\nPlease open another terminal and use 'free -m' command and check memory usage\n");
	getchar();
	getchar();
	free(memory);
	printf("Memory has been released. You can use 'free -m' agan to confirm.\n");
	return 0;
}
