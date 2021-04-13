#include <iostream>
#include "Stack.hpp"
#include "lnkList.hpp"

void reverseLinkedList(lnkList& input)
{
	//unsigned int count = input.count();
	lnkStack temp;
	// store list in stack
	Node* iter = input.head();
	while (iter != nullptr)
	{
		temp.push(iter->data);
		iter = iter->next;
	}
	// retrieve from stack & store in list
	// this automatically reverses order 
	// (stack is LILO)
	input.empty();
	unsigned int index = 0;
	while (!temp.isEmpty())
	{
		input.insert(index, temp.top()->data);
		temp.pop();
		index++;
	} 
	
}

int main()
{
	lnkList foo;
	foo.insert(0, 10);
	foo.insert(1, 20);
	foo.insert(2, 30);
	foo.insert(3, 40);

	foo.show(); 
	reverseLinkedList(foo);
	foo.show(); 

	return 0;
}