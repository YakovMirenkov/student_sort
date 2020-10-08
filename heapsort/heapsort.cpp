#include "heapsort.h"

void heapsort(student *a, int n)
{// Рассматривается бинарное дерево с корнем a[0], где для a[k] потомки: a[2*k + 1], a[2*k + 2], а родитель - a[(k - 1)/2]
	int k, j, parent, child1, child2;
	student tmp;

	// Дерево превращается в такое, где всякая цепочка от корня упорядочена по убыванию
	for( k = 1; k<n; k++ )
	{
		tmp = static_cast<student &&>(a[k]);
		for( j = k, parent = (k - 1)/2; j>0 && tmp>a[parent]; j = parent, parent = (j - 1)/2 )
			a[j] = static_cast<student &&>(a[parent]);
		a[j] = static_cast<student &&>(tmp);
	}

	for( k = n - 1; k>0; k-- )
	{
		a[0].swap(a[k]);
		tmp = static_cast<student &&>(a[0]);
		// Восстановление структуры, где всякая цепочка от корня упорядочена по убыванию
		for( j = 0, child1 = 1, child2 = 2; (child2 = 2*j + 2)<k; child1 = 2*j + 1)
		{
			if( a[child1]>tmp )
			{
				if( a[child2]>a[child1] )
				{
					a[j] = static_cast<student &&>(a[child2]);
					j = child2;
				} else
				{
					a[j] = static_cast<student &&>(a[child1]);
					j = child1;
				}
			} else if( a[child2]>tmp )
			{
				if( a[child1]>a[child2] )
				{
					a[j] = static_cast<student &&>(a[child1]);
					j = child1;
				} else
				{
					a[j] = static_cast<student &&>(a[child2]);
					j = child2;
				}
			} else
				break;
		}
		if( (child1 = 2*j + 1)<k )
		{
			if( a[child1]>tmp )
			{
				a[j] = static_cast<student &&>(a[child1]);
				j = child1;
			}
		}
		a[j] = static_cast<student &&>(tmp);
	}
}
