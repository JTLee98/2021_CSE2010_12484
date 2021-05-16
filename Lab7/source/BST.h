#pragma once

#define BST_ORDER_PRE  0
#define BST_ORDER_IN   1
#define BST_ORDER_POST 2


struct Node
{
	Node();
	int data;
	Node* left;
	Node* right;
};

using BSTenum = char;

class BST
{
private:
	Node* m_root;
	int m_count;

	BSTenum m_order_mode;
	int p_data;
	void m_insert(Node*& parent);
	void m_print(Node* parent) const;
public:
	BST();
	~BST();

	void insert(int data);
	void print(BSTenum order);
};