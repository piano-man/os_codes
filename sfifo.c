#include <stdio.h>

int main()
{
	int N_PAGES;
	printf("ENTER THE NUMBER OF PAGES : ");
	scanf("%d", &N_PAGES);
	int PAGES[N_PAGES];
	
	int i, j, k;	
	printf("ENTER THE PAGES : \n");
	for(i = 1; i <= N_PAGES; i++)
		scanf("%d", &PAGES[i]);

	int N_FRAMES;
	printf("ENTER THE NUMBER OF FRAMES : ");
	scanf("%d", &N_FRAMES);
	int FRAMES[N_FRAMES];

	for(i = 0; i < N_FRAMES;i++)
        FRAMES[i]= -1;
        
	j = 0;
	int avail, count = 0;
    printf("REF. STRING\tPAGE FRAMES\n");
	for(i = 1; i <= N_PAGES; i++) {
		printf("%d\t\t", PAGES[i]);
		avail = 0;
		for(k = 0; k < N_FRAMES; k++)
			if(FRAMES[k] == PAGES[i])
				avail=1;
        if (avail == 0) {
			FRAMES[j] = PAGES[i];
			j = (j + 1) % N_FRAMES;
            count++;
            for(k = 0; k < N_FRAMES; k++)
				if(FRAMES[k] != -1)
	            	printf("%d\t", FRAMES[k]);
				else
					printf(" \t");
		}
		printf("\n");
	}
    printf("NO. OF PAGE FAULTS = %d\n", count);
    return 0;
}

