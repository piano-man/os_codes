#include <stdio.h>

#define MARKED 1
#define UNMARKED 0

int main()
{
	int RANGE, n, i, j, x, distance, head_position;
	int min = INT_MAX, max = INT_MIN;

	int MEMORY[10000] = {UNMARKED};


	printf("ENTER NO. OF POSITIONS : ");
	scanf("%d", &n);

	printf ("ENTER THE MEMORY POSITIONS : \n" );
	for (i = 0; i < n; i++) {
		scanf ("%d", &x);
		MEMORY[x] = MARKED;

		if(x > max) max = x;
		if(x < min) min = x;
	}

	printf("ENTER MEMORY RANGE : ");
	scanf("%d", &RANGE);

	printf("ENTER HEAD POSITION : " );
	scanf("%d", &head_position);

	int temp = head_position, count = 0;
	distance = 0;

	for (i = head_position - 1; i >= min; i--) {
		if ((MEMORY[i] == MARKED) || (i == 0)) {
			x = temp - i;
			distance += x;
			MEMORY[i] = UNMARKED;
			printf("Moving from %d to %d, Distance = %d\n", temp, i, x);
			temp = i;
			count++;
		}
	}
	if(count != n) {
		temp = max;
		printf("Moving from %d to %d, Distance = %d\n", min, max, (max - min));
		distance += (max - min);
		
		for (j = max - 1; j >= 0; j--) {
			if (MEMORY[j] == MARKED) {
				x = temp - j;
				MEMORY[j] = UNMARKED;
				distance += x;
				printf("Moving from %d to %d, Distance = %d\n", temp, j, x);
				temp = j;
			}
		}
	}

	printf ("TOTAL HEAD MOVEMENT = %d\n", distance);

	return 0;
}
