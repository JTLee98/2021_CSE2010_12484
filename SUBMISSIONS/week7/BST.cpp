#include <iostream>
#include "BST.h"
Node::Node()
	:data(0), left(nullptr), right(nullptr) {}
void BinTree::m_insert(Node*& parent)
{
	if (parent == nullptr)
	{
		Node* newNode = new Node;
		newNode->data = p_data;
		parent = newNode;
		return;
	}
	else if (parent->data > p_data)
		m_insert(parent->left);
	else if (parent->data <= p_data)
		m_insert(parent->right);
}

void BinTree::m_print(Node* parent) const
{
	if (parent == nullptr) return;
	switch (m_order_mode)
	{
	case BST_ORDER_PRE:
		std::cout << parent->data << " / ";
		m_print(parent->left);
		m_print(parent->right);
		break;
	case BST_ORDER_IN:
		m_print(parent->left);
		std::cout << parent->data << " / ";
		m_print(parent->right);
		break;
	case BST_ORDER_POST:
		m_print(parent->left);
		m_print(parent->right);
		std::cout << parent->data << " / ";
		break;
	default:
		std::cout << "order mode unspecified.\n";
		break;
	}
}

BinTree::BinTree()
	: m_root(nullptr), m_count(0), m_order_mode(0), p_data(0) {}

BinTree::~BinTree()
{
}

void BinTree::insert(int data)
{
	p_data = data;
	m_insert(m_root);
	m_count++;
}

void BinTree::print(BSTenum order)
{
	if (m_root == nullptr) return;
	m_order_mode = order;
	m_print(m_root);
	std::cout << std::endl;
}

