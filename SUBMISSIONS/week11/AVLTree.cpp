#include "AVLTree.h"
#include <iostream>
#define max(X,Y) ((X>Y) ? X : Y)

struct Node
{
	int key;
	int height;
	void* data;
	Node* left;
	Node* right;
	Node()
		:key(-1), height(0), data(nullptr),
		left(nullptr), right(nullptr) {}
	Node(int key, void* data)
		:key(key), height(0), data(data),
		left(nullptr), right(nullptr) {}
};
int height(Node* node)
{
	if (node == nullptr) return -1;
	return node->height;
}
void updateHeight(Node* node)
{
	if (node == nullptr) return;
	node->height = 1 + max(height(node->left),height(node->right));
}
int heightDiff(Node* node)
{
	return height(node->left) - height(node->right);
}

Node* AVLTree::rotateLL(Node* parent)
{
	Node* child = parent->left;
	parent->left = child->right;
	child->right = parent;
	// update height
	parent->height = max(height(parent->left), height(parent->right));
	child->height = max(height(child->left), parent->height);
	return child;
}

Node* AVLTree::rotateRR(Node* parent)
{
	Node* child = parent->right;
	parent->right = child->left;
	child->left = parent;
	// update height
	parent->height = max(height(parent->left), height(parent->right));
	child->height = max(height(child->right), parent->height);
	return child;
}

Node* AVLTree::rotateLR(Node* parent)
{
	Node* child = parent->left;
	parent->left = rotateRR(child);
	return rotateLL(parent);
}

Node* AVLTree::rotateRL(Node* parent)
{
	Node* child = parent->right;
	parent->right = rotateLL(child);
	return rotateRR(parent);
}

Node* AVLTree::m_insert(Node* node, int key)
{
	m_insert(m_root, key, nullptr);
}

Node* AVLTree::m_insert(Node* node, int key, void* data)
{
	if (node == nullptr)
	{
		node = new Node(key, data);
		return node;
	}
	if (key < node->key)
	{
		node->left = m_insert(node->left, key, data);
		if (heightDiff(node) == 2) // unbalanced
			node = (key < node->left->key) ? rotateLL(node) : rotateLR(node);
	}
	else // key >= node
	{
		node->right = m_insert(node->right, key, data);
		if (heightDiff(node)== -2) // unbalanced
			node = (key < node->left->key) ? rotateLL(node) : rotateLR(node);
	}
	updateHeight(node);
	return node;
}

void AVLTree::m_print(Node* node) const
{
	if (node == nullptr) return;
	m_print(node->left);
	std::cout << node->key << " / ";
	m_print(node->right);
}

AVLTree::AVLTree()
	:m_root(nullptr), m_count(0) {}

AVLTree::~AVLTree()
{
}

void AVLTree::insert(int key, void* data)
{
	m_count++;
	m_insert(m_root, key, data);
}

void AVLTree::insert(int* keys, const int count)
{
	void* empty[count]{};
	this->insert(keys, empty, count);
}

void AVLTree::insert(int* keys, void** data, int count)
{
	for (int i = 0; i < count; i++)
		m_insert(m_root, keys[i], data[i]);
}

void** AVLTree::search(int key) const
{
	Node* iter = m_root;
	void** results = new void*[m_count];
	int idx = 0;
	while (iter != nullptr)
	{
		if (iter->key < key)
			iter = iter->left;
		else if (iter->key == key)
		{
			results[i] = iter->data;
			i++;
			iter = iter->right;
		}
		else // iter > key
			iter = iter->right;
	}
	return results;
}

void AVLTree::print() const
{
	m_print(m_root);
}
