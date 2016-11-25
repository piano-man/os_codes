#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>

sem_t rd;
sem_t wr;
int readcount = 0;

void *writer (void *parn) {
	int t = (int) parn;
	sem_wait (&wr);
	printf ("writing %d\n", t);
	sem_post (&wr);
} 

void *reader (void *parn) {
	int t = (int) parn;
	sem_wait (&rd);
	readcount++;
	if (readcount == 1) {
		sem_wait (&wr);
	}
	sem_post (&rd);
	printf ("reading %d at readcount %d\n", t, readcount);
	sem_wait (&rd);
	readcount--;
	if (readcount == 0) {
		sem_post (&wr);
	}
	printf ("reader %d is leaving\n",t);
	sem_post (&rd);
}

int main () {
	int i, nr, nw;


	pthread_t rdthread[20], wrthread[20];
	printf ("Enter number of reader thread: ");
	scanf ("%d", &nr);
	printf ("Enter number of writer thread: ");
	scanf ("%d", &nw);
	sem_init (&wr,0,1);
	sem_init (&rd,0,nr);
	for (i = 0; i < nr; i++) {
		pthread_create (&rdthread[i], NULL, reader, (void *)i);
	}
	for (i = 0; i < nw; i++) {
		pthread_create (&wrthread[i], NULL, writer, (void*)i);
	}
	for (i = 0; i < nr; i++) {
		pthread_join (rdthread[i], NULL);
	}
	for (i = 0; i < nw; i++) {
		pthread_join (wrthread[i], NULL);
	}

	return 0;
}
