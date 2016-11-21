# include<stdio.h>
# include<stdlib.h>
# include<math.h>
main()
{
	printf("enter the number of cylinders");
	int n;
	scanf("%d",&n);
	printf("enter the cylinder numbers");
	int arr[n];
	int k;
	for(k=0;k<n;k++)
	{
		scanf("%d",&arr[n]);
	}
	int i;
	int j;
	int phead;
	int rhead;
	int head;
	int check[n];
	for(i=0;i<n;i++)
	{
		check[i]=i;
	}
	int min;
	printf("enter the starting head position");
	int start;
	scanf("%d",&start);
	phead=start;
	for(i=0;i<n;i++)
	{

		min=100000;
		for(j=0;j<n;j++)
		{
			if(j!=phead&&check[j]!=1000)
				if(min>abs((arr[j]-arr[phead])))
				{
					min=abs(arr[j]-arr[phead]);
					rhead=j;
				}
		}
		check[phead]=1000;
		head+=abs(arr[phead]-arr[rhead]);
		phead=rhead;
	}
	printf("the total head movement is: %d",head);
}
