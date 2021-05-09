#include "heap.h"
#include <string>
#include <iostream>
#include <cmath>


Heap::Heap(const int bound)
	: m_count(0), m_bound(bound), m_digits(0)
{ 
	m_array = new int[bound]; 
}


Heap::~Heap()
{
	delete[] m_array;
}


const bool Heap::insert(int p_data)
{
	if (m_count == m_bound)
		return false;

	m_count++;
	m_array[m_count] = p_data;
	// bubble up
	int id = m_count;
	while (id != 1 and p_data > m_array[id / 2])
	{
		m_array[id] = m_array[id / 2];
		id /= 2;
	}
	m_array[id] = p_data;

	// adjust spacing
	int p_digits = (int)log10(abs(p_data));
	if (m_digits < p_digits)
		m_digits = p_digits;

	return true;
}


const bool Heap::insert(int* p_data, int p_count)
{
	if (m_count + p_count > m_bound)
		return false;
	
	for (int i = 0; i < p_count; i++)
	{
		int data = p_data[i];
		int id = m_count;
		m_count++;
		m_array[m_count] = data;
		// bubble up
		while (id != 0 and data > m_array[id / 2])
		{
			m_array[id] = m_array[id / 2];
			id /= 2;
		}
		m_array[id] = data;
		// adjust spacing
		int p_digits = (data == 0) ? 1 : log10(abs(data)) + 1;
		if (m_digits < p_digits)
			m_digits = p_digits;
	}
	
	return true;
}


const bool Heap::remove()
{
	if (m_count == 0)
		return false;
	if (m_count == 1)
	{
		m_count = 0;
		return true;
	}

	m_array[0] = m_array[m_count];
	m_count--;

	return true;
}


void Heap::print() const
{
	if (m_count == 0)
	{
		std::cout << "heap at " << m_array << " is empty.\n";
		return;
	}

	const int lines = ilogb(m_count) + 1;
	
	int i, j;
	int lv = 1, lv_inv = exp2(lines);
	for (i = 0; i < lines ; i++)
	{
		lv_inv /= 2;
		for (j = 0; j < lv && j + lv <= m_count; j++)
		{
			int data = m_array[lv + j - 1];
			int digits = (data == 0) ? 1 : log10(abs(data)) + 1;
			std::cout
				<< std::string(m_digits * lv_inv , ' ')
				<< std::string(m_digits * lv_inv - digits, '_')
				<< data
				<< std::string(m_digits * lv_inv, '_')
				<< std::string(m_digits * lv_inv, ' ');
		}
		std::cout << '\n';
		lv *= 2;
	}
}
