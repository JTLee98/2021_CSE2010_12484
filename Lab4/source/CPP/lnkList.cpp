// lnkList source (using CPP)

#include "lnkList.hpp"

#include <iostream>
#include <sstream>
#include <stdexcept>


lnkList::lnkList()
	:m_count(0), m_head(nullptr) {}


lnkList::~lnkList()
{
	this->empty();
	m_head = nullptr;
}


Node* lnkList::operator[](unsigned int pos)
{
	// throw exception if 
	// lnkList is empty 
	// or pos is out of range
	if (pos > m_count)
	{
		if (m_count == 0)
		{
			std::stringstream msg;
			msg << "lnkList is empty"
				<< " (lnkList location = "
				<< m_head << ")\n";
			std::out_of_range e(msg.str().c_str());
			throw e;
		}
		else
		{
			std::stringstream msg;
			msg << "position " << pos
				<< " out of range"
				<< " (lnkList location = "
				<< m_head << ")\n";
			std::out_of_range e(msg.str().c_str());
			throw e;
		}
	}
	
	// else return pointer to node
	else
	{
		Node* iter = m_head;
		for (unsigned int i = 0; i < pos; i++)
			iter = iter->next;
		return iter;
	}
}


unsigned int lnkList::count() const
{
	return m_count;
}


Node* lnkList::head() const
{
	return m_head;
}


void lnkList::insert(unsigned int pos, int pdata)
{
	Node* newNode = new Node;
	try
	{
		newNode->next = (*this)[pos];
		if (pos == 0)
			m_head = newNode;
		else
			(*this)[pos - 1]->next = newNode;
	}
	catch (std::out_of_range& err)
	{
		std::cout 
			<< "ERROR lnkList::insert() : "
			<< err.what();
	}
	
	newNode->data = pdata;
	m_count++;
	return;
}


void lnkList::rm(unsigned int pos)
{
	Node* current = nullptr;
	try
	{
		// test if pos is in range
		current = (*this)[pos];
	}
	catch (std::out_of_range& err)
	{
		std::cout
			<< "ERROR lnkList::rm() : "
			<< err.what();
		return;
	}
	
	if (pos == 0)
	{
		m_head = m_head->next;
	}
	else
	{
		Node* prev = (*this)[pos - 1];
		prev->next = current->next;
	}
	delete current;
	m_count--;
	return;
}


void lnkList::show() const
{
	if (m_count == 0)
	{
		std::cout << "lnkList is empty";
		return;
	}

	Node* iter = m_head;
	int i = 0;
	while (iter != nullptr)
	{
		std::cout
			<< '[' << i << "]: "
			<< iter->data << '\n';
		iter = iter->next;
		i++;
	}
	return;
}


bool lnkList::isEmpty() const
{
	if (m_count == 0) return true;
	else return false;
}


Node* lnkList::findNode(int pdata) const
{
	if (m_count == 0) return nullptr;
	Node* iter = m_head;
	while (iter->data != pdata)
		iter = iter->next;
	return iter;
}


int lnkList::findPos(int pdata) const
{
	if (m_count == 0) return -1;
	Node* iter = m_head;
	int i = 0;
	while (iter->data != pdata)
	{
		iter = iter->next;
		i++;
	}
	return i;
	
}


void lnkList::empty()
{
	if (m_count == 0) return;
	Node* iter = m_head;
	while (iter != nullptr)
	{
		Node* temp = iter;
		iter = iter->next;
		delete temp;
	}
	m_count = 0;
	return;
}
