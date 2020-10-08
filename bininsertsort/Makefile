FLAGS = -g -fsanitize=address -mfpmath=sse -fstack-protector-all -g -W -Wall -Wextra -Wunused -Wcast-align -Werror -pedantic -pedantic-errors -Wfloat-equal -Wpointer-arith -Wformat-security -Wmissing-format-attribute -Wformat=1 -Wwrite-strings -Wcast-align -Wno-long-long -Woverloaded-virtual -Wnon-virtual-dtor -Wcast-qual -Wno-suggest-attribute=format

all: bininsertsort.out bininsertsort_debug.out

bininsertsort.out: main.o bininsertsort.o ../student/student.o ../student/array/array.o
	g++ -O3 main.o bininsertsort.o ../student/student.o ../student/array/array.o -o bininsertsort.out
main.o: main.cpp
	g++ -O3 -c main.cpp -o main.o
bininsertsort.o: bininsertsort.cpp
	g++ -O3 -c bininsertsort.cpp -o bininsertsort.o
../student/student.o: ../student/student.cpp
	g++ -O3 -c ../student/student.cpp -o ../student/student.o
../student/array/array.o: ../student/array/array.cpp
	g++ -O3 -c ../student/array/array.cpp -o ../student/array/array.o

bininsertsort_debug.out: main_debug.o bininsertsort_debug.o ../student/student_debug.o ../student/array/array_debug.o
	g++ $(FLAGS) main_debug.o bininsertsort_debug.o ../student/student_debug.o ../student/array/array_debug.o -o bininsertsort_debug.out
main_debug.o: main.cpp
	g++ $(FLAGS) -c main.cpp -o main_debug.o
bininsertsort_debug.o: bininsertsort.cpp
	g++ $(FLAGS) -c bininsertsort.cpp -o bininsertsort_debug.o
../student/student_debug.o: ../student/student.cpp
	g++ $(FLAGS) -c ../student/student.cpp -o ../student/student_debug.o
../student/array/array_debug.o: ../student/array/array.cpp
	g++ $(FLAGS) -c ../student/array/array.cpp -o ../student/array/array_debug.o

mrproper_all: mrproper mrproper_student

mrproper:
	rm *.o *.out

mrproper_student:
	rm ../student/*.o ../student/array/*.o
