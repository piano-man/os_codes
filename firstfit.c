#include <stdio.h>

#define MAX 10000

int main()
{
	int BLOCK_ARRAY[MAX], FILE_ARRAY[MAX];
	int FRAGMENTS[MAX], BLOCKS[MAX], FILES[MAX];

	int m, n, number_of_blocks, number_of_files, temp;

 	printf("ENTER THE TOTAL NUMBER OF BLOCKS :\t");
 	scanf("%d", &number_of_blocks);

 	printf("ENTER THE TOTAL NUMBER OF FILES :\t");
 	scanf("%d", &number_of_files);
 	
 	printf("\nENTER THE SIZE OF BLOCKS:\n");
 	for(m = 0; m < number_of_blocks; m++)
		scanf("%d", &BLOCKS[m]);

	printf("\nENTER THE SIZE OF FILES:\n");
 	for(m = 0; m < number_of_files; m++)
		scanf("%d", &FILES[m]);

	for(m = 0; m < number_of_files; m++)
 	{
  		for(n = 0; n < number_of_blocks; n++)
  		{
   			if(BLOCK_ARRAY[n] != 1)
   			{
    				temp = BLOCKS[n] - FILES[m];
    				if(temp >= 0)
    				{
     					FILE_ARRAY[m] = n;
     					break;
    				}
   			}
  		}
  		FRAGMENTS[m] = temp;
  		BLOCK_ARRAY[FILE_ARRAY[m]] = 1;
 	}
	
 	printf("\nFile Number\tBlock Number\tFile Size\tBlock Size\tFragment");
 	for(m = 0; m < number_of_files; m++)
 	{
		printf("\n%d\t\t%d\t\t%d\t\t%d\t\t%d", m, FILE_ARRAY[m], FILES[m], BLOCKS[FILE_ARRAY[m]], FRAGMENTS[m]);
	}
	printf("\n");

	return 0;
}