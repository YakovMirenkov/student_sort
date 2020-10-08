#include "bininsertsort.h"

void bininsertsort(student *a, int n)
{
	int i, j, left, right, middle;
	student tmp;

	for( i = 1; i<n; i++ )
	{
		left = 0;
		right = i;
		while( left<right )
		{
			middle = (left + right)/2;

			if( a[i]>a[middle] )
				left = middle + 1;
			else
				right = middle;
		}

		tmp = static_cast<student &&>(a[i]);
		for( j = i; j>left; j-- )
			a[j] = static_cast<student &&>(a[j - 1]);
		a[left] = static_cast<student &&>(tmp);
	}
}
