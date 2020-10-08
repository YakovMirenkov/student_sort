#include "bubblesort.h"

void bubblesort(student *a, int n)
{
	int i, j;

	for( j = 0; j<(n - 1); j++ )
		for( i = 0; i<(n - 1 - j); i++ )
			if( a[i]>a[i + 1] )
				a[i].swap(a[i + 1]);
}
