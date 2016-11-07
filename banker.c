# include<stdio.h>
# include<stdlib.h>
//# include<pthhread.h>
main()
{
	printf("enter the number of processes");
	int p;
	scanf("%d",&p);
	printf("enter the number of resources");
	int r;
	scanf("%d", &r);
	int falloc[p][r];
	int fmax[p][r];
	int need[p][r];
	int complete[p];
	int count=0;
	int i;
	int k;
	int safe[p];
	printf("enter available resources");
	int avail[r];
	for(i=0;i<p;i++)
	{
		complete[i]=0;
	}
	for(i=0;i<r;i++)
	{
		scanf("%d",&avail[i]);
	}
	for(i=0;i<p;i++)
	{
		printf("enter allocation");
		for(k=0;k<r;k++)
			scanf("%d",&falloc[i][k]);
		printf("enter max");
		for(k=0;k<r;k++)
			scanf("%d",&falloc[i][k]);
	}
	for(i=0;i<r;i++)
	{
		printf("%d ",falloc[0][i]);
	}
	for(i=0;i<p;i++)
	{
		for(k=0;k<p;k++)
		{
			need[i][k]=fmax[i][k]-falloc[i][k];
		}
	}
	int process;
//requesting algorithm
printf("enter the process id");
int pid;
scanf("%d",&pid);
printf("enter the request");
int req[r];
for(i=0;i<r;i++)
{
scanf("%d",&req[i]);
}
for(i=0;i<p;i++)
{

}
	do
	{
		process=-1;
		for(i=0;i<p;i++)
		{
			if(complete[i]!=1)
			{
				process=i;
				for(k=0;k<r;k++)
				{
					if(avail[k]<need[process][k])
					{
						process=-1;
						break;
					}
				}
			}
			if(process!=-1)
				break;
		}
		if(process!=-1)
		{
			safe[count++]=process;
			for(i=0;i<r;i++)
			{
				avail[r]+=falloc[process][r];
			}
		}
	}while(count!=p&&process!=-1);
	if(count==p)
	{
		printf("the system is safe");
		printf("the safe sequence is :");
		for(i=0;i<p;i++)
		{
			printf("%d",safe[i]);
		}
	}
	else
		printf("the system is unsafe");
}
