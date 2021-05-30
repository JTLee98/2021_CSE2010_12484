#include "HashTable.h"
#include <cstring>
#include <iostream>

// chaining hashtable node
// (~= linked list)
HashTable_Chain::Node::Node()
	: data(nullptr), prev(nullptr), next(nullptr) {}

HashTable_Chain::Node::Node(const char* data)
	: prev(nullptr), next(nullptr)
{
	char* temp = new char[256];
	strcpy_s(temp, 256, data);
	this->data = temp;
}

HashTable_Chain::HashTable_Chain()
	:hashf(nullptr), m_arrsize(0), m_table(nullptr), m_currKey(0), m_currNode(nullptr) {}

HashTable_Chain::HashTable_Chain(hashfunc_ptr hash, unsigned int arr_size)
	: hashf(hash), m_arrsize(arr_size), m_currKey(0), m_currNode(nullptr)
{
	m_table = new Node*[arr_size];
	for (unsigned int i = 0; i < m_arrsize; i++)
		m_table[i] = nullptr;
}

HashTable_Chain::~HashTable_Chain()
{
	delete[] m_table;
}

int HashTable_Chain::add(const char* data)
{
	m_currKey = this->hashf(data);
	Node* newNode = new Node(data);
	m_currNode = m_table[m_currKey];
	// if bucket is empty, (i.e. no clashes)
	// just insert and return
	if (m_currNode == nullptr)
	{
		m_table[m_currKey] = newNode;
		return m_currKey;
	}
	// if not empty (m_currNode != nullptr) 
	// traverse down linked list to tail 
	// & insert newNode
	while (m_currNode->next != nullptr)
	{
		// check for duplicate
		if (strcmp(m_currNode->data, data) == 0)
			return -1;
		m_currNode = m_currNode->next;
	}
	// after while loop is finished,
	// m_currNode is pointing to tail
	m_currNode->next = newNode;
	newNode->prev = m_currNode;
	return m_currKey;

}

// returns this->hashf(data) if data is in table
// if not in table, return -1
int HashTable_Chain::contains(const char* data)
{
	m_currKey = this->hashf(data);
	m_currNode = m_table[m_currKey];
	while (m_currNode != nullptr)
	{
		if (strcmp(m_currNode->data, data) == 0)
			return m_currKey;
		m_currNode = m_currNode->next;
	}
	return -1;
}

int HashTable_Chain::remove(const char* data)
{
	if (this->contains(data) == -1)
		return -1;
	// delete m_currNode
	Node* prev = m_currNode->prev;
	Node* next = m_currNode->next;
	if (next != nullptr)
		next->prev = prev;
	if (prev != nullptr)
		prev->next = next;
	delete m_currNode;
	return m_currKey;
}

void HashTable_Chain::print() const
{
	std::cout << "HashTable(chain) at " << this << ": \n";
	Node* iter = nullptr;
	for (unsigned int i = 0; i < m_arrsize; i++)
	{
		std::cout << "[key " << i << "] : (";
		iter = m_table[i];
		while (iter != nullptr)
		{
			std::cout << iter->data << ") -> (";
			iter = iter->next;
		}
		std::cout << "X)\n";
	}
}
