// lnkList header (using CPP)
#pragma once

struct Node
{
	int data;
	Node* next;
};

class lnkList
{
private:
	unsigned int m_count;
	Node* m_head;
public:
	lnkList();
	~lnkList();

	Node* operator[](unsigned int pos); // getNode(pos)

	unsigned int count() const;
	Node* head() const;

	void insert(unsigned int pos, int pdata);
	void rm(unsigned int pos); // rmNode
	void show() const; // showNode
	bool isEmpty() const; // isEmpty
	Node* findNode(int pdata) const;
	int findPos(int pdata) const;
	void empty(); // makeEmpty
};