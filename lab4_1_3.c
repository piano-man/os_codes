//round robin scheduling algorithm
# include<stdio.h>
# include<stdlib.h>
main()
{
	int at[10];
	int bt[10];
	int rt[10];
	int count =0,wt,tt;
	printf("enter the number of processes you want");
	int n;
	scanf("%d",&n);
	int remain = n;
	int time;
	int i;
	int flag;
	for (i=0;i<n;i++)
	{
		printf("enter burst time ");
		scanf("%d",&bt[i]);
	}
	for(i=0;i<n;i++)
	{
		printf("enter arrival time");
		scanf("%d",&at[i]);
	}
	for(i=0;i<n;i++)
	{
		rt[i]=bt[i];
	}
	printf("enter time quantum");
	int tq;
	scanf("%d",&tq);
	for(time=0;remain!=0;i++)
	{
		if(rt[count]<=tq && rt[count]>0)
		{
			time = time+rt[count];
			rt[count]=0;
			flag=1;
		}
		else if(rt[count]>0)
		{
			rt[count]=rt[count]-tq;
			time=time + tq;
		}
		if(rt[count]==0 && flag==1)
		{
			remain--;
			wt+=time-at[count]-bt[count];
			tt=time-at[count];
			flag=0;
		}
		if(count == n-1)
		{
			count = 0;
		}
		else if(at[count + 1]<=time)
		{
			count++;
		}
		else 
			count=0;
	}
	printf("average wait time is %d",wt);
	printf("total  turnaround time is %d",tt);
}
