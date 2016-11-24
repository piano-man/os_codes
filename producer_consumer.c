#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#define buffersize 10

pthread_mutex_t mutex;
pthread_t tp[11], tc[11];
sem_t full, empty;
int counter;
int buffer[buffersize];

void initialize () {
	pthread_mutex_init (&mutex, NULL);
	sem_init (&full, 1, 0);
	sem_init (&empty, 1, buffersize);
	counter = 0;
}

void write (int item) {
	buffer[counter++] = item;
}

int read () {
	return (buffer[--counter]);
}

void *producer (void *parn) {
	int waittime, item, i;
	item = rand () % 9;
	waittime = rand () % 9;
	sem_wait (&empty);
	pthread_mutex_lock (&mutex);
	printf ("produced %d\n", item);
	write (item);
	pthread_mutex_unlock (&mutex);
	sem_post (&full);
}

void *consumer (void *parn) {
	int waittime, item;
	waittime = rand () % 9;
	sem_wait (&full);
	pthread_mutex_lock (&mutex);
	item = read ();
	printf ("consumed %d\n", item);
	pthread_mutex_unlock (&mutex);
	sem_post (&empty);
}
int main () {
	int n1, n2, i;
	initialize ();
	printf ("Enter no. of producers : ");
	scanf ("%d", &n1);
	printf ("Enter no. of consumers : ");
	scanf ("%d", &n2);
	for (i = 0; i < n1; i++) {
		pthread_create (&tp[i], NULL, producer, NULL);
	}
	for (i = 0; i < n2; i++) {
		pthread_create (&tc[i], NULL, consumer, NULL); 
	}
	for (i = 0; i < n1; i++) {
		pthread_join (tp[i], NULL);
	}
	for (i = 0; i < n2; i++) {
		pthread_join (tc[i], NULL);
	}
	return 0;
}
