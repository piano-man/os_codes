# include<stdio.h>
# include<stdlib.h>
main()
{
	int page[10]={1,2,3,4,2,5,6,3,4,5};
	int fr[3];
	int fault=0;
	int i=0;
	int tarr[3];
	int flag;
	int change=0;
	for(i=0;i<3;i++)
	{
		tarr[i]=page[i];
	}
	while(i<10)
	{

		int j;

		if(i>2)
		{

			for(j=0;j<3;j++)
			{
				if(page[i]==tarr[j])
				{flag=1;
					break;
				}
			}
			if(flag==0)
			{
				fault++;
				tarr[change]=page[i];
				change++;
				if(change==2)
					change=0;
				i++;
			}
			if(flag==1)
				i++;
			for(j=0;j<3;j++)
			{
				printf("%d",tarr[j]);
			}
		}
	}
	printf("the number of faulta is : %d",fault);
}
