#pragma once

#include "Node.h"

class lnkStack
{
private:
	Node* m_top;
	unsigned int m_count;
public:
	lnkStack();
	~lnkStack();

	void push(int p_data);
	Node* pop();
	void show() const;
	Node* top() const;
	void del();
	bool isEmpty() const;
};