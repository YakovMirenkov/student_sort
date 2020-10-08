#include "selectsort.h"

void selectsort(student *a, int n)
{
	int i, i_min, j;
	student tmp;

	for( j = 0; j<(n - 1); j++ )
	{
		i_min = j;
		tmp = a[j];
		for( i = j + 1; i<n; i++ )
			if( tmp>a[i] )
			{
				i_min = i;
				tmp = a[i];
			}

		a[i_min].swap(a[j]);
	}
}
