/*#include<stdio.h>
#define MAX 50
int main()
{
	int page[MAX],i,n,f,ps,off,pno;
	
	printf("\nEnter the no of pages in memory");
	scanf("%d",&n);
	printf("\nEnter page size");
	scanf("%d",&ps);
	printf("\nEnter no of frames");
	scanf("%d",&f);
	for(i=0;i<n;i++)
		page[i]=-1;
	printf("\nEnter the page table\n");
	printf("(Enter frame no as -1 if that page is not present in any frame)\n\n");
	printf("\npageno\tframeno\n-------\t-------");
	for(i=0;i<n;i++)
	{
		printf("\n\n%d\t\t",i);
		scanf("%d",&page[i]);
	}
	printf("\n\nEnter the logical address(i.e,page no & offset):");
	scanf("%d%d",&pno,&off);
	if(page[pno]==-1)
		printf("\n\nThe required page is not available in any of frames");
	else
		printf("\n\nPhysical address(i.e,frame no & offset):%d,%d",page[pno],off);
	

}*/
# include<stdio.h>
# include<stdlib.h>
main()
{
printf("enter the number of pages");
int p;
scanf("%d",&p);
int arr[p];
int *arr1[p];
printf("enter the size of pages");
int i;
for(i=0;i<p;i++)
{
scanf("%d",&arr[i]);
arr1[i]=(int *)malloc(arr[i]*sizeof(int));
printf("%p",arr1[i]);
}

}
