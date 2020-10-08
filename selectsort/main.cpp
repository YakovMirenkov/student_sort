#include <cstdio>
#include <cstdlib>
#include <ctime>
#include "../student/student.h"
#include "../student/array/array.h"
#include "selectsort.h"
int f_rand(int n, int i, student *x);
int f1(int n, int i, student *x);
int f2(int n, int i, student *x);
int f3(int n, int i, student *x);
int f4(int n, int i, student *x);

#define ERROR (-1)
#define DEF_NAME "Student\0"

int main(int argc, char **argv)
{
	int n, d, num_f = 0, res_read, res_init, (*f)(int, int, student *) = nullptr;
	student *a;
	clock_t t;

	if( (argc!=3 && argc!=4) || (n = atoi(argv[1]))<=0 || sscanf(argv[2], "%d", &d)!=1 || d<0 || d>n || (argc==4 && argv[3][0]=='-' && argv[3][1]=='F' && (num_f = atoi(argv[3] + 2))<=0) )
	{
		fprintf(stderr, "Usage:\n\t%s size display\n\t%s size display [file]\n\t%s size display [-Fformula]\n", argv[0], argv[0], argv[0]);
		return ERROR;
	}

	if( argc==3 )
		f = f_rand;
	if( num_f>0 )
	{
		switch( num_f )
		{
		case 1:
			f = f1;
			break;
		case 2:
			f = f2;
			break;
		case 3:
			f = f3;
			break;
		case 4:
			f = f4;
			break;
		default:
			fprintf(stderr, "Can not find formula number %d!\n", num_f);
			return ERROR;
		}
	}

	if( (a = new student[n])==nullptr )
	{
		fprintf(stderr, "Can not allocate memory!\n");
		return ERROR;
	}

	if( f==nullptr )
	{
		if( (res_read = read_array(argv[3], a, n))!=SUCCESS )
		{
			switch( res_read )
			{
			case OPEN_ERROR:
				fprintf(stderr, "Can not open %s!\n", argv[3]);
				break;
			case READ_ERROR:
				fprintf(stderr, "Can not read %d students from %s!\n", n, argv[3]);
				break;
			default:
				fprintf(stderr, "Unknown error with code %d!\n", res_read);
			}
			delete[] a;
			return ERROR;
		}
	} else
	{
		if( (res_init = init_array(f, a, n))!=student::SUCCESS )
		{
			switch( res_init )
			{
			case student::ALLOC_ERROR:
				fprintf(stderr, "Can not allocate memory!\n");
				break;
			default:
				fprintf(stderr, "Unknown error with code %d!\n", res_init);
			}
			delete[] a;
			return ERROR;
		}
	}

	print_array(a, n, d);
	printf("\nSorting...\n\n");
	t = clock();
	selectsort(a, n);
	t = clock() - t;
	print_array(a, n, d);
	printf("Time: %.2f sec\n", (float)t/CLOCKS_PER_SEC);

	delete[] a;
	return 0;
}

int f_rand(int n, int i, student *x)
{
	(void)n;
	(void)i;
	return x->init_rand();
}
int f1(int n, int i, student *x)
{
	(void)n;
	return x->init(DEF_NAME, i);
}
int f2(int n, int i, student *x)
{
	return x->init(DEF_NAME, n - i);
}
int f3(int n, int i, student *x)
{
	(void)n;
	return x->init(DEF_NAME, i/2);
}
int f4(int n, int i, student *x)
{
	return x->init(DEF_NAME, n - i/2);
}
