#include <iostream>
#include "BST.h"

int main()
{
	BST foo;

	foo.insert(4);
	foo.insert(2);
	foo.insert(6);
	foo.insert(1);
	foo.insert(3);
	foo.insert(5);
	foo.insert(7);

	std::cout << "Pre order : ";
	foo.print(BST_ORDER_PRE);
	std::cout << "\nIn order : ";
	foo.print(BST_ORDER_IN);
	std::cout << "\nPost order : ";
	foo.print(BST_ORDER_POST);

	return 0;
}