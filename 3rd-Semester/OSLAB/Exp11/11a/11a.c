#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<semaphore.h>
#include<unistd.h>

#define NUM_TABLES 3
#define NUM_CUSTOMER 4

sem_t tables;
void *customer(void *arg) {
	int id = *(int *)arg;

	printf("Customer %d is waiting for a table.\n", id);
	sem_wait(&tables);

	printf("Customer %d got a table and is dining.\n", id);
	sleep(rand() % 3 + 1);

	printf("Customer %d has finished dining and left the table.\n", id);
	sem_post(&tables);

	free(arg);
	return NULL;
}

int main() {
	pthread_t threads[NUM_CUSTOMER];

	sem_init(&tables, 0, NUM_TABLES);

	for(int i = 0; i < NUM_CUSTOMER; i++) {
		int *id = malloc(sizeof(int));
		*id = i + 1;
		pthread_create(&threads[i], NULL, customer, id);
	}

	for(int i = 0; i < NUM_CUSTOMER; i++) {
		pthread_join(threads[i], NULL);
	}

	sem_destroy(&tables);

	printf("Restaurant is now closed.\n");

	return 0;
}
