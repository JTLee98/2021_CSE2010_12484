#include "heap.h"
#include <cmath>
#include <iostream>

constexpr int debugArrSize = 26;

int main()
{
	Heap foo(128);
	int data[debugArrSize]{};
	std::cout << "input array: \n";
	for (int i =0; i < debugArrSize; i++)
	{
		data[i] = rand()%1000;
		std::cout << data[i] << ", ";
	}
	foo.insert(data, debugArrSize);
	std::cout << "\nMax Heap at " << &foo << " : \n";
	foo.print();

	std::cout << "\ncall remove 10 times\n";
	for (int i = 0; i < 10; i++)
		foo.remove();
	std::cout << "Max Heap at " << &foo << " : \n";
	foo.print();	

	return 0;
}
