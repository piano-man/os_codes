#include <stdio.h>

#define MARKED 1
#define UNMARKED 0

int main()
{
	int RANGE, n, i, j, x, distance, head_position;

	int MEMORY[10000] = {UNMARKED};


	printf("ENTER NO. OF POSITIONS : ");
	scanf("%d", &n);

	printf ("ENTER THE MEMORY POSITIONS : \n" );
	for (i = 0; i < n; i++) {
		scanf ("%d", &x);
		MEMORY[x] = MARKED;
	}

	printf("ENTER MEMORY RANGE : ");
	scanf("%d", &RANGE);

	printf("ENTER HEAD POSITION : " );
	scanf("%d", &head_position);

    distance = 0;
    
	while(n--) {

		for (i = head_position + 1; i < RANGE; i++) {
			if (MEMORY[i] == MARKED) {
				break;
			}
		}
		for (j = head_position - 1; j >= 0; j--) {
			if (MEMORY[j] == MARKED) {
				break;
			}
		}

		if (((head_position - j) < (i - head_position)) && (j >= 0) ) {
			x = (head_position - j);
			MEMORY[j] = UNMARKED;
			printf("Moving from %d to %d, Distance = %d\n", head_position, j, x);
			head_position = j;
		} else if (i < 10000) {
			x = (i - head_position);
			MEMORY[i] = UNMARKED;
			printf ("Moving from %d to %d, Distance = %d\n", head_position, i, x);
			head_position = i;
		}

		distance += x;
	}

	printf ("TOTAL HEAD MOVEMENT = %d\n", distance);

	return 0;
}
