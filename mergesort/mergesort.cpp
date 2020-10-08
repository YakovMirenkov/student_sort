#include "mergesort.h"
void merge(student *a1, student *a2, student *b, int n1, int n2);

void mergesort(student *a, student *b, int n)
{
	int i, sz, j, cnt_swap = 0;
	student *tmp;

	for( sz = 1; sz<n; sz *= 2 )
	{
		for( i = 0; (i + 2)*sz<=n; i += 2 )
			merge(a + i*sz, a + (i + 1)*sz, b + i*sz, sz, sz);

		if( (i + 1)*sz<n )
			merge(a + i*sz, a + (i + 1)*sz, b + i*sz, sz, n - (i + 1)*sz);
		else
			for( j = i*sz; j<n; j++ )
				b[j] = static_cast<student &&>(a[j]);

		tmp = a;
		a = b;
		b = tmp;
		cnt_swap++;
	}

	if( cnt_swap%2 )
		for( i = 0; i<n; i++ )
			b[i] = static_cast<student &&>(a[i]);
}

void merge(student *a1, student *a2, student *b, int n1, int n2)
{
	int i1 = 0, i2 = 0, j;

	for( j = 0; i1<n1 && i2<n2; j++ )
		if( a1[i1]>a2[i2] )
		{
			b[j] = static_cast<student &&>(a2[i2]);
			i2++;
		} else
		{
			b[j] = static_cast<student &&>(a1[i1]);
			i1++;
		}

	for( ; i1<n1; i1++, j++ )
		b[j] = static_cast<student &&>(a1[i1]);
	for( ; i2<n2; i2++, j++ )
		b[j] = static_cast<student &&>(a2[i2]);
}
