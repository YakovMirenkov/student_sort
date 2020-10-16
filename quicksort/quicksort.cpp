#include "quicksort.h"

void quicksort(student *a, int n)
{
	int i, j;

	while( n>1 )
	{
		i = 0;
		j = n - 1;
		while( i<j )
		{
			while( a[n/2]>a[i] )
				i++;
			while( a[j]>a[n/2] )
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
