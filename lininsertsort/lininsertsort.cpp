#include "lininsertsort.h"

void lininsertsort(student *a, int n)
{
	int i, j;
	student tmp;

	for( i = 1; i<n; i++ )
	{
		tmp = static_cast<student &&>(a[i]);
		for( j = i - 1; j>=0 && a[j]>tmp; j-- )
			a[j + 1] = static_cast<student &&>(a[j]);

		a[j + 1] = static_cast<student &&>(tmp);
	}
}
