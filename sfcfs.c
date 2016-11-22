#include <stdio.h>

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
    
	for (i = 0; i < n; i++) {
		if (head_position > MEMORY[i]) {
			x = (head_position - MEMORY[i]);
		} else {
			x = (MEMORY[i] - head_position);
		}
		printf("Moving from %d to %d, distance = %d\n", head_position, MEMORY[i], x);
		distance += x;
		head_position = MEMORY[i];
	}

	printf ("TOTAL HEAD MOVEMENT = %d\n", distance);

	return 0;
}
