# include<stdio.h>
# include<stdlib.h>
main()
{
	/*printf("enter the number of partitions");
	  int n;
	  scanf("%d",&n);
	  printf("enter the sizes of the partition");
	  int arr[n];
	  for(i=0;i<n;i++)
	  {
	  scanf("%d",&arr[i]);
	  }*/
	printf("enter the choice");
	printf("1)first fit");
	printf("2)best fit");
	printf("3)worst fit");
	int c;
	scanf("%d",&c);
	/*printf("enter the number of processes");
	  int m;
	  int size[m];
	  scanf("%d",&m);
	  printf("enter the process size");
	  for(i=0;i<m;i++)
	  {
	  scanf("%d",&size[i]);
	  }*/
	if(c==1)
	{

		int a[20],p[20],i,j,n,m;
		printf("Enter no of Blocks.\n");
		scanf("%d",&n);
		for(i=0;i<n;i++)
		{
			printf("Enter the %dst Block size:",i);
			scanf("%d",&a[i]);
		}
		printf("Enter no of Process.\n");
		scanf("%d",&m);
		for(i=0;i<m;i++)
		{
			printf("Enter the size of %dst Process:",i);
			scanf("%d",&p[i]);
		}
		for(i=0;i<n;i++)
		{
			for(j=0;j<m;j++)
			{
				if(p[j]<=a[i])
				{
					printf("The Process %d allocated to %d\n",j,a[i]);
					p[j]=10000;
					break;
				}
			}
		}
		for(j=0;j<m;j++)
		{
			if(p[j]!=10000)
			{
				printf("The Process %d is not allocated\n",j);
			}

		}

	}
	if(c==2)
	{
		int fragments[10], block[10], file[10], m, n, number_of_blocks, number_of_files, temp, lowest = 10000;
		static int block_arr[10], file_arr[10];
		printf("\nEnter the Total Number of Blocks:\t");
		scanf("%d", &number_of_blocks);
		printf("\nEnter the Total Number of Files:\t");
		scanf("%d", &number_of_files);
		printf("\nEnter the Size of the Blocks:\n");
		for(m = 0; m < number_of_blocks; m++) 
		{
			printf("Block No.[%d]:\t", m + 1);
			scanf("%d", &block[m]);
		}
		printf("Enter the Size of the Files:\n");
		for(m = 0; m < number_of_files; m++) 
		{
			printf("File No.[%d]:\t", m + 1);	
			scanf("%d", &file[m]);
		}
		for(m = 0; m < number_of_files; m++)
		{
			for(n = 0; n < number_of_blocks; n++)
			{
				if(block_arr[n] != 1)
				{
					temp = block[n] - file[m];
					if(temp >= 0)
					{
						if(lowest > temp)
						{
							file_arr[m] = n;
							lowest = temp;
						}
					}
				}
				fragments[m] = lowest;
				block_arr[file_arr[m]] = 1;
				lowest = 10000;
			}
		}
		printf("\nFile Number\tFile Size\tBlock Number\tBlock Size\tFragment");
		for(m = 0; m < number_of_files && file_arr[m] != 0; m++)
		{
			printf("\n%d\t\t%d\t\t%d\t\t%d\t\t%d", m, file[m], file_arr[m], block[file_arr[m]], fragments[m]);
		}
	}
	if(c==3)
	{

		int fragments[10], blocks[10], files[10];
		int m, n, number_of_blocks, number_of_files, temp, top = 0;
		static int block_arr[10], file_arr[10];
		printf("\nEnter the Total Number of Blocks:\t");
		scanf("%d",&number_of_blocks);
		printf("Enter the Total Number of Files:\t");
		scanf("%d",&number_of_files);
		printf("\nEnter the Size of the Blocks:\n");
		for(m = 0; m < number_of_blocks; m++) 
		{
			printf("Block No.[%d]:\t", m + 1);
			scanf("%d", &blocks[m]);
		}
		printf("Enter the Size of the Files:\n");
		for(m = 0; m < number_of_files; m++) 
		{
			printf("File No.[%d]:\t", m + 1);
			scanf("%d", &files[m]);
		}
		for(m = 0; m < number_of_files; m++)
		{
			for(n = 0; n < number_of_blocks; n++)
			{
				if(block_arr[n] != 1)
				{
					temp = blocks[n] - files[m];
					if(temp >= 0)
					{
						if(top < temp)
						{
							file_arr[m] = n;
							top = temp;
						}
					}
				}
				fragments[m] = top;
				block_arr[file_arr[m]] = 1;
				top = 0;
			}
		}
		printf("\nFile Number\tFile Size\tBlock Number\tBlock Size\tFragment");
		for(m = 0; m < number_of_files; m++)
		{
			printf("\n%d\t\t%d\t\t%d\t\t%d\t\t%d", m, files[m], file_arr[m], blocks[file_arr[m]], fragments[m]);
		}

	}
}
