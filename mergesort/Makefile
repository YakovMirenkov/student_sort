FLAGS = -g -fsanitize=address -mfpmath=sse -fstack-protector-all -g -W -Wall -Wextra -Wunused -Wcast-align -Werror -pedantic -pedantic-errors -Wfloat-equal -Wpointer-arith -Wformat-security -Wmissing-format-attribute -Wformat=1 -Wwrite-strings -Wcast-align -Wno-long-long -Woverloaded-virtual -Wnon-virtual-dtor -Wcast-qual -Wno-suggest-attribute=format

all: mergesort.out mergesort_debug.out

mergesort.out: main.o mergesort.o ../student/student.o ../student/array/array.o
	g++ -O3 main.o mergesort.o ../student/student.o ../student/array/array.o -o mergesort.out
main.o: main.cpp
	g++ -O3 -c main.cpp -o main.o
mergesort.o: mergesort.cpp
	g++ -O3 -c mergesort.cpp -o mergesort.o
../student/student.o: ../student/student.cpp
	g++ -O3 -c ../student/student.cpp -o ../student/student.o
../student/array/array.o: ../student/array/array.cpp
	g++ -O3 -c ../student/array/array.cpp -o ../student/array/array.o

mergesort_debug.out: main_debug.o mergesort_debug.o ../student/student_debug.o ../student/array/array_debug.o
	g++ $(FLAGS) main_debug.o mergesort_debug.o ../student/student_debug.o ../student/array/array_debug.o -o mergesort_debug.out
main_debug.o: main.cpp
	g++ $(FLAGS) -c main.cpp -o main_debug.o
mergesort_debug.o: mergesort.cpp
	g++ $(FLAGS) -c mergesort.cpp -o mergesort_debug.o
../student/student_debug.o: ../student/student.cpp
	g++ $(FLAGS) -c ../student/student.cpp -o ../student/student_debug.o
../student/array/array_debug.o: ../student/array/array.cpp
	g++ $(FLAGS) -c ../student/array/array.cpp -o ../student/array/array_debug.o

mrproper_all: mrproper mrproper_student

mrproper:
	rm *.o *.out

mrproper_student:
	rm ../student/*.o ../student/array/*.o
