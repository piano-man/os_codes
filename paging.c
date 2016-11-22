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
struct page
{
int size;
int offset;
int number;
};
main()
{
printf("enter the number of pages");
int p;
scanf("%d",&p);
struct node *logical[p];
int phy[5]={0};
int log[p];
int fault=0;
int current;
//struct page * rpage[p];
int i;
for(i=0;i<p;i++)
{
log[i]=i;
}
for(i=0;i<p;i++)
{
logical[i]=(struct node *)malloc(sizeof(struct node));
printf("enter the page size");
scanf("%d",&(logical[i]->size));
printf("enter the offset");
scanf("%d",&(logical[i]->offset));
printf("enter the page number");
scanf("%d",&(logical[i]->number));
}
printf("enter the page number you want to retrieve");
int no;
scanf("%d",&no);
int add;
add=log[no]+logical[no]->offset;
}
