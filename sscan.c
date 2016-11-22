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

	int temp = head_position;
    distance = 0;

	for (i = head_position - 1; i >= 0; i--) {
		if ((MEMORY[i] == MARKED) || (i == 0)) {
			x = temp - i;
			distance += x;
			MEMORY[i] = UNMARKED;
			printf("Moving from %d to %d, Distance = %d\n", temp, i, x);
			temp = i;
		}
	}

	temp = 0;
	for (j = 0; j < RANGE; j++) {
		if (MEMORY[j] == MARKED) {
			x = j - temp;
			MEMORY[j] = UNMARKED;
			distance += x;
			printf("Moving from %d to %d, Distance = %d\n", temp, j, x);
			temp = j;
		}
	}

	printf ("TOTAL HEAD MOVEMENT = %d\n", distance);

	return 0;
}
