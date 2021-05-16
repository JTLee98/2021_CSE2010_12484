#pragma once
struct Node;

class AVLTree
{
private:
	Node* m_root;
	int m_count;

	Node* rotateLL(Node* parent);
	Node* rotateRR(Node* parent);
	Node* rotateLR(Node* parent);
	Node* rotateRL(Node* parent);
	Node* m_insert(Node* node, int key);
	Node* m_insert(Node* node, int key, void* data);
	void m_print(Node* node) const;
public:
	AVLTree();
	~AVLTree();

	void insert(int key, void* data);
	void insert(int* keys, const int count);
	void insert(int* keys, void** data, int count);
	void** search(int key) const;
	void print() const;
}