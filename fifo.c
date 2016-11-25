#include<stdio.h>
#include<stdlib.h>

int main()
{
	int frames[100],pages[1000],n,f,av = 0,fault = 0;
	int i,j,k = 0;
	printf ( "Enter no. of pages ");
	scanf ( "%d",&n );
	printf ( "Enter no. of frames " );
	scanf ( "%d",&f );
	printf ( "Enter the pages " );

	for ( i = 0;i < n;i++ ) {
		scanf ( "%d",&pages[i] );
	}

	for ( j = 0;j < f;j++ ) {
		frames[j] = -1;
		//		frames[j] = j+1;
	}


	printf ( "Page = NIL\t" );
	for ( j = 0;j < f;j++ ) {
		printf ( "%d\t",frames[j] );
	}


	for ( i = 0;i < n;i++ ) {
		av = 0;
		for ( j = 0;j < f;j++ ) {
			if ( pages[i] == frames[j] ) {
				av = 1;
			}
		}

		if ( av == 0 ) {
			frames[k] = pages[i];
			k = ( k + 1 ) % f;
			fault++;
		}


		printf ( "\nPage = %d\t", pages[i] );
		for ( j = 0;j < f;j++ ) {
			printf ( "%d\t",frames[j] );
		}

	}

	printf ( "\n\nNo. of page faults = %d\n",fault );
	return 0;
}
