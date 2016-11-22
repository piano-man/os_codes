/*# include<stdio.h>
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
}*/
#include<stdio.h>
void main()
{
	int a[20],b[20],d,n,i,j,temp,s,k=0,x=0,t=0;
	
	printf("Enter head pointer position:");
	scanf("%d",&a[0]);
	printf("\nEnter number of processes:");
	scanf("%d",&n);
	printf("\nEnter processes in request order");
	for(i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	b[k++]=a[0];
	for(i=0;i<n;i++)
	{
		s=1000;
		for(j=i+1;j<=n;j++)
		{
			if(a[i]>a[j])
				d=a[i]-a[j];
			else
				d=a[j]-a[i];
			if(d<s)
			{
				s=d;
				x=j;
			}
		}
		t+=s;
		temp=a[i+1];
		a[i+1]=a[x];
		a[x]=temp;
		b[k++]=a[i+1];
	}
	printf("\nProcessing order:");
	for(i=0;i<=n;i++)
		printf("\t%d",b[i]);
	printf("\nTotal Head Movement:%d",t);

}
