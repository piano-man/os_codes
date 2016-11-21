#include <stdio.h>
#include <stdlib.h>

int main () {
	int a[100],n,head,total_time=0,diff,i,jk;
	float avg;
	printf ("Enter number of elements: ");
	scanf ("%d", &n);
	printf ("Enter Inputs: ");
	for (i = 1; i <= n; i++) {
		scanf ("%d", &a[i]);
	}
	printf ("Enter head: ");
	scanf ("%d", &head);
	int temp = n,a1[100],min,l;
	while (temp--) {
		for (i = 1; i <= n; i++) {
			a1[i] = 999;
		}
		for (i = 1; i <= n; i++) {
			a1[i] = abs(a[i] - head);
		}
		min = 9999;
		l = -1;
		for (i = 1; i <= n; i++) {
			if (a1[i] < min) {
				min = a1[i];
				l = i;
			}
		}
		diff = abs(head-a[l]);
		total_time += diff;
		printf ("Move from %d to %d with seek %d\n",head,a[l],diff);
		head = a[l];
		a[l] = 10000;
	}
	printf ("Total seek is: %d\n",total_time);
	avg = (float)total_time/n;
	printf ("Average seek is: %f\n",avg);
	return 0;
}
