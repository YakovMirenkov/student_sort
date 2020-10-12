#ifndef STUDENT_H
#define STUDENT_H

class student
{
private:
	char *name = nullptr;
	int value = 0;

public:
	enum ERRORS
	{
		SUCCESS = 0,
		READ_ERROR,
		ALLOC_ERROR
	};

	int init(const char *new_name, int new_value);
	void rm();
	int get_value() const { return value; }
	const char *get_name() const { return const_cast<const char *>(name); }
	student(const char *new_name = nullptr, int new_value = 0);
	student(const student &x);
	student(student &&x);
	~student();
	student &operator=(const student &x);
	student &operator=(student &&x);
	int operator>(const student &x) const;
	void swap(student &x);
	int read(FILE *in);
	void print() const;
	int init_rand();
};

#endif// STUDENT_H
