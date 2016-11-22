# include<stdio.h>
# include<stdlib.h>
main()
{
	printf("enter the number of frames");
	int f;
	scanf("%d",&f);
	printf("enter the number of pages");
	int p;
	scanf("%d",&p);
	int frame[f];
	int pages[p];
	int freq[f];
	int count[p];
	int i;
	int flag;
	int j;
	int min;
	int num;
	int hit=0;
	for(i=0;i<f;i++)
	{
		frame[i]=-1;
		freq[i]=-1;
	}
	printf("enter the page number");
	for(i=0;i<p;i++)
	{
		scanf("%d",&pages[i]);
	}
//	printf ("Input done\n");
	for(i=0;i<p;i++)
	{
		int page=pages[i];
		flag=1;
		for(j=0;j<f;j++)
		{
			if(frame[j]==page)
			{
				flag=0;
				count[page]++;
				hit++;
				break;
			}

		}
		if(flag)
		{
			if(i>=3)
			{
				for(j=0;j<f;j++)
				{
					num=frame[j];
					freq[j]=count[num];
				}
				min=freq[0];
				for(j=0;j<f;j++)
				{
					if(min>freq[j])
					{
						min=freq[j];
					}
				}
				for(j=0;j<f;j++)
				{
					if(freq[j]==min)
					{
						count[page]++;
						frame[j]=page;
						break;
					}
				}
			}
		
			else
			{
				frame[i]=page;
				count[page]++;
			}
		}
		
	}
	printf("frame:");
	int k;
	for(k=0;k<f;k++)
	{
	printf("%d ",frame[k]);

	}
	printf("number of page hits = %d",hit);

}
