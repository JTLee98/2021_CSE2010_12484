#include "Stack.hpp"
#include <iostream>
#include <stdlib.h>

lnkStack::lnkStack()
	:m_count(0), m_top(nullptr) {}

lnkStack::~lnkStack() 
{
	this->del();
}

void lnkStack::push(int p_data)
{
	Node* new_top = new Node;
	new_top->data = p_data;
	new_top->next = m_top;
	this->m_top = new_top;
	m_count++;
}

Node* lnkStack::pop()
{
	Node* temp = m_top;
	this->m_top = temp->next;
	free(temp);
	m_count--;
	return m_top;
}

void lnkStack::show() const
{
	std::cout << "lnkStack at memory address " << this;
	if (this->isEmpty())
		std::cout << "is empty.";
	else
	{
		Node* iter = m_top;
		unsigned int idx = 0;
		std::cout << " :";
		for (iter = m_top; iter != nullptr; iter = iter->next)
		{
			std::cout << "\n[" << idx << "]: " << iter->data;
			idx++;
		}
		return;
	}
}

Node* lnkStack::top() const
{
	return m_top;
}


void lnkStack::del()
{
	Node* iter = m_top, * temp = nullptr;
	while (iter != nullptr)
	{
		temp = iter;
		iter = iter->next;
		free(temp);
	}
	m_count = 0;
	m_top = nullptr;
}

bool lnkStack::isEmpty() const
{
	if (m_count == 0 || m_top == nullptr)
		return true;
	else return false;
}
