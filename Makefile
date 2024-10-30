QuickSort: QuickSort.o
	g++ -g -o QuickSort.exe QuickSort.o -pthread    

QuickSort.o: QuickSort/QuickSort.cpp
	g++ -g  -c -pthread QuickSort/QuickSort.cpp
