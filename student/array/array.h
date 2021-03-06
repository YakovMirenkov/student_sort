#ifndef STUDENT_ARRAY_H
#define STUDENT_ARRAY_H

#include "../student.h"

enum ERRORS
{
	SUCCESS = 0,
	OPEN_ERROR,
	READ_ERROR,
};

void print_array(student *a, int n, int d);
int read_array(char *name, student *a, int n);
int init_array(int (*f)(int, int, student *), student *a, int n);

#endif
