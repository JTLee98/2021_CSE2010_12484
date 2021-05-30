#include "HashTable.h"
#include <iostream>

HashTable_LinProbe::HashTable_LinProbe()
	:hashf(nullptr),m_table(nullptr), m_arrsize(0), m_currKey(0), m_full(false) {}

HashTable_LinProbe::HashTable_LinProbe(hashfunc_ptr hash, unsigned int arr_size)
	: hashf(hash), m_arrsize(arr_size), m_currKey(0), m_full(false)
{
	m_table = new const char* [arr_size];
	for (unsigned int i = 0; i < arr_size; i++)
		m_table[i] = nullptr;
}

HashTable_LinProbe::~HashTable_LinProbe()
{
	delete[] m_table; 
}

int HashTable_LinProbe::add(const char* data)
{
	// chack duplicate/full & set m_currKey
	if (this->contains(data) != -1 || this->m_full)
		return -1;

	int key = m_currKey;
	while (m_table[key] != nullptr)
	{
		key = (key + 1) % m_arrsize;
		// cycled back to origin 
		// -> table is full 
		if (key == m_currKey)
		{
			this->m_full = true;
			return -1;
		}
	}
	// found empty spot
	unsigned int length = strlen(data);
	char* temp = new char[4 * length];
	strcpy_s(temp, 4 * length, data);
	m_table[key] = temp;
	return key;

}

int HashTable_LinProbe::contains(const char* data)
{
	m_currKey = hashf(data);
	int key = m_currKey;
	const char* iter = m_table[key];
	while (iter != nullptr)
	{
		// found exact match
		if (strcmp(iter, data) == 0)
			return key;

		key = (key + 1) % m_arrsize;
		
		// cycled back to origin
		if (key == m_currKey) 
			return -1;
		iter = m_table[key];
	}
	return -1;
}

int HashTable_LinProbe::remove(const char* data)
{
	if (not this->contains(data))
		return -1;
	// search for 'data'
	int key = m_currKey;
	const char* iter = m_table[key];
	while (strcmp(iter, data) != 0)
	{
		key = (key + 1) % m_arrsize;
		iter = m_table[key];
	}
	m_table[key] = nullptr;
	this->m_full = false;
	return key;
}

void HashTable_LinProbe::print() const
{
	std::cout << "HashTable(linear probe) at " << this << ": \n";
	for (unsigned int i = 0; i < m_arrsize; i++)
	{
		const char* data = m_table[i];
		std::cout << "[key " << i << "] : ";
		if (data != nullptr)
			std::cout << data << '\n';
		else std::cout << "(X)\n";
	}

}

void HashTable_LinProbe::clear()
{
	for (unsigned int i = 0; i < m_arrsize; i++)
	{
		if (m_table[i] != nullptr)
			delete[] m_table[i];
		m_table[i] = nullptr;
	}
	m_full = false;
}

const char* HashTable_LinProbe::operator[](int index) const
{
	return m_table[index];
}
