# include<stdio.h>
# include<stdlib.h>
# include<conio.h>
main()
{
int n;
char c[10];
int b[100];
int w[100]=0;
int t[100]=0;
printf("enter the number of processes");
scanf("%d",&n);
int i,j;
for(i=0;i<n;i++)
{
printf("enter the process name");
scanf("%s",c);
printf("enter the burst time");
scanf("%d",&b[i]);
}
w[0]=0;
for(i=1;i<n;i++)
{
w[i]=w[i-1]+b[i-1];
t[i]=w[i]+t[i];
}
for(i=0;i<n;i++)
{
printf("the total time for the execution of the proces %d  is %d ",i,t[i]);
}


}


