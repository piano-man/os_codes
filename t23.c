#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>

pthread_t t[2];
pthread_mutex_t m;
pthread_cond_t check_v;
int v = 0;

void *inc_v (void *x)
{
	long id;
	id = (long)x;
	int i;
	
	for ( i = 0;i < 100;i++ ){

	pthread_mutex_lock(&m);

	while(v == 0) {
//		pthread_cond_wait(&check_v, &m);
		printf ( "Thread %ld\nv was =  %d",id,v);
		v++; 
		printf (" now v is =  %d\n",v);
	}

	if ( v == 1 ) {
		pthread_cond_wait(&check_v,&m);
	}
	
	pthread_mutex_unlock(&m);
	sleep(1);
	}	
//	sleep(1);
	pthread_exit(NULL);
}

void *dec_v (void *x)
{
	long id;
	id = (long)x;
	int i;
	
	for ( i = 0;i < 100;i++ ) {
	pthread_mutex_lock(&m);
	
	while ( v == 1 ) {
//		pthread_cond_wait(&check_v,&m);
		printf ( "Thread %ld\nv was = %d",id,v);
		v--;
		printf (" now v is = %d\n",v);
	}

	if ( v == 0) {
		pthread_cond_signal(&check_v);
	}

	pthread_mutex_unlock(&m);
	sleep(1);
	}
//	sleep(1);
	pthread_exit(NULL);
}

int main()
{
	long t1 = 1,t2 = 2;
	pthread_create(&t[1],NULL,inc_v,(void *)t1);
	pthread_create(&t[2],NULL,dec_v,(void *)t2);

	pthread_join(t[1],NULL);
	pthread_join(t[2],NULL);

	pthread_exit(NULL);
	return 0;
}

