#include "circularQueue.hpp"
#include <iostream>

cQueue::cQueue()
	: m_data(), m_front(0), m_rear(0){}

cQueue::~cQueue()
{
}

int cQueue::front() const
{
	return m_front;
}

int cQueue::rear() const
{
	return m_rear;
}

void cQueue::enqueue(int p_data)
{
	if (this->isFull())
	{
		std::cout
			<< "Circular Queue at memory address"
			<< this << "is full.\n";
		return;
	}
	else
	{
		std::cout << "enque data " << p_data << std::endl;
		m_rear = (m_rear + 1) % CAPACITY;
		m_data[m_rear] = p_data;
	}
	return;
}

bool cQueue::isFull() const
{
	if ((m_rear + 1) % CAPACITY == m_front) return true;
	else return false;
}

bool cQueue::isEmpty() const
{
	if (m_rear == m_front) return true;
	else return false;
}

void cQueue::show() const
{
	std::cout << "Circular Queue at memory address" << this;
	if (this->isEmpty())
	{
		std::cout << "is empty.\n";
		return;
	}
	std::cout << ": \n";
	int i = 0;
	for (i = m_front + 1; i != m_rear; i = (i + 1) % CAPACITY)
		std::cout << m_data[i] << '\n';
	std::cout << m_data[i] << '\n';
	return;
}

void cQueue::deque()
{
	if (this->isEmpty())
	{
		std::cout
			<< "Circular Queue at memory address"
			<< this << "is empty.\n";
		return;
	}
	m_front = (m_front + 1) % CAPACITY;
	std::cout << "deque\n";
	return;
}
