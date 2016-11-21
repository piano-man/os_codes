/*# include<stdio.h>
# include<stdlib.h>
# include<math.h>
sort(int arr[],int n)
{
int i,j,key;
for(i=1;i<n;i++)
{
key = arr[i];
j=i-1;
while(j>=0 && arr[j]>key)
{
arr[j+1]=arr[j];
j=i-1;
}
arr[j+1]=key;
}
}
main()
{
printf("enter the number of cylinders");
int n;
scanf("%d",&n);
printf("enter the cylinder numbers");
int arr[n];
int i;
int temp1[1000];
int temp2[1000];
for(i=0;i<n;i++)
{
scanf("%d",&arr[i]);
}
printf("enter the starting head positon");
int start;
scanf("%d",&start);
sort(arr,n);

}*/
#include<stdio.h>
int main()
{
	int i,j,sum=0,n;
	int d[20];
	int disk;   //loc of head
	int temp,max;     
	int dloc;   //loc of disk in arra
	printf("enter number of location\t");
	scanf("%d",&n);
	printf("enter position of head\t");
	scanf("%d",&disk);
	printf("enter elements of disk queue\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&d[i]);
	}
	d[n]=disk;
	n=n+1;
	for(i=0;i<n;i++)    // sorting disk locations
	{
		for(j=i;j<n;j++)
		{
			if(d[i]>d[j])
			{
				temp=d[i];
				d[i]=d[j];
				d[j]=temp;
			}
		}
	}
	max=d[n];
	for(i=0;i<n;i++)   // to find loc of disc in array
	{
		if(disk==d[i]) { dloc=i; break;  }
	}
	for(i=dloc;i>=0;i--)
	{
		printf("%d -->",d[i]);
	}
	printf("0 -->");
	for(i=dloc+1;i<n;i++)
	{
		printf("%d-->",d[i]);
	}
	sum=disk+max;
	printf("\nmovement of total cylinders %d",sum);

}

