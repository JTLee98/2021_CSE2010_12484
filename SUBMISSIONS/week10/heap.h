#pragma once

class Heap
{
private:
	int* m_array;
	int m_count;
	int m_bound;
	int m_digits;
public:
	Heap(const int size);
	~Heap();

	const bool insert(int p_data);
	const bool insert(int* p_data, int count);
	const bool remove();
	void print() const;


};
