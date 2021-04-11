#include <iostream>
#include "circularQueue.hpp"
#include "Stack.hpp"

int main()
{
	std::cout << "===========<lnkStack demo>============\n";
	lnkStack foo;
	std::cout << "lnkStack::push(10)\n";
	foo.push(10);
	std::cout << "lnkStack::push(20)\n";
	foo.push(20);
	std::cout << "lnkStack::push(30)\n";
	foo.push(30);	

	std::cout << "lnkStack::pop()\n";
	Node* pNode = foo.pop();
	if (pNode)
	{
		free(pNode);
		foo.show();
	}
	
	Node* top = foo.top();
	std::cout
		<< "lnkStack::top()\n" << "data: ";
	if (top == nullptr)
		std::cout << " lnkList is empty."; 
	else std::cout << top->data;

	foo.del();

	std::cout << "\n===========<cQueue demo>============\n";
	cQueue bar;
	std::cout
		<< "front: " << bar.front()
		<< " rear: " << bar.rear() << '\n';

	bar.enqueue(10);
	bar.enqueue(20);
	bar.enqueue(30);
	std::cout << "front: " << bar.front();
	std::cout << ", rear: " << bar.rear();

	bar.deque();
	bar.deque();
	std::cout << "front: " << bar.front();
	std::cout << ", rear: " << bar.rear();

	bar.enqueue(40);
	std::cout << "front: " << bar.front();
	std::cout << ", rear: " << bar.rear();

	bar.enqueue(50);
	std::cout << "front: " << bar.front();
	std::cout << ", rear: " << bar.rear();

	bar.enqueue(60);
	std::cout << "front: " << bar.front();
	std::cout << ", rear: " << bar.rear();

	bar.enqueue(70);
	std::cout << "front: " << bar.front();
	std::cout << ", rear: " << bar.rear();
	
	bar.show();
	return 0;
}