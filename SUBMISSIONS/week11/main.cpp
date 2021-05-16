#include "AVLTree.h"
#include <iostream>
#include <cmath>

int main()
{
	int test_data[30]{};
	std::cout << "test data: ";
	for (int i = 0; i < 30; i++)
	{
		test_data[i] = rand() % 100;
		std::cout << test_data[i] << ", ";
	}

	AVLTree foo;
	foo.insert(test_data,30);
	std::cout << '\n';
	foo.print();
}