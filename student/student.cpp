#include <cstring>
#include <cstdio>
#include <cstdlib>
#include "student.h"

#define MAX_NAME_LEN 10
#define SCAN_STUDENT_FORMAT "%10s%d"// %MAX_NAME_LENs%d

int student::init(const char *new_name, int new_value)
{
	size_t len;
	size_t i;

	value = new_value;

	if( new_name==nullptr )
	{
		name = nullptr;
		return SUCCESS;
	}

	len = strlen(new_name);
	if( (name = new char[len + 1])==nullptr )
		return ALLOC_ERROR;
	for( i = 0; i<=len; i++ )
		name[i] = new_name[i];

	return SUCCESS;
}

void student::rm()
{
	if( name!=nullptr )
	{
		delete[] name;
		name = nullptr;
	}
	value = 0;
}

student::student(const char *new_name, int new_value)
{
	init(new_name, new_value);
}

student::student(const student &x)
{
	init(x.name, x.value);
}

student::student(student &&x)
{
	name = x.name;
	x.name = nullptr;
	value = x.value;
}

student::~student()
{
	rm();
}

student &student::operator=(const student &x)
{
	if( this->name==x.name )
	{
		value = x.value;
		return *this;
	}

	rm();
	init(x.name, x.value);

	return *this;
}

student &student::operator=(student &&x)
{
	name = x.name;
	x.name = nullptr;
	value = x.value;
	return *this;
}

int student::operator>(const student &x) const
{
	int namecmp = strcmp(name, x.name);
	int valcmp;

	if( namecmp>0 )
		return namecmp;
	if( namecmp<0 )
		return 0;

	valcmp = value - x.value;
	if( valcmp>0 )
		return valcmp;

	return 0;
}

void student::swap(student &x)
{
	int tmp_value;
	char *tmp_name;

	tmp_name = name;
	name = x.name;
	x.name = tmp_name;

	tmp_value = value;
	value = x.value;
	x.value = tmp_value;
}

int student::read(FILE *in)
{
	char new_name[MAX_NAME_LEN + 1];
	int new_value;

	if( fscanf(in, SCAN_STUDENT_FORMAT/* %MAX_NUM_LENs%d */, new_name, &new_value)!=2 )
		return READ_ERROR;
	rm();
	return init(new_name, new_value);
}

void student::print() const
{
	if( name!=nullptr )
		printf("%s\t%d\n", name, value);
}

int student::init_rand()
{
	int i, len = rand()%MAX_NAME_LEN + 1;

	if( (name = new char[len])==nullptr )
		return ALLOC_ERROR;

	for( i = 0; (i + 1)<len; i++ )
	{
		name[i] = static_cast<char>(97 + rand()%26);
	}
	name[len - 1] = '\0';
	value = rand();

	return SUCCESS;
}
