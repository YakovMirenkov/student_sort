FLAGS = -g -fsanitize=address -mfpmath=sse -fstack-protector-all -g -W -Wall -Wextra -Wunused -Wcast-align -Werror -pedantic -pedantic-errors -Wfloat-equal -Wpointer-arith -Wformat-security -Wmissing-format-attribute -Wformat=1 -Wwrite-strings -Wcast-align -Wno-long-long -Woverloaded-virtual -Wnon-virtual-dtor -Wcast-qual -Wno-suggest-attribute=format

all: bubblesort.out bubblesort_debug.out

bubblesort.out: main.o bubblesort.o ../student/student.o ../student/array/array.o
	g++ -O3 main.o bubblesort.o ../student/student.o ../student/array/array.o -o bubblesort.out
main.o: main.cpp
	g++ -O3 -c main.cpp -o main.o
bubblesort.o: bubblesort.cpp
	g++ -O3 -c bubblesort.cpp -o bubblesort.o
../student/student.o: ../student/student.cpp
	g++ -O3 -c ../student/student.cpp -o ../student/student.o
../student/array/array.o: ../student/array/array.cpp
	g++ -O3 -c ../student/array/array.cpp -o ../student/array/array.o

bubblesort_debug.out: main_debug.o bubblesort_debug.o ../student/student_debug.o ../student/array/array_debug.o
	g++ $(FLAGS) main_debug.o bubblesort_debug.o ../student/student_debug.o ../student/array/array_debug.o -o bubblesort_debug.out
main_debug.o: main.cpp
	g++ $(FLAGS) -c main.cpp -o main_debug.o
bubblesort_debug.o: bubblesort.cpp
	g++ $(FLAGS) -c bubblesort.cpp -o bubblesort_debug.o
../student/student_debug.o: ../student/student.cpp
	g++ $(FLAGS) -c ../student/student.cpp -o ../student/student_debug.o
../student/array/array_debug.o: ../student/array/array.cpp
	g++ $(FLAGS) -c ../student/array/array.cpp -o ../student/array/array_debug.o

mrproper_all: mrproper mrproper_student

mrproper:
	rm *.o *.out

mrproper_student:
	rm ../student/*.o ../student/array/*.o
