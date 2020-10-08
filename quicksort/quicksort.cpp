#include "quicksort.h"

void quicksort(student *a, int n)
{
	int i, j;
	student tmp;

	while( n>1 )
	{
		i = 0;
		j = n - 1;
		tmp = a[n/2];
		while( i<j )
		{
			while( tmp>a[i] )
				i++;
			while( a[j]>tmp )
				j--;
			// Найдено первое a[i]>=a[n/2] и последнее a[j]<=a[n/2]

			if( i>=j )
				break;
			a[i].swap(a[j]);
			i++;
			j--;
		}

		if( i<=(n - i) )
		{
			quicksort(a, i);
			a += i;
			n -= i;
		} else
		{
			quicksort(a + i, n - i);
			n = i;
		}
	}
}
