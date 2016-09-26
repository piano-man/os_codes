# include<stdio.h>
# include<stdlib.h>
int main()
{
	int i,n,min,k=1,btime=0;
	int bt[10],temp,j,at[10],wt[10],tt[10],ta=0,sum=0,p[10];
	float wavg=0,tavg=0,tsum=0,wsum=0;
	printf(" -------Shortest Job First Scheduling ( NP )-------\n");
	printf("\nEnter the No. of processes :");
	scanf("%d",&n);

	for(i=0;i<n;i++)
	{
		printf("\tEnter the burst time of %d process :",i+1);
		scanf(" %d",&bt[i]);
		printf("\tEnter the arrival time of %d process :",i+1);
		scanf(" %d",&at[i]);
		printf("Enter the priority of the process");
		scanf("%d",&p[i]);
	}
	for(j=0;j<n;j++)
	{
		btime=btime+bt[j];
		min=p[k];
		for(i=k;i<n;i++)
		{
			if (btime>=at[i] && p[i]<min)
			{

				temp=at[k];
				at[k]=at[i];
				at[i]=temp;
				temp=p[k];
				p[k]=p[i];
				p[i]=temp;
			}
		}
		k++;
	}
	wt[0]=0;
	for(i=1;i<n;i++)
	{
		sum=sum+p[i-1];
		wt[i]=sum-at[i];
		wsum=wsum+wt[i];
	}

	wavg=(wsum/n);
	for(i=0;i<n;i++)
	{
		ta=ta+p[i];
		tt[i]=ta-at[i];
		tsum=tsum+tt[i];
	}

	tavg=(tsum/n);

	printf("************************");
	printf("\n RESULT:-");

	printf("\n\nAVERAGE WAITING TIME : %f",wavg);
	printf("\nAVERAGE TURN AROUND TIME : %f",tavg);
	return 0;
}

