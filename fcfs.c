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
int i;
int head=0;
for(i=0;i<n;i++)
{
scanf("%d",&arr[i]);
}
for(i=0;i<(n-1);i++)
{
head+= abs((arr[i+1]-arr[i]));
}
printf("the total head movement is : %d",head);
}
