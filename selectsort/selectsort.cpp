#include "selectsort.h"

void selectsort(student *a, int n)
{
	int i, i_min, j;

	for( j = 0; j<(n - 1); j++ )
	{
		i_min = j;
		for( i = j + 1; i<n; i++ )
			if( a[j]>a[i] )
				i_min = i;

		a[i_min].swap(a[j]);
	}
}
