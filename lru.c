# include<stdio.h>
# include<stdlib.h>
int count[3];
count[0]=0;
count[1]=1;
count[2]=2;
int max;
max=count[0];
int priority(int chan)
{
	int i;
	for(i=0;i<3;i++)
	{
		if(count[i]>max)
			max=count[i];
	}
	count[chan]=max+1;
	return count[chan];
}
int findmin()
{
	int min;
	int i;
	for(i=0;i<min;i++)
	{
		if(count[i]<min)
		{
			min=count;
			ret=i;
		}
	}
	return ret;;
}
main()
{
	int n;
	int min;
	printf("enter the number of pages");
	scanf("%d",&n);
	printf("enter the reference string")
		int arr[100];
	for(i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
	//frame size is 3
	int temp[3];
	int i=0;
	int j=0;
	temp[i]=arr[j];
	j++;
	while(i<3)
	{
		if(arr[j]==temp[i])
			j++;
		else
			i++;
		temp[i]=arr[j];
		j++;
	}
	i=0;
	j=0;
	int k;
	for(k=0;k<3;k++)
	{
		printf("%d",temp[i]);
	}
	k=0;
	for(i=3;i<n;i++)
	{
		for(j=0;j<3;j++)
		{
			if(arr[i]==temp[j])
				break;
		}
		count[j]=priority(j);
		min=findmin();
		temp[min]=arr[i];
	}
	for(k=0;k<3;k++)
	{
		printf("%d",temp[k]);
	}
}

