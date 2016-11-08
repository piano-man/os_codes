# include<stdio.h>
# include<stdlib.h>
# include<pthread.h>
int flag[2];
int turn;
void *p1()
{
	int i=0;
	while(i<2)
	{
		flag[0]=1;
		turn=1;
		while(flag[1]==1&&turn==1);
		printf("thread 1 in critical section");
		flag[0]=0;
		i++;
	}
	pthread_exit(NULL);
}
void *p2()
{
	int i=0;
	while(i<2)
	{
		flag[1]=1;
		turn=0;
		while(flag[0]==1&&turn==0);
		printf("thread 2 is in critical section");
		flag[1]=0;
		i++;
	}
	pthread_exit(NULL);
}
main()
{
	pthread_t threads[2];
	pthread_create(&threads[0],NULL,p1,(void *)0);
	pthread_create(&threads[1],NULL,p2,(void *)1);
	pthread_join(threads[0],NULL);
	pthread_join(threads[1],NULL);
	pthread_exit(NULL);
}
