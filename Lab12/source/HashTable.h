#pragma once

typedef int (*hashfunc_ptr)(const char*);


class HashTable_Chain
{
private:
	hashfunc_ptr hashf;
	unsigned int m_arrsize;
	struct Node
	{
		char* data;
		Node* prev;
		Node* next;

		Node();
		Node(const char* data);
	};
	Node** m_table;
	int m_currKey;
	Node* m_currNode;
public:
	HashTable_Chain();
	HashTable_Chain(hashfunc_ptr hash, unsigned int arr_size);
	~HashTable_Chain();

	int add(const char* data);
	int contains(const char* data);
	int remove(const char* data);
	void print() const;
};

class HashTable_LinProbe
{
private:
	hashfunc_ptr hashf;
	unsigned int m_arrsize;
	const char** m_table;
	int m_currKey;
	bool m_full;
public:
	HashTable_LinProbe();
	HashTable_LinProbe(hashfunc_ptr hash, unsigned int arr_size);
	~HashTable_LinProbe();

	int add(const char* data);
	int contains(const char* data);
	int remove(const char* data);
	void print() const;
	void clear();
	const char* operator[](int index) const;
};
