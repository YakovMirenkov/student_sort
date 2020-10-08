#include <cstdio>
#include "array.h"

void print_array(student *a, int n, int d)
{
	int i;

	if( n>d )
		n = d;

	for( i = 0; i<n; i++ )
		a[i].print();
}

int read_array(char *name, student *a, int n)
{
	FILE *in;
	int i;

	if( !(in = fopen(name, "r")) )
		return OPEN_ERROR;

	for( i = 0; i<n; i++ )
		if( a[i].read(in)!=student::SUCCESS )
		{
			fclose(in);
			return READ_ERROR;
		}

	fclose(in);
	return SUCCESS;
}

int init_array(int (*f)(int, int, student *), student *a, int n)
{
	int i, res_f;

	for( i = 0; i<n; i++ )
	{
		if( (res_f = f(n, i, a + i))!=student::SUCCESS )
			return res_f;
	}

	return student::SUCCESS;
}
